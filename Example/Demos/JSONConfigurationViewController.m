//
//  JSONConfigurationViewController.m
//  VeesoDemo
//
//  Created by gabi on 03.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "JSONConfigurationViewController.h"
#import "APSMediaPlayer.h"
#import "APSVASTMediaBuilderPlugin.h"

@interface JSONConfigurationViewController ()

@end

@implementation JSONConfigurationViewController

- (NSString*)title {
    return @"Demo 2";
}

- (NSString*)shortDescription {
    return @"2 Prerolls, banner ad 20 seconds in";
}

- (NSString*)longDescription {
    return @"Remotely configured via JSON\nH.264 progressive playback\nAds retrieved via VAST";
}

- (void)configurePlayer {
    // Create the media builder, register the VAST plugin and set some defaults
    APSVASTMediaBuilderPlugin *vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    vastPlugin.adBreakTemplate.skipButtonConfiguration.defaultSkipOffset = 5;
    vastPlugin.adBreakTemplate.bannerConfiguration.closeButtonOffset = CGPointMake(-275, -5);
    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init];
    [builder addPlugin:vastPlugin];
    
    // Configure the builder from a remote JSON configuration file and render the resulting media units
    [builder configureFromURL:[NSURL URLWithString:@"http://appscend.mobi/redStars//Phone_Item/mediaPlayerConfig?platform=1&vid=2272102"] onComplete:^() {
        [[APSMediaPlayer sharedInstance] playMediaUnits:[builder mediaUnits]];
    }];
}

@end
