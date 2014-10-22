//
//  ViewController.m
//  VeesoDemo
//
//  Created by gabi on 31.08.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "ViewController.h"
#import "ManualConfigurationViewController.h"
#import "JSONConfigurationViewController.h"
#import "DictionaryConfigurationViewController.h"
#import "MRAIDShowcaseViewController.h"
#import "ContinuousViewController.h"
#import "APSMediaPlayer.h"

@interface ViewController () {
    NSArray *_model;
}

@end

@implementation ViewController

static NSString *CellIdentifier = @"Cell";

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.navigationController setNavigationBarHidden:YES];
    
    _model = [self demos];
    
	UIImage * backgroundImage;
    
    self.tableView.contentInset = UIEdgeInsetsMake(0, -10, 0, 0);
    
    if ([[UIScreen mainScreen] bounds].size.height == 568) {
        backgroundImage = [UIImage imageNamed:@"5bg_2x"];
    }
    else {
        backgroundImage = [UIImage imageNamed:@"bg"];
    }
    
    self.demosButton.layer.cornerRadius = 10;
    self.demosButton.layer.masksToBounds = YES;
    self.sdkButton.layer.cornerRadius = 10;
    self.sdkButton.layer.masksToBounds = YES;
    self.infoButton.layer.cornerRadius = 10;
    self.infoButton.layer.masksToBounds = YES;
    [self.demosButton addTarget:self action:@selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.sdkButton addTarget:self action:@selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.infoButton addTarget:self action:@selector(buttonPressed:) forControlEvents:UIControlEventTouchUpInside];
    
    [self highlightButton:self.demosButton];
    
    UIImageView *backgroundImageView = [[UIImageView alloc] initWithImage:backgroundImage];
    [self.view insertSubview:backgroundImageView atIndex:0];
}

- (void)viewDidLayoutSubviews {
    self.scrollView.contentSize = CGSizeMake(840, 268);
}

- (void)viewWillAppear:(BOOL)animated {
    [self.navigationController setNavigationBarHidden:YES];
}

- (void)buttonPressed:(id)sender {
    UIButton *button = (UIButton*)sender;

    if (button == self.demosButton)
        [self.scrollView setContentOffset:CGPointMake(0, 0) animated:YES];
    else if (button == self.sdkButton)
        [self.scrollView setContentOffset:CGPointMake(280, 0) animated:YES];
    else
        [self.scrollView setContentOffset:CGPointMake(560, 0) animated:YES];
}

- (void)highlightButton:(UIButton*)button {
    [UIView animateWithDuration:.2 animations:^() {
        self.demosButton.backgroundColor = self.sdkButton.backgroundColor = self.infoButton.backgroundColor = [UIColor clearColor];
        button.backgroundColor = [UIColor colorWithWhite:1 alpha:.3];
    }];
}

- (BOOL)shouldAutorotate {
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
    return UIStatusBarStyleLightContent;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _model.count;
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
    }
    
    cell.textLabel.textColor = [UIColor whiteColor];
    cell.detailTextLabel.textColor = [UIColor whiteColor];
    cell.backgroundColor = [UIColor clearColor];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    if (indexPath.row < _model.count) {
        NSDictionary *demo = _model[indexPath.row];
        
        cell.textLabel.text = demo[@"title"];
        cell.detailTextLabel.text = demo[@"subtitle"];
        cell.imageView.image = demo[@"image"];
        cell.imageView.layer.cornerRadius = 27;
        cell.imageView.layer.masksToBounds = YES;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath {
    cell.imageView.frame = CGRectMake(0, 0, 100, 100);
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 55;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row < _model.count) {
        NSDictionary *demo = _model[indexPath.row];
        if (demo[@"pushTo"]) {
            [self.navigationController pushViewController:[[(Class)demo[@"pushTo"] alloc] init] animated:YES];
        }
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (scrollView.contentOffset.x == 0)
        [self highlightButton:self.demosButton];
    else if (scrollView.contentOffset.x == 280)
        [self highlightButton:self.sdkButton];
    else if (scrollView.contentOffset.x == 560)
        [self highlightButton:self.infoButton];
}

- (NSArray*)demos {
    return  @[
              @{
                  @"title": @"Demo 1",
                  @"subtitle": @"preroll, banner ad",
                  @"image": [UIImage imageNamed:@"i_1.jpg"],
                  @"pushTo": [ManualConfigurationViewController class]
                  },
              @{
                  @"title": @"Demo 2",
                  @"subtitle": @"two prerolls, banner ad",
                  @"image": [UIImage imageNamed:@"i_2.jpg"],
                  @"pushTo": [JSONConfigurationViewController class]
                  },
              @{
                  @"title": @"Demo 3",
                  @"subtitle": @"midroll in livestream",
                  @"image": [UIImage imageNamed:@"i_3.jpg"],
                  @"pushTo": [DictionaryConfigurationViewController class]
                  },
              @{
                  @"title": @"Demo 4",
                  @"subtitle": @"MRAID expandable banner",
                  @"image": [UIImage imageNamed:@"i_4.jpg"],
                  @"pushTo": [MRAIDShowcaseViewController class]
                  },
              @{
                  @"title": @"Demo 5",
                  @"subtitle": @"Postroll, continuous play",
                  @"image": [UIImage imageNamed:@"i_5.jpg"],
                  @"pushTo": [ContinuousViewController class]
                  },
              ];
}

- (IBAction)getSDK:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://panel.veeso.co/"]];
}

@end
