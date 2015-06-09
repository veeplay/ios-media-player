//
//  FullscreenPresentationController.m
//  VeesoDemo
//
//  Created by Ovidiu on 04/06/15.
//  Copyright (c) 2015 Veeso. All rights reserved.
//

#import "FullscreenPresentationController.h"

@implementation FullscreenPresentationController

- (id) initWithPresentedViewController:(UIViewController *)presentedViewController presentingViewController:(UIViewController *)presentingViewController {
    self = [super initWithPresentedViewController:presentedViewController presentingViewController:presentedViewController];
    if (self) {
        _dimmingView = [[UIView alloc] init];
        [_dimmingView setBackgroundColor:[UIColor blackColor]];
        [_dimmingView setAlpha:0.0];
    }
    return self;
}

- (void)presentationTransitionWillBegin {
    [[self dimmingView] setFrame:[self.containerView bounds]];
    [[self dimmingView] setAlpha:0.0];
    
    [self.containerView insertSubview:[self dimmingView] atIndex:0];
    
    if ([self.presentedViewController transitionCoordinator]) {
        [[self.presentedViewController transitionCoordinator] animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext> context) {
            [[self dimmingView] setAlpha:1.0];
        } completion:nil];
    } else {
        [[self dimmingView] setAlpha:1.0];
    }
}

- (void)dismissalTransitionWillBegin {
    if([[self presentedViewController] transitionCoordinator]) {
        [[[self presentedViewController] transitionCoordinator] animateAlongsideTransition:^(id<UIViewControllerTransitionCoordinatorContext> context) {
            [[self dimmingView] setAlpha:0.0];
        } completion:nil];
    } else {
        [[self dimmingView] setAlpha:0.0];
    }
}

- (UIModalPresentationStyle)adaptivePresentationStyle {
    return UIModalPresentationOverFullScreen;
}

- (CGSize)sizeForChildContentContainer:(id <UIContentContainer>)container withParentContainerSize:(CGSize)parentSize {
    return parentSize;
}

- (void)containerViewWillLayoutSubviews {
    [[self dimmingView] setFrame:[[self containerView] bounds]];
    [[self presentedView] setFrame:[self frameOfPresentedViewInContainerView]];
}

- (BOOL)shouldPresentInFullscreen {
    return YES;
}

- (CGRect)frameOfPresentedViewInContainerView {
    return CGRectMake(0, 0, self.containerView.bounds.size.width, self.containerView.bounds.size.height);
}

@end
