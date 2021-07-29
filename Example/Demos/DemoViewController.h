//
//  ContinuousViewController.h
//  VeesoDemo
//
//  Created by gabi on 17.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "ViewController.h"

@interface DemoViewController : UIViewController

- (NSString*)title;
- (NSString*)shortDescription;
- (NSString*)longDescription;
- (void)configurePlayer;
- (CGRect) playerFrameForOrientation:(UIInterfaceOrientation)orientation;

@end
