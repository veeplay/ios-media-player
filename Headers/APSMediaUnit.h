//
//  APSVASTMediaUnit.h
//  APSVAST
//
//  Created by Appscend on 7/21/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "APSMediaTrackableObject.h"
@class APSMediaOverlay;

#define kAPSMediaUnitTitle @"com.appscend.mp.unit.title"
#define kAPSMediaUnitDescription @"com.appscend.mp.unit.description"
#define kAPSMediaUnitImageURL @"com.appscend.mp.unit.image"
#define kAPSMediaUnitType @"com.appscend.mp.unit.type"

extern NSString *const APSContentUnit;

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif
/**
 *  Specifies how the controls bar should be displayed for a media unit.
 */
typedef NS_ENUM(NSInteger, APSMediaControlsDisplay) {
    /**
     *  The controls bar should be displayed at the bottom of the player surface.
     */
    APSMediaControlsDisplayBottom,
    /**
     *  The controls bar should be displayed at the top of the player surface.
     */
    APSMediaControlsDisplayTop,
    /**
     *  The controls bar should not be displayed for this unit.
     */
    APSMediaControlsDisplayNone
};

/**
 *  The `APSMediaUnit` class represents a clip that's ready to be rendered by the player. A media unit also references an array of `APSMediaOverlay` objects, defining the overlays connected to the unit.
 */
@interface APSMediaUnit : NSObject <NSCopying, APSMediaTrackableObject>

/**-----------------------------------------------------------------------------
 * @name Creating a media unit
 * -----------------------------------------------------------------------------
 */
/**
 *  Initializes a media unit object.
 *
 *  @param url The video clip URL.
 *
 *  @return A new `APSMediaUnit` object
 */
- (APSMediaUnit*)initWithURL:(NSURL*)url;

/**-----------------------------------------------------------------------------
 * @name Managing the media overlays connected to the current unit
 * -----------------------------------------------------------------------------
 */
/**
 *  Adds an `APSMediaOverlay` object to the unit, to be rendered together.
 *
 *  @param overlay The `APSMediaPlayer` object to be connected to the unit.
 */
- (void)addOverlay:(APSMediaOverlay*)overlay;

/**
 *  Connects an array of `APSMediaOverlay` objects to the current unit.
 *
 *  @param overlays An array of `APSMediaOverlay` objects to be connected to the unit.
 */
- (void)setOverlays:(NSArray*)overlays;

/**
 *  Removes all currently connected overlays.
 */
- (void)clearOverlays;

/**
 *  Returns an array containing all `APSMediaOverlay` objects currently connected to the unit.
 *
 *  @return An array of `APSMediaOverlay` objects.
 */
- (NSArray*)overlays;

/**-----------------------------------------------------------------------------
 * @name Unit Properties
 * -----------------------------------------------------------------------------
 */
/**
 *  The video clip URL.
 */
@property (nonatomic) NSURL *url;
/**
 *  Initial video playback time in seconds.
 */
@property (nonatomic) NSTimeInterval initialPlaybackTime;
/**
 *  Defines how the controls bar will be displayed for the unit. See `APSMediaControlsDisplay` for possible values.
 */
@property (nonatomic) APSMediaControlsDisplay controlsDisplay;
/**
 *  The configuration for the controls bar overlay. Construct this using the `configurationFromDictionary:` method of  `APSMediaPlayerControlsOverlayController`.
 */
@property (nonatomic) NSDictionary *controlsParameters;
/**
 *  The video clip scaling mode, relative to the player surface. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMovieScalingMode) for more details on `MPMovieScalingMode`. Defaults to `MPMovieScalingModeNone`.
 */
@property (nonatomic) MPMovieScalingMode scalingMode;
/**
 *  This dictionary defines all URLs that need to be notified of specific events from the unit's lifecycle. The keys are event constants, as defined in `APSMediaPlayer`, and the values are `NSArrays` containing `NSURL` objects.
 */
@property (nonatomic) NSMutableDictionary *trackingURLs;
/**
 *  An array of other media units to be played instead of the current one, should an error be encountered. The unit at index 0 has the highest priority.
 */
@property (nonatomic) NSMutableArray *buffet;
/**
 *  Defines if pinch-to-fullscreen should be allowed.
 */
@property (nonatomic) BOOL pinchToFullscreen;
/**
 *  Defines if the unit should start playing as soon as it loads or wait for a play command.
 */
@property (nonatomic) BOOL shouldAutoplay;
/**
 *  Defines whether the player can replay the current unit or not after it has ended in the playlist.
 */
@property (nonatomic) BOOL canReplay;
/**
 *  Toggle to enable logs.
 */
@property (nonatomic) BOOL debug;
/**
 *  Additional unit information.
 */
@property (nonatomic) NSMutableDictionary *metadata;

/**-----------------------------------------------------------------------------
 * @name Utility Methods
 * -----------------------------------------------------------------------------
 */
/**
 Converts a string format to a `MPMovieScalingMode` value. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMovieScalingMode) for more details on `MPMovieScalingMode`.

 Possible input values are:
 
 - *"aspectFit"*, that will be converted to `MPMovieScalingModeAspectFit`
 - *"aspectFill"*, that will be converted to `MPMovieScalingModeAspectFill`
 - *"fill"*, that will be converted to `MPMovieScalingModeFill`

 @param string A string format to be converted.
 
 @return A `MPMovieScalingMode` value.
 */
+ (MPMovieScalingMode)scalingModeFromString:(NSString*)string;
@end
