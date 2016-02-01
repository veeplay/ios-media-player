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
#import "APSTypes.h"

@class APSVASTAdBreak;
@class APSMediaOverlay;
@class APSMediaEvent;

#ifndef kAPSMetadataTitle
#define kAPSMetadataTitle @"title"
#define kAPSMetadataDescription @"description"
#define kAPSMetadataImageURL @"image"
#define kAPSMetadataType @"type"
#endif

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
 *  Specifies how the unit should handle seeking through multiple ad breaks.
 */
typedef NS_ENUM(NSInteger, APSHandleSeekEvent) {
    /**
     *  This will only trigger the first ad break.
     */
    APSHandleSeekEventPlayFirstBreak,
    /**
     *  This will only trigger the last ad break.
     */
    APSHandleSeekEventPlayLastBreak,
    /**
     *  This will trigger all ad breaks.
     */
    APSHandleSeekEventPlayAllBreaks
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
 *  @param overlay The `APSMediaOverlay` object to be connected to the unit.
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
 * @name Managing the media overlays connected to the current unit
 * -----------------------------------------------------------------------------
 */
/**
 *  Adds an object that implements the `APSMediaEvent` protocol to the unit.
 *
 *  @param overlay The event to be connected to the unit.
 */
- (void)addEvent:(APSMediaEvent*)overlay;

/**
 *  Connects an array of objects that implement the `APSMediaEvent` protocol to the current unit.
 *
 *  @param overlays An array of events to be connected to the unit.
 */
- (void)setEvents:(NSArray*)events;

/**
 *  Removes all currently connected events.
 */
- (void)clearEvents;

/**
 *  Removes a specific media event.
 */
- (void)removeEvent:(APSMediaEvent*)event;

/**
 *  Returns an array containing all event objects currently connected to the unit, that are not dynamic (see [APSMediaEvent dynamicPosition]).
 *
 *  @return An array of objects that implement the `APSMediaEvent` protocol.
 */
- (NSArray*)events;

/**
 *  Returns an array containing all event objects currently connected to the unit, that are dynamic (see [APSMediaEvent dynamicPosition]).
 *
 *  @return An array of objects that implement the `APSMediaEvent` protocol.
 */
- (NSArray*)dynamicEvents;

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
 *  Assigns a unit manager to the current unit. See APSUnitManagerProtocol for more information.
 */
@property (nonatomic) NSString *managerType;
/**
 The configuration for the controls bar overlay.
 
 The following keys are available:
 
 - *kAPSControlsBarColor*: Set this to a `UIColor` that represents the background color of the controls bar.
 - *kAPSControlsBarAlpha*: `NSNumber` that represents the opacity of the controls bar.
 - *kAPSControlsComponents*: Set this to a mask that you get using OR operations on `APSControlsOverlayComponents` constants.
 - *kAPSControlsPlayedTrackColor*: The `UIColor` of the portion of the seek bar that indicates the currently played duration of the movie.
 - *kAPSControlsBufferedTrackColor*: The `UIColor` of the portion of the seek bar that indicates the currently buffered duration of the movie.
 - *kAPSControlsEmptyTrackColor*: The `UIColor` of the portion of the seek bar that indicates the currently unbuffered duration of the movie.
 - *kAPSControlsPlayImage*: The `UIImage` of the play button to use in the playback controls bar. Only displayed if the playback component is selected.
 - *kAPSControlsPauseImage*: The `UIImage` of the pause button to use in the playback controls bar. Only displayed if the playback component is selected.
 - *kAPSControlsFullscreenImage*: The `UIImage` of the fullscreen button to use in the playback controls bar. Only displayed if the playback component is selected.
 - *kAPSControlsPreviousImage*: The `UIImage` of the back button to use in the playback controls bar. Only displayed if the back button component is selected.
 - *kAPSControlsNextImage*: The `UIImage` of the forward button to use in the playback controls bar. Only displayed if the forward button component is selected.
 - *kAPSControlsVisibileOnlyInFullscreen*: Defines whether the playback controls bar should only be visible while the player is in fullscreen mode. This is useful if implementing a custom player UX for normal mode. Set this to a `NSNumber` boolean.
 - *kAPSControlsAutohideDuration*: The number of seconds the playback controls bar should automatically become hidden after. Set this to a `NSNumber`.
 - *kAPSControlsLiveText*: The text to display instead of the total video duration, for live streams. Only has effect when the total duration component is selected. Defaults to `@"LIVE"`.
 - *kAPSControlsPlaybackTimeText*: The text to display instead of the current playback time, for live streams. Only has effect when the current playback time component is selected.
 - *kAPSControlsUpdateCurrentTimeWhileSeeking*: The current time text is showing the current seek position when dragging the seek bar
 */
@property (nonatomic) NSDictionary *controlsParameters;
/**
 *  The video clip scaling mode, relative to the player surface. Defaults to `APSMovieScalingModeNone`.
 */
@property (nonatomic) APSMovieScalingMode scalingMode;
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
 *  Additional unit key-value information.
 */
@property (nonatomic) NSMutableDictionary *metadata;
/**
 *  The APSVASTAdBreak objects which created this unit
 */
@property (nonatomic, weak) APSVASTAdBreak *adbreak;

/**-----------------------------------------------------------------------------
 * @name Ad Handling
 * -----------------------------------------------------------------------------
 */
/**
 *  Defines how mid content ads should be handled when the user has skipped over several batches. Use this parameter to instruct the player to render: only the first ad batch, only the last ad batch or all passed ad batches. Defaults to `APSHandleSeekEventPlayLastBreak`.
 */
@property (nonatomic, assign) APSHandleSeekEvent seekHandling;
/**
 *  For ad breaks assigned to this unit without an ad offset (breaks that should be auto-positioned within the content), this parameter defines the minimum time interval in seconds to wait before displaying the first ad batch. Defaults to 300 seconds.
 */
@property (nonatomic, assign) NSTimeInterval midcontentAdMinimumInitialOffset;
/**
 *  For ad breaks assigned to this unit without an ad offset (breaks that should be auto-positioned within the content), this parameter defines the minimum time interval in seconds (relative to the end of the video) that should be ad-free. Defaults to 300 seconds.
 */
@property (nonatomic, assign) NSTimeInterval midcontentAdMinimumFinalOffset;
/**
 *  For ad breaks assigned to this unit without an ad offset (breaks that should be auto-positioned within the content), this parameter defines the minimum time interval in seconds to wait between ad batches. Defaults to 300 seconds.
 */
@property (nonatomic, assign) NSTimeInterval midcontentAdMinimumSpacing;

/**-----------------------------------------------------------------------------
 * @name Utility Methods
 * -----------------------------------------------------------------------------
 */
/**
 Converts a string format to a `APSMovieScalingMode` value.

 Possible input values are:
 
 - *"aspectFit"*, that will be converted to `APSMovieScalingModeAspectFit`
 - *"aspectFill"*, that will be converted to `APSMovieScalingModeAspectFill`
 - *"fill"*, that will be converted to `APSMovieScalingModeFill`

 @param string A string format to be converted.
 
 @return A `APSMovieScalingMode` value.
 */
+ (APSMovieScalingMode)scalingModeFromString:(NSString*)string;
@end
