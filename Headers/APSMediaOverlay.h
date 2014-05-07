//
//  APSMediaOverlay.h
//  APSVAST
//
//  Created by Appscend on 7/22/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaTrackableObject.h"
@class APSMediaUnit;
@protocol APSMediaPlayerOverlayController;

typedef enum {
    kAPSMediaOverlayPositionFullscreen,
    kAPSMediaOverlayPositionBottomLeft,
    kAPSMediaOverlayPositionBottomRight,
    kAPSMediaOverlayPositionTopLeft,
    kAPSMediaOverlayPositionTopRight,
    kAPSMediaOverlayPositionTop,
    kAPSMediaOverlayPositionBottom,
    kAPSMediaOverlayPositionLeft,
    kAPSMediaOverlayPositionRight,
    kAPSMediaOverlayPositionUnspecified
} APSMediaOverlayPosition;

@interface APSMediaOverlay : NSObject <NSCopying, APSMediaTrackableObject> {
    NSTimeInterval _startPoint;
    NSTimeInterval _endPoint;
    BOOL _relativeStartPoint;
    BOOL _relativeEndPoint;
    BOOL _absoluteDuration;
}

@property (nonatomic) NSString *type;
@property (nonatomic) id parameters;
@property (nonatomic) APSMediaOverlayPosition position;
@property (nonatomic) UIViewController<APSMediaPlayerOverlayController> *controller;
@property (nonatomic) int zIndex;
@property (nonatomic) NSString *width, *height;
@property (nonatomic) NSString *absoluteOffsetX;
@property (nonatomic) NSString *absoluteOffsetY;
@property (nonatomic) CGFloat fadeInDuration;
@property (nonatomic) NSMutableDictionary *trackingURLs;
@property (nonatomic) NSTimeInterval repeatAfter;
@property (nonatomic) BOOL removeWhenHidden;
@property (nonatomic, weak) APSMediaUnit *parentUnit;

- (void)setStartPoint:(NSString*)startPoint;
- (void)setEndPoint:(NSString*)endPoint;

- (NSTimeInterval)startPoint;
- (NSTimeInterval)endPoint;

- (void)incrementStartAndEndPointsWithInterval:(NSTimeInterval)duration;

- (void)adjustRelativeToDuration:(NSTimeInterval)duration;

@end
