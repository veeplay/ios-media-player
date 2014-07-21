//
//  APSMediaOverlay.h
//  APSVAST
//
//  Created by Appscend on 7/22/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaTrackableObject.h"

#import "APSMediaPlayerControlsOverlayController.h"
#import "APSMediaPlayerButtonOverlayController.h"
#import "APSMediaPlayerTextOverlayController.h"
#import "APSMediaPlayerImageOverlayController.h"
#import "APSMediaPlayerHTMLOverlayController.h"
#import "APSMediaPlayerMidrollOverlayController.h"
#import "APSMediaPlayerYoutubeOverlayController.h"
#import "APSMediaPlayerVimeoOverlayController.h"

@class APSMediaUnit;
@protocol APSMediaPlayerOverlayController;

#ifndef kAPSMetadataTitle
#define kAPSMetadataTitle @"aps_meta_title"
#define kAPSMetadataDescription @"aps_meta_description"
#define kAPSMetadataImageURL @"aps_meta_image"
#define kAPSMetadataType @"aps_meta_type"
#endif

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

/**
 *  Describes the position the overlay should take when placed on-screen by the player.
 */
typedef NS_ENUM(NSInteger, APSMediaOverlayPosition) {
    /**
     *  The overlay should be stretched to fit the whole player surface.
     */
    kAPSMediaOverlayPositionFullscreen,
    /**
     *  The overlay should be bottom-left aligned with the player surface.
     */
    kAPSMediaOverlayPositionBottomLeft,
    /**
     *  The overlay should be bottom-right aligned with the player surface.
     */
    kAPSMediaOverlayPositionBottomRight,
    /**
     *  The overlay should be top-left aligned with the player surface.
     */
    kAPSMediaOverlayPositionTopLeft,
    /**
     *  The overlay should be top-right aligned with the player surface.
     */
    kAPSMediaOverlayPositionTopRight,
    /**
     *  The overlay should be placed centrally in the top of the player surface.
     */
    kAPSMediaOverlayPositionTop,
    /**
     *  The overlay should be placed centrally at the bottom of the player surface.
     */
    kAPSMediaOverlayPositionBottom,
    /**
     *  The overlay should be vertically centered to the left of the player surface.
     */
    kAPSMediaOverlayPositionLeft,
    /**
     *  The overlay should be vertically centered to the right of the player surface.
     */
    kAPSMediaOverlayPositionRight,
    /**
     *  The overlay will not be placed on screen.
     */
    kAPSMediaOverlayPositionUnspecified
};

extern NSString *const APSContentOverlay;

/**
 *  `APSMediaOverlay` describes any overlay that the `APSMediaPlayer` instance needs to render during playback.
 */
@interface APSMediaOverlay : NSObject <NSCopying, APSMediaTrackableObject>

/**-----------------------------------------------------------------------------
 * @name Setting the Overlay Type and Parameters
 * -----------------------------------------------------------------------------
 */

/**
 *  Overlay type. The values that can be used with this property are usually constants defined by each individual overlay controller
 */
@property (nonatomic) NSString *type;

/**
 *  Overlay parameters. Implementation-specific to overlay controllers.
 */
@property (nonatomic) NSMutableDictionary *parameters;

/**-----------------------------------------------------------------------------
 * @name Positioning the Overlay On-Screen
 * -----------------------------------------------------------------------------
 */

/**
 *  Describes the position the overlay should take when placed on-screen by the player. See `APSMediaOverlayPosition` for available values.
 */
@property (nonatomic) APSMediaOverlayPosition position;

/**
 *  The order of the overlay in the current view stack.
 */

@property (nonatomic) int zIndex;
/**
 *  The width of the overlay. Supports pixels (e.g.: @"320") or percentages, relative to the total width (e.g.: @"50%").
 */

@property (nonatomic) NSString *width;
/**
 *  The height of the overlay. Supports pixels (e.g.: @"320") or percentages, relative to the total height (e.g.: @"50%").
 */

@property (nonatomic) NSString *height;
/**
 *  The overlay's absolute horizontal offset, relative to the current origin. The current origin is determined by the overlay's `position` parameter, while the positive direction is always toward the center of the player surface. Supports pixels (e.g.: @"320") or percentages, relative to the total width (e.g.: @"50%").
 */

