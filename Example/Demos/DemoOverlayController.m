//
//  DemoOverlayController.m
//  VeesoDemo
//
//  Created by gabi on 08.09.2015.
//  Copyright (c) 2015 Veeso. All rights reserved.
//

#import "DemoOverlayController.h"
#import "APSMediaOverlay.h"

@interface DemoOverlayController ()

@end

@implementation DemoOverlayController

NSString* const DemoOverlay = @"demo.overlay";

- (NSString*)type {
    return DemoOverlay;
}

- (void)load {
    UIView *color = [[UIView alloc] initWithFrame:self.view.frame];
    color.backgroundColor = self.overlay.parameters[@"color"]?self.overlay.parameters[@"color"]:[UIColor redColor];
    [self.view addSubview:color];
    
    [UIView animateWithDuration:1
                          delay:0
                        options:UIViewAnimationOptionRepeat
                     animations:^{
                         color.alpha = 0;
                     }
                     completion:nil];
}

@end
