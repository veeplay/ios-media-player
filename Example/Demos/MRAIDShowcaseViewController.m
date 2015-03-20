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
    
    // Create the MRAID banner ad
    APSVASTAdBreak *banner = [[APSVASTAdBreak alloc] init];
    banner.type = APSVASTNonLinear;
    banner.adOffset = @"15";
    banner.sources = @[@"http://az739004.vo.msecnd.net/vast/vast_nonlinear_mraid.xml"];
    banner.bannerConfiguration.showCloseButton = NO;
    
    vastPlugin.adBreaks = @[banner];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/67c1472f-6517-49b5-bda8-0b228bb19d67/deusex-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"]];
    builder.contentUnits = @[unit];
    
    // Render the playlist
    [APSMediaPlayer sharedInstance].modalViewControllerRoot = self;
    [[APSMediaPlayer sharedInstance] playMediaUnits:[builder mediaUnits]];
}

@end
