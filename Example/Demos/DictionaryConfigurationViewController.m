//
//  DictionaryConfigurationViewController.m
//  VeesoDemo
//
//  Created by gabi on 03.09.2014.
//  Copyright (c) 2014 Veeso. All rights reserved.
//

#import "DictionaryConfigurationViewController.h"
#import "APSMediaPlayer.h"
#import "APSVASTMediaBuilderPlugin.h"

@implementation DictionaryConfigurationViewController

- (NSString*)title {
    return @"Demo 3";
}

- (NSString*)shortDescription {
    return @"Livestream, midroll 15 seconds in";
}

- (NSString*)longDescription {
    return @"Configured via NSDictionary\nHLS playback\nAds retrieved via VMAP";
}

- (void)configurePlayer {
    APSVASTMediaBuilderPlugin *vastPlugin = [[APSVASTMediaBuilderPlugin alloc] init];
    vastPlugin.adBreakTemplate.skipButtonConfiguration.defaultSkipOffset = 5;
    vastPlugin.adBreakTemplate.bannerConfiguration.closeButtonOffset = CGPointMake(-275, -5);
    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init];
    [builder addPlugin:vastPlugin];
    
    [builder configureFromDictionary:[self configurationDictionary]];
    [builder requestMediaUnitsWithCompletionBlock:^(NSArray *units) {
        [[APSMediaPlayer sharedInstance] playMediaUnits:units];
    }];
}

- (NSDictionary*)configurationDictionary {
    return @{
            @"ads": @{
                    @"debug":@(YES),
                    @"vmap":@"http://az739004.vo.msecnd.net/vmap/vmap.xml",
                    @"countdown": @{
                        @"text": @"Content will resume in __remaining__s"
                    }
                    },
            @"content": @[
                    @{
                        @"url": @"http://www.nasa.gov/multimedia/nasatv/NTV-Public-IPS.m3u8",
                        @"controls": @{
                            @"components" : @[@"playback", @"totalTime", @"currentTime", @"fullscreen"],
                            @"barColor": @"ff0000",
                            @"barAlpha": @(0.5)
                            }
                        }
                    ]
            };
}

@end
