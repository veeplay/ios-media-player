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
#import "APSMediaPlayerYoutubeOverlayController.h"
#import "APSMediaPlayerVimeoOverlayController.h"
#import "APSMediaEvent.h"

@class APSMediaUnit;
@protocol APSMediaPlayerOverlayController;

#ifndef kAPSMetadataTitle
#define kAPSMetadataTitle @"title"
#define kAPSMetadataDescription @"description"
#define kAPSMetadataImageURL @"image"
#define kAPSMetadataType @"type"
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
@interface APSMediaOverlay : APSMediaEvent <NSCopying, APSMediaTrackableObject>

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


/**-----------------------------------------------------------------------------
 * @name Overlay Properties
 * -----------------------------------------------------------------------------
 */

/**
 *  The duration (in seconds) for the fade in effect of the overlay, when it is placed on and taken off screen.
 */
@property (nonatomic) CGFloat fadeInDuration;

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
