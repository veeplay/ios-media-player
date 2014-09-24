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

@interface ManualConfigurationViewController ()

@end

@implementation ManualConfigurationViewController

- (NSString*)title {
    return @"Demo 1";
}

- (NSString*)shortDescription {
    return @"Preroll, banner ad 15 seconds in";
}

- (NSString*)longDescription {
    return @"Programmatic configuration\nH.264 progressive playback\nAds retrieved via VAST";
}

- (void)configurePlayer {
    APSVASTMediaBuilderPlugin *vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init];
    [builder addPlugin:vastPlugin];
    
    // Create the pre-roll ad break
    APSVASTAdBreak *preroll = [[APSVASTAdBreak alloc] init];
    preroll.type = APSVASTPreContent;
    preroll.sources = @[@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/vast/vast_twitter.xml"];
    preroll.debug = YES;
    
    // Create the banner ad
    APSVASTAdBreak *banner = [[APSVASTAdBreak alloc] init];
    banner.type = APSVASTNonLinear;
    banner.adOffset = @"15";
    banner.sources = @[@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/vast/vast_nonlinear.xml"];
    banner.debug = YES;
    
    // Move the close button to the left, and configure some colors
    banner.bannerConfiguration.closeButtonOffset = CGPointMake(-275, -5);
    banner.bannerConfiguration.closeButtonProgressColor = @"ffffff";
    banner.bannerConfiguration.closeButtonXColor = @"ffffff";
    
    vastPlugin.adBreaks = @[preroll, banner];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[NSURL URLWithString:@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/movies/assassins.mp4"]];
    builder.contentUnits = @[unit];
    
    // Render the playlist
    [APSMediaPlayer sharedInstance].modalViewControllerRoot = self;
    [[APSMediaPlayer sharedInstance] playMediaUnits:[builder mediaUnits]];
}

@end