@property (nonatomic) NSString *absoluteOffsetX;
/**
 *  The overlay's absolute vertical offset, relative to the current origin. The current origin is determined by the overlay's `position` parameter, while the positive direction is always toward the center of the player surface. Supports pixels (e.g.: @"320") or percentages, relative to the total height (e.g.: @"50%").
 */

@property (nonatomic) NSString *absoluteOffsetY;
/**
 *  The duration (in seconds) for the fade in effect of the overlay, when it is placed on and taken off screen.
 */

/**-----------------------------------------------------------------------------
 * @name Positioning the Overlay In Time
 * -----------------------------------------------------------------------------
 */

/**
 *  Sets the starting time point of the overlay.
 *
 *  @param startPoint A string format describing the time point when the player needs to display the overlay. Possible values are seconds (e.g.: @"60") or a percentage relative to the total duration of the parent clip (e.g.: @"50%").
 */
- (void)setStartPoint:(NSString*)startPoint;
/**
 *  Sets the ending time point of the overlay.
 *
 *  @param endPoint A string format describing the time point when the player needs to remove the overlay. Possible values are seconds (e.g.: @"60") or a percentage relative to the total duration of the parent clip (e.g.: @"50%").
 */
- (void)setEndPoint:(NSString*)endPoint;

/**
 *  The time interval (in seconds) when the player needs to display the overlay.
 *
 *  @return The initial time interval.
 *  @warning If percentual values were set via `setStartPoint`, this value will change immediately after the current clip's duration is available.
 */
- (NSTimeInterval)startPoint;
/**
 *  The time interval (in seconds) when the player needs to remove the overlay.
 *
 *  @return The final time interval.
 *  @warning If percentual values were set via `setStartPoint`, this value will change immediately after the current clip's duration is available.
 */
- (NSTimeInterval)endPoint;

/**
 *  Shifts air-time for an overlay by a defined amount of time.
 *
 *  @param duration Shift duration in seconds.
 */
- (void)incrementStartAndEndPointsWithInterval:(NSTimeInterval)duration;

/**
 *  Translates percentual values set via `setStartPoint` to actual time intervals in seconds, relative to a specified total duration.
 *
 *  @param duration The total duration.
 */
- (void)adjustRelativeToDuration:(NSTimeInterval)duration;


/**-----------------------------------------------------------------------------
 * @name Overlay Properties
 * -----------------------------------------------------------------------------
 */

/**
 *  The duration (in seconds) for the fade in effect of the overlay, when it is placed on and taken off screen.
 */
@property (nonatomic) CGFloat fadeInDuration;

/**
 *  This dictionary defines all URLs that need to be notified of specific events from the overlay's lifecycle. The keys are event constants, as defined in `APSMediaPlayer`, and the values are `NSArrays` containing `NSURL` objects.
 */
@property (nonatomic) NSMutableDictionary *trackingURLs;

/**
 *  If this parameter is greater than 0, then the overlay will be reshown by the media player after the specific time interval (in seconds).
 */
@property (nonatomic) NSTimeInterval repeatAfter;

/**
 *  Defines if the overlay should be removed from memory when its' opacity becomes zero.
 */
@property (nonatomic) BOOL removeWhenHidden;

/**
 *  After being added to a `APSMediaUnit` object, a reference to this parent can be found here.
 */
@property (nonatomic, weak) APSMediaUnit *parentUnit;

/**
 *  A refence to the overlay controller object. This is set by the player, on the overlay's initial render.
 */
@property (nonatomic) APSMediaPlayerOverlayController *controller;

/**
 *  Additional overlay information.
 */
@property (nonatomic) NSMutableDictionary *metadata;

/**-----------------------------------------------------------------------------
 * @name Other
 * -----------------------------------------------------------------------------
 */
/**
 *  Converts a string format to a APSMediaOverlayPosition value.
 *
 *  @param position The position of the overlay. Possible values are:
 *  - "top"
 *  - "topLeft"
 *  - "topRight"
 *  - "bottomLeft"
 *  - "bottomRight"
 *  - "bottom"
 *  - "fullscreen"
 *
 *  @return The APSMediaOverlayPosition value coresponding to the string format.
 */
+ (APSMediaOverlayPosition)positionFromString:(NSString*)position;

@end
