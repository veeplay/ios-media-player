//
//  ViewController.h
//  VeesoDemo
//
//  Created by gabi on 31.08.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIScrollViewDelegate>

@property IBOutlet UITableView *tableView;
@property IBOutlet UIScrollView *scrollView;
@property IBOutlet UIButton *demosButton;
@property IBOutlet UIButton *sdkButton;
@property IBOutlet UIButton *infoButton;

- (IBAction)getSDK:(id)sender;

@end
