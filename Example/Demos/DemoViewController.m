//
//  ContinuousViewController.m
//  VeesoDemo
//
//  Created by gabi on 17.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "DemoViewController.h"
#import "APSMediaPlayer.h"

@interface DemoViewController () {
    BOOL _isWidescreenDevice;
}

@end

@implementation DemoViewController

- (NSString*)title {
    return nil;
}

- (NSString*)shortDescription {
    return nil;
}

- (NSString*)longDescription {
    return nil;
}

- (void)configurePlayer {
    
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    UIScreen *screen = [UIScreen mainScreen];
    float ratio = screen.bounds.size.width / screen.bounds.size.height;
    if (ratio == 320.0f/568.0f || ratio == 568.0f/320.0f)
        _isWidescreenDevice = YES;
    
    self.navigationItem.title = [self title];
    
    UILabel *textLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 75, 300, 40)];
    textLabel.text = [self shortDescription];
    textLabel.textColor = [UIColor whiteColor];
    textLabel.font = [UIFont fontWithName:@"HelveticaNeue" size:15];
    [self.view addSubview:textLabel];
    
    if (_isWidescreenDevice) {
        UILabel *subtextLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 410, 300, 130)];
        subtextLabel.text = [self longDescription];
        subtextLabel.textColor = [UIColor whiteColor];
        subtextLabel.font = [UIFont fontWithName:@"HelveticaNeue-Light" size:14];
        subtextLabel.numberOfLines = 0;
        [self.view addSubview:subtextLabel];
        [subtextLabel sizeToFit];
    }
    
    [APSMediaPlayer sharedInstance].view.autoresizingMask = UIViewAutoresizingNone;
    [APSMediaPlayer sharedInstance].view.frame = CGRectMake(10, 110, 300, 280);
    [APSMediaPlayer sharedInstance].modalViewControllerRoot = self;
    [self.view addSubview:[APSMediaPlayer sharedInstance].view];
    
    [self configurePlayer];
}

- (void)viewWillAppear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:NO];
}

- (void)viewWillDisappear:(BOOL)animated {
    [[APSMediaPlayer sharedInstance] pause];
    [self.navigationController setNavigationBarHidden:YES];
}

- (NSUInteger)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskAll;
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration {
    
    if (UIInterfaceOrientationIsPortrait(toInterfaceOrientation))
        [APSMediaPlayer sharedInstance].frame = CGRectMake(10, 110, 300, 280);
    else
        [APSMediaPlayer sharedInstance].frame = CGRectMake(10, 110, _isWidescreenDevice?548:460, 200);
}

@end
