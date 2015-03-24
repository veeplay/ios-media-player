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
    NSArray *_urls;
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
    if (!_urls) {
        _urls = @[[NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/2221b031-6ba6-48e6-b674-c3e5194bf1da/soa1-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"],
                  [NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/d888017e-be2f-495f-9a09-c32e8a9a1886/soa2-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"],
                  [NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/cb3c20cf-65d0-43ae-a1ca-063ac62ad89d/soa3-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"],
                  [NSURL URLWithString:@"http://veeplaydemo.streaming.mediaservices.windows.net/1244d4f6-57f1-44c3-9d47-b9f07275b337/soa5-m3u8-aapl.ism/Manifest(format=m3u8-aapl)"]];
    }
    
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
    postroll.sources = @[@"http://az739004.vo.msecnd.net/vast/vast_multiple_ads.xml"];
    
    _vastPlugin.adBreaks = @[postroll];
    
    // Create the main content unit
    APSMediaUnit *unit = [[APSMediaUnit alloc] initWithURL:[_urls objectAtIndex:arc4random_uniform([_urls count])]];
    NSLog(@"unit url: %@", unit.url.absoluteString);
    _builder.contentUnits = @[unit];
    
    // Render the playlist
    [[APSMediaPlayer sharedInstance] playMediaUnits:[_builder mediaUnits]];
}

@end
