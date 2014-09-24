//
//  AppDelegate.m
//  VeesoDemo
//
//  Created by gabi on 31.08.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import "NavigationViewController.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Main_iPhone" bundle:nil];
    UIViewController *vc = [sb instantiateViewControllerWithIdentifier:@"main"];
    NavigationViewController *navigationController = [[NavigationViewController alloc] initWithRootViewController:vc];
    self.window.rootViewController = navigationController;
    return YES;
}

@end
