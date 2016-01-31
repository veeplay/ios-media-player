//
//  FullscreenTransitioner.m
//  VeesoDemo
//
//  Created by Ovidiu on 04/06/15.
//  Copyright (c) 2015 Veeso. All rights reserved.
//

#import "FullscreenTransitioner.h"
#import "FullscreenPresentationController.h"

@implementation FullscreenTransitioner

- (id) init:(BOOL)isPresenting {
    self = [super init];
    if (self) {
        _presenting = isPresenting;
    }
    return self;
}

- (NSTimeInterval) transitionDuration:(id<UIViewControllerContextTransitioning>)transitionContext {
    return 1.5;
}

- (void) animateTransition:(id<UIViewControllerContextTransitioning>)transitionContext {
    UIViewController *fromVC = [transitionContext viewControllerForKey:UITransitionContextFromViewControllerKey];
    UIView *fromView = [fromVC view];
    UIViewController *toVC   = [transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
    UIView *toView = [toVC view];
    
    UIView *containerView = [transitionContext containerView];
    
    BOOL isPresentation = [self presenting];
    
    if (isPresentation) {
        [containerView addSubview:toView];
    }
    
    UIViewController *animatingVC = isPresentation? toVC : fromVC;
    UIView *animatingView = [animatingVC view];
    
    CGRect appearedFrame = [transitionContext finalFrameForViewController:animatingVC];
    // Our dismissed frame is the same as our appeared frame, but off the right edge of the container
    CGRect dismissedFrame = appearedFrame;
    dismissedFrame.origin.x += dismissedFrame.size.width;
    
    CGRect initialFrame = isPresentation ? fromVC.view.frame : appearedFrame;
    CGRect finalFrame = isPresentation ? appearedFrame : dismissedFrame;
    
    [animatingView setFrame:initialFrame];
    
    NSLog(@"[self transitionDuration:transitionContext]: %f", [self transitionDuration:transitionContext]);
    
    // Animate using the duration from -transitionDuration:
    [UIView animateWithDuration:[self transitionDuration:transitionContext]
                          delay:0
         usingSpringWithDamping:300.0
          initialSpringVelocity:5.0
                        options:UIViewAnimationOptionAllowUserInteraction | UIViewAnimationOptionBeginFromCurrentState
                     animations:^{
                         [animatingView setFrame:finalFrame];
                     }
                     completion:^(BOOL finished){
                         // If we're dismissing, remove the presented view from the hierarchy
                         if(![self presenting])
                         {
                             [fromView removeFromSuperview];
                         }
                         // We need to notify the view controller system that the transition has finished
                         [transitionContext completeTransition:YES];
                     }];
}

@end
