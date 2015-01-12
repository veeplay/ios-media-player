//
//  ContinuousViewController.m
//  VeesoDemo
//
//  Created by gabi on 17.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "ContinuousViewController.h"
#import "APSMediaPlayer.h"
#import "APSVASTMediaBuilderPlugin.h"

@interface ContinuousViewController () {
    APSVASTMediaBuilderPlugin *_vastPlugin;
    APSMediaBuilder *_builder;
}
@end

@implementation ContinuousViewController

- (NSString*)title {
    return @"Demo 5";
}

- (NSString*)shortDescription {
    return @"Postroll, continuous playback";
}

- (NSString*)longDescription {
    return @"H.264 progressive playback\nAds retrieved via VAST\nInfinite playlist";
}

- (void)configurePlayer {
    _vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    _builder = [[APSMediaBuilder alloc] init];
    [_builder addPlugin:_vastPlugin];
    
    [APSMediaPlayer sharedInstance].onFinish = ^() {
        [self advancePlaylist];
    };
    
    [self advancePlaylist];
}

- (void)advancePlaylist {
    // Create the post-roll ad break
    APSVASTAdBreak *postroll = [[APSVASTAdBreak alloc] init];
    postroll.type = APSVASTPostContent;
    postroll.sources = @[@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/vast/vast_multiple_ads.xml"];
    
    _vastPlugin.adBreaks = @[postroll];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[NSURL URLWithString:[NSString stringWithFormat:@"https://s3-eu-west-1.amazonaws.com/demo-app.assets.appscend.com/movies/soa%d.mp4", (arc4random_uniform(5) + 1)]]];
    _builder.contentUnits = @[unit];
    
    // Render the playlist
    [[APSMediaPlayer sharedInstance] playMediaUnits:[_builder mediaUnits]];
}

@end
