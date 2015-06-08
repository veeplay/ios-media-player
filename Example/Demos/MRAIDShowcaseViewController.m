//
//  MRAIDShowcaseViewController.m
//  VeesoDemo
//
//  Created by gabi on 15.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "MRAIDShowcaseViewController.h"
#import "APSMediaPlayer.h"
#import "APSVASTMediaBuilderPlugin.h"

@implementation MRAIDShowcaseViewController

- (NSString*)title {
    return @"Demo 4";
}

- (NSString*)shortDescription {
    return @"MRAID expandable banner 15 seconds in";
}

- (NSString*)longDescription {
    return @"Ad retrieved via VAST\nMRAID framework used\nExpandable ad\nNative links";
}

- (void)configurePlayer {
    APSVASTMediaBuilderPlugin *vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init];
    [builder addPlugin:vastPlugin];
    
    // Enable internal fullscreen handling
    [[APSMediaPlayer sharedInstance] setInternalFullscreenSupport:YES];
    
    // Create the MRAID banner ad
    APSVASTAdBreak *banner = [[APSVASTAdBreak alloc] init];
    banner.type = APSVASTNonLinear;
    banner.adOffset = @"15";
    banner.sources = @[@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/vast/vast_nonlinear_mraid.xml"];
    banner.bannerConfiguration.showCloseButton = NO;
    
    vastPlugin.adBreaks = @[banner];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[NSURL URLWithString:@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/movies/deusex.mp4"]];
    builder.contentUnits = @[unit];
    
    // Render the playlist
    [APSMediaPlayer sharedInstance].modalViewControllerRoot = self;
    [[APSMediaPlayer sharedInstance] playMediaUnits:[builder mediaUnits]];
}

@end
