//
//  ManualConfigurationViewController.m
//  VeesoDemo
//
//  Created by gabi on 01.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "ManualConfigurationViewController.h"
#import "APSMediaPlayer.h"
#import "APSVASTMediaBuilderPlugin.h"
#import "FullscreenTransitioner.h"
#import "FullscreenPresentationController.h"
#import "DemoOverlayController.h"

@interface ManualConfigurationViewController ()

@end

@implementation ManualConfigurationViewController {
    UIViewController *_fullscreenVC;
    BOOL _isPresenting;
    UIViewAutoresizing _initialAutosizingMask;
}

- (NSString*)title {
    return @"Demo 1";
}

- (NSString*)shortDescription {
    return @"Preroll, banner ad 15 seconds in";
}

- (NSString*)longDescription {
    return @"Programmatic configuration\nH.264 progressive playback\nAds retrieved via VAST";
}

- (void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // Observing APSMediaPlayerToggleFullscreenNotification to manage fullscreen changes
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(manageFullscreen) name:APSMediaPlayerToggleFullscreenNotification object:nil];
    
    // Observing APSMediaPlayerWillOpenMiniBrowser so we can dismiss the fullscreen view controller to make place for the web browser view controller
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(willOpenAd) name:APSMediaPlayerWillOpenMiniBrowser object:nil];
}

- (void) viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)configurePlayer {
    APSVASTMediaBuilderPlugin *vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init];
    [builder addPlugin:vastPlugin];
    
    // Create the pre-roll ad break
    APSVASTAdBreak *preroll = [[APSVASTAdBreak alloc] init];
    preroll.type = APSVASTPreContent;
    preroll.sources = @[@"http://az739004.vo.msecnd.net/vast/vast_twitter.xml"];
    preroll.debug = YES;
    
    // Create the banner ad
    APSVASTAdBreak *banner = [[APSVASTAdBreak alloc] init];
    banner.type = APSVASTNonLinear;
    banner.adOffset = @"15";
    banner.sources = @[@"http://az739004.vo.msecnd.net/vast/vast_nonlinear.xml"];
    banner.debug = YES;
    
    // Move the close button to the left, and configure some colors
    banner.bannerConfiguration.closeButtonOffset = CGPointMake(-275, -5);
    banner.bannerConfiguration.closeButtonProgressColor = @"ffffff";
    banner.bannerConfiguration.closeButtonXColor = @"ffffff";
    
    vastPlugin.adBreaks = @[preroll, banner];
    
    [[APSMediaPlayer sharedInstance] registerOverlayController:[DemoOverlayController class]];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/ca4d815a-9f06-4ea8-9eeb-00e87b92d812/assassins-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"]];
    APSMediaOverlay *overlay = [[APSMediaOverlay alloc] init];
    overlay.type = DemoOverlay;
    overlay.position = kAPSMediaOverlayPositionFullscreen;
    overlay.startPoint = @"0";
    overlay.endPoint = @"10";
    overlay.parameters[@"color"] = [UIColor greenColor];
    unit.overlays = @[overlay];
    
    builder.contentUnits = @[unit];
    
    // Render the playlist
    [APSMediaPlayer sharedInstance].modalViewControllerRoot = self;
    [[APSMediaPlayer sharedInstance] playMediaUnits:@[unit]];
    
    // Disable internal fullscreen handling
    [[APSMediaPlayer sharedInstance] setInternalFullscreenSupport:NO];
    [[APSMediaPlayer sharedInstance] setFullscreenOnLandscapeRotate:NO];
}

- (void) manageFullscreen {
    _isPresenting = ![[APSMediaPlayer sharedInstance] isFullscreen];
    
    if (!_fullscreenVC) {
        // _fullscreenVC is the new view controller where the player's view will be placed in fullscreen
        _fullscreenVC = [[UIViewController alloc] init];
        [_fullscreenVC setTransitioningDelegate:self];
    }
    
    // Without UIModalPresentationCustom _fullscreenVC will not use our UIPresentationController class
    _fullscreenVC.modalPresentationStyle = UIModalPresentationCustom;
    
    if (_isPresenting)
        [self presentViewController:_fullscreenVC animated:YES completion:nil];
    else
        [_fullscreenVC dismissViewControllerAnimated:YES completion:^{
            // We no longer need _fullscreenVC after we exit from fullscreen
            _fullscreenVC = nil;
        }];
}

- (void) willOpenAd {
    if ([[APSMediaPlayer sharedInstance] isFullscreen]) {
        [_fullscreenVC dismissViewControllerAnimated:NO completion:^{
            [[[APSMediaPlayer sharedInstance] view] removeFromSuperview];
            [[[APSMediaPlayer sharedInstance] view] setAutoresizingMask:_initialAutosizingMask];
            [self.view addSubview:[[APSMediaPlayer sharedInstance] view]];
            [[[APSMediaPlayer sharedInstance] view] setFrame:[self playerFrameForOrientation:[[UIApplication sharedApplication] statusBarOrientation]]];
        }];
    }
}

