//
//  APSVASTMediaUnit.h
//  APSVAST
//
//  Created by Appscend on 7/21/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "APSMediaOverlay.h"
#import "APSMediaTrackableObject.h"

#define kAPSMediaUnitTitle @"com.appscend.mp.unit.title"
#define kAPSMediaUnitDescription @"com.appscend.mp.unit.description"
#define kAPSMediaUnitImageURL @"com.appscend.mp.unit.image"

typedef enum {
    APSMediaControlsDisplayBottom,
    APSMediaControlsDisplayTop,
    APSMediaControlsDisplayNone
} APSMediaControlsDisplay;

@interface APSMediaUnit : NSObject <NSCopying, APSMediaTrackableObject> {
    NSMutableArray *_overlays;
}

@property (nonatomic) NSURL *url;
@property (nonatomic) NSTimeInterval initialPlaybackTime;
@property (nonatomic) APSMediaControlsDisplay controlsDisplay;
@property (nonatomic) NSDictionary *controlsParameters;
@property (nonatomic) MPMovieScalingMode scalingMode;
@property (nonatomic) NSMutableDictionary *trackingURLs;
@property (nonatomic) NSMutableArray *buffet;
@property (nonatomic) BOOL pinchToFullscreen;
@property (nonatomic) BOOL shouldAutoplay;
@property (nonatomic) BOOL canReplay;
@property (nonatomic) BOOL debug;
@property (nonatomic) NSMutableDictionary *metadata;

- (APSMediaUnit*)initWithURL:(NSURL*)url;

- (void)addOverlay:(APSMediaOverlay*)overlay;
- (void)setOverlays:(NSArray*)overlays;
- (void)clearOverlays;
- (NSArray*)overlays;

@end
