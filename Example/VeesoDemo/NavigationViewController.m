//
//  NavigationViewController.m
//  VeesoDemo
//
//  Created by gabi on 17.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "NavigationViewController.h"
#import "APSMediaPlayer.h"
#import "ViewController.h"

@interface NavigationViewController ()

@end

@implementation NavigationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (NSUInteger)supportedInterfaceOrientations {
    return [self.topViewController supportedInterfaceOrientations];
}

- (BOOL)shouldAutorotate {
    return YES;
}

@end