#pragma mark UIViewControllerTransitioningDelegate methods

- (UIPresentationController *) presentationControllerForPresentedViewController:(UIViewController *)presented presentingViewController:(UIViewController *)presenting sourceViewController:(UIViewController *)source {
    return [[FullscreenPresentationController alloc] initWithPresentedViewController:presented presentingViewController:presenting];
}

- (id <UIViewControllerAnimatedTransitioning>) animationControllerForPresentedController:(UIViewController *)presented presentingController:(UIViewController *)presenting sourceController:(UIViewController *)source {
    return self;
}

- (id <UIViewControllerAnimatedTransitioning>) animationControllerForDismissedController:(UIViewController *)dismissed {
    return self;
}

#pragma mark UIViewControllerAnimatedTransitioning methods

- (NSTimeInterval) transitionDuration:(id<UIViewControllerContextTransitioning>)transitionContext {
    return 0.5;
}

- (void) animateTransition:(id<UIViewControllerContextTransitioning>)transitionContext {
    UIViewController *fromVC = [transitionContext viewControllerForKey:UITransitionContextFromViewControllerKey];
    UIView *fromView = [fromVC view];
    UIViewController *toVC   = [transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
    UIView *toView = [toVC view];
    UIView *containerView = [transitionContext containerView];
    
    if (_isPresenting) {
        // Store the current autoresizingMask so we can restore it later
        _initialAutosizingMask = [[[APSMediaPlayer sharedInstance] view] autoresizingMask];
        
        // ContainerView is the view where the transition animation will be placed
        [containerView addSubview:toView];
        
        // We're removing now the APSMediaPlayer's view from the current superview and we're moving it to the fullscreen view controller
        [[[APSMediaPlayer sharedInstance] view] removeFromSuperview];
        [toView addSubview:[[APSMediaPlayer sharedInstance] view]];
        
        // Set new autoresizing mask to we make sure that the APSMediaPlayer's view will fill the fullscreen view controller's view
        [[[APSMediaPlayer sharedInstance] view] setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    }
    
    UIViewController *animatingVC = _isPresenting ? toVC : fromVC;
    UIView *animatingView = [animatingVC view];
    
    // If UIPresentationController is not supported (iOS 7) we manually set the appeared frame
    CGRect appearedFrame = [UIPresentationController class] ? [transitionContext finalFrameForViewController:animatingVC] : UIInterfaceOrientationIsPortrait([[UIApplication sharedApplication] statusBarOrientation]) ? self.view.window.bounds : CGRectMake(0.0, 0.0, self.view.window.bounds.size.width, self.view.window.bounds.size.height);
    
    CGRect initialFrame = _isPresenting ? fromVC.view.frame : appearedFrame;
    CGRect finalFrame = _isPresenting ? appearedFrame : fromVC.view.frame;
    
    [animatingView setFrame:initialFrame];
    
    // Animate using the duration from -transitionDuration:
    [UIView animateWithDuration:[self transitionDuration:transitionContext]
                          delay:0
         usingSpringWithDamping:300.0
          initialSpringVelocity:5.0
                        options:UIViewAnimationOptionAllowUserInteraction | UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         [animatingView setFrame:finalFrame];
                         
                         if (_isPresenting) {
                             // Frame coordinates are a mess on landscape orientation in iOS 7
                             if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
                                 [[APSMediaPlayer sharedInstance] setFrame:finalFrame];
                             else
                                 UIInterfaceOrientationIsPortrait([[UIApplication sharedApplication] statusBarOrientation]) ? [[APSMediaPlayer sharedInstance] setFrame:finalFrame] : [[APSMediaPlayer sharedInstance] setFrame:CGRectMake(0.0, 0.0, finalFrame.size.height, finalFrame.size.width)];
                         } else {
                             [[APSMediaPlayer sharedInstance] setFrame:[self playerFrameForOrientation:[[UIApplication sharedApplication] statusBarOrientation]]];
                         }
                     }
                     completion:^(BOOL finished){
                         
                         if(!_isPresenting) {
                             // Obviously you want to move the APSMediaPlayer's view back after the unfullscreen animation is over
                             [fromView removeFromSuperview];
                             [[[APSMediaPlayer sharedInstance] view] removeFromSuperview];
                             [[[APSMediaPlayer sharedInstance] view] setAutoresizingMask:_initialAutosizingMask];
                             [self.view addSubview:[[APSMediaPlayer sharedInstance] view]];
                         }
                         
                         // We need to notify the view controller system that the transition has finished
                         [transitionContext completeTransition:YES];
                     }];
}

@end
