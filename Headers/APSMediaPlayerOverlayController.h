//
//  APSMediaPlayerOverlayController.h
//  APSVAST
//
//  Created by Appscend on 7/22/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "APSTypes.h"
@protocol KRAdapter;
@class APSMediaOverlay;

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

/**
 *  Defines the action that the player should take when resuming playback after an interruption caused by user interaction, that determined the display of the in-app web browser.
 */
typedef NS_ENUM(NSInteger, APSWebviewDismissedAction) {
    /**
     *  Player should hide the calling overlay on webview dismiss.
     */
    APSHideOverlayOnWebviewDismiss,
    /**
     *  Player should skip the current unit on webview dismiss.
     */
    APSSkipUnitOnWebviewDismiss,
    /**
     *  No action should be taken on webview dismiss.
     */
    APSDoNothingOnWebviewDismiss
};

/**
 *  The `APSMediaPlayerOverlayController` defines all the methods that a `UIViewController` subclass must or can implement to be able to register as an overlay controller with the player. This protocol extends the `KRAdapter` protocol, so objects should also implement a `type` method, returning a unique string to register under.
 
  To use:
 
  - Create a new class that implements this protocol
  - Register it with the player shared instance:
 
                [[APSMediaPlayer sharedInstance] registerClass:[<YOURCLASS> class] inGroup:kAPSMediaPlayerOverlayControllersGroup];
 
  - Set up with the `APSMediaOverlay`:
 
                overlay.type = @"<YOURSTRINGCONSTANT>"
 */
@protocol APSMediaPlayerOverlayControllerProtocol <KRAdapter>
/**-----------------------------------------------------------------------------
 * @name Overlay Initialization
 * -----------------------------------------------------------------------------
 */
/**
 *  This method is invoked by the player when first diplaying the overlay controller object.
 *
 */
- (void)load;

@optional

/**
 *  This method is invoked by the player on a background thread, before the overlay start point, as set by the [APSMediaEvent preTriggerInterval] property.
 */
- (void)preload;

/**-----------------------------------------------------------------------------
 * @name Callbacks
 * -----------------------------------------------------------------------------
 */
/**
 This method is called whenever the playback state of the player is changed (e.g. current playback time changes, playback state changes etc.). If the overlay controller needs to update its interface as a result of these changes, the updates should be performed in this method.
 
 The method is invoked on the main application thread.
 */
- (void)update;
/**
 This method is invoked by the player, before the overlay controller's view is removed from the player surface. Any overlay cleanup code should be performed in this method.
 
 The method is invoked on the main application thread.
 */
- (void)overlayWillBeRemoved;
/**
 *  This method is invoked by the player, when fullscreen mode is enabled.
 */
- (void)didEnterFullscreen;
/**
 *  This method is invoked by the player, when fullscreen mode is disabled.
 */
- (void)didExitFullscreen;
/**
 *  This method is invoked by the player, when picture in picture mode is enabled.
 */
- (void)didStartPictureInPicture;
/**
 *  This method is invoked by the player, when picture in picture mode is disabled.
 */
- (void)didStopPictureInPicture;

/**-----------------------------------------------------------------------------
 * @name Handling Playback
 * -----------------------------------------------------------------------------
 */
/**
 Allows an overlay controller to return a current playback time in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed playback time, in seconds.
 */
- (NSTimeInterval)currentPlaybackTime;
/**
 Allows an overlay controller to return a total playable (buffered) time in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed total playable (buffered) time, in seconds.
 */
- (NSTimeInterval)playableDuration;
/**
 *  Allows an overlay that handles media playback in place of the parent unit to internally set the current playback time.
 *
 *  @param playbackTime The required playback time to seek to, in seconds.
 */
- (void)setCurrentPlaybackTime:(NSTimeInterval)playbackTime;
/**
 Allows an overlay controller to return a total playback duration in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @param playbackTime The total overlay-managed playback duration, in seconds.
 */
- (NSTimeInterval)duration;
/**
 Allows an overlay controller to return a playback state in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed playback state.
 */
- (APSMoviePlaybackState)playbackState;
/**
 Allows an overlay controller to return a load state in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed load state.
 */
- (APSMovieLoadState)loadState;
/**
 Allows an overlay controller to return a media source type in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed media source type.
 */
- (APSMovieSourceType)movieSourceType;
/**
 *  Allows an overlay that handles media playback in place of the parent unit to start playback.
 */
- (void)play;
/**
 *  Allows an overlay that handles media playback in place of the parent unit to stop playback.
 */
- (void)stop;
/**
 *  Allows an overlay that handles media playback in place of the parent unit to pause playback.
 */
- (void)pause;
/**
 *  Allows an overlay that handles media playback in place of the parent unit to return a thumbnail image at a specific time interval from the managed video.
 *
 *  @param playbackTime The time when the thumbnail should be taken from the video.
 *  @param block The block to be invoked on thumbnail generation completion.
 *
 *  @warning This method should execute blocking operations on a background thread, and should invoke the callback block on the main thread.
 */
- (void) thumbnailAt:(NSTimeInterval) playbackTime withCompletionBlock:(APSThumbnailGeneratedBlock)block;

/**-----------------------------------------------------------------------------
 * @name Defining Behavior for Webview Dismiss Events
 * -----------------------------------------------------------------------------
 */
/**
 *  Allows an overlay controller to specify what action the player should take when it comes back into focus, after a modal in-app web browser was triggered and dismissed by user interaction.
 *
 *  @return The desired action. See `APSWebviewDismissedAction` for more details.
 */
- (APSWebviewDismissedAction)onWebviewDismiss;
@end

/**
 *  The superclass of all overlay controllers. Implements `APSMediaPlayerOverlayControllerProtocol`.
 */
@interface APSMediaPlayerOverlayController : UIViewController <APSMediaPlayerOverlayControllerProtocol>
/**
 *  A reference to the `APSMediaOverlay` object associated with the current overlay controller.
 */
@property (nonatomic, weak) APSMediaOverlay *overlay;
@end
