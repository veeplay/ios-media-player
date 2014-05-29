//
//  APSMediaPlayerOverlayController.h
//  APSVAST
//
//  Created by Appscend on 7/22/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
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
 *  The `APSMediaPlayerOverlayController` defines all the methods that a `UIViewController` subclass must or can implement to be able to register as an overlay controller with the player. This protocol extends the `KRAdapter` protocol, so objects should also define a unique string `type` to register under.
 */
@protocol APSMediaPlayerOverlayController <KRAdapter>
/**-----------------------------------------------------------------------------
 * @name Overlay Initialization
 * -----------------------------------------------------------------------------
 */
/**
 *  This method is invoked by the player when first diplaying the overlay controller object.
 *
 *  @param parameters The configuration parameters, copied from the `APSMediaOverlay` property with the same name.
 */
- (void)startWithParameters:(id)parameters;

@optional
/**
 *  This method is invoked by the player after the overlay controller object creation, with a reference to the corresponding `APSMediaOverlay` object that triggered the creation.
 *
 *  @param overlay The corresponding `APSMediaOverlay`
 */
- (void)setParentOverlay:(APSMediaOverlay*)overlay;

/**-----------------------------------------------------------------------------
 * @name Overlay Dictionary Configuration
 * -----------------------------------------------------------------------------
 */
/**
 *  The string key that will be used as the overlay type in the JSON and dictionary builder configurations.
 *
 *  @return String key.
 */
+ (NSString*)overlayConfigurationKey;
/**
 *  This method is called by the `APSMediaBuilder` object, in the process of its configuration, if in the JSON or `NSDictionary` configuration the overlay is defined to a type equal to the string defined by the overlay controller, using the `dictionaryConfigurationKey` method.
 *
 *  @param configuration A `NSDictionary` object containing the specific overlay controller configuration data.
 *
 *  @return The configuration dictionary, ready to be set to the `parameters` property of the `APSMediaOverlay`.
 */
+ (NSDictionary*)configurationFromDictionary:(NSDictionary*)configuration;
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
 *  This method is invoked by the player, when the fullscreen status has changed.
 */
- (void)fullscreenToggled;

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
 Allows an overlay controller to return a playback state in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMoviePlaybackState) for more details about `MPMoviePlaybackState`.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed playback state.
 */
- (MPMoviePlaybackState)playbackState;
/**
 Allows an overlay controller to return a load state in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/c/tdef/MPMovieLoadState) for more details about `MPMovieLoadState`.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed load state.
 */
- (MPMovieLoadState)loadState;
/**
 Allows an overlay controller to return a media source type in place of the parent `APSMediaUnit` object, if the `url` property of that object is nil. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMovieSourceType) for more details about `MPMovieSourceType`.
 
 This occurs for overlays that handle media playback in place of the parent unit, for e.g. the Youtube player overlay controller.
 *
 *  @return The current overlay-managed media source type.
 */
- (MPMovieSourceType)movieSourceType;
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
 *  @param time The time when the thumbnail should be taken from the video.
 *
 *  @return The resulting thumbnail.
 */
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)time;

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
