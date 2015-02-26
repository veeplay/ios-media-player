//
//  APSMediaPlayer.h
//  APSVAST
//
//  Created by Appscend on 7/21/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

#import "KRHub.h"
#import "APSMediaBuilder.h"
#import "APSMediaOverlay.h"
#import "APSMediaUnit.h"
#import "TSMiniWebBrowser.h"

#define kAPSMediaPlayerEventType @"event.type"
#define kAPSMediaPlayerEvent @"event"
#define kAPSMediaPlayerEventURLs @"event.urls"
#define kAPSMediaPlayerEventSource @"event.source"

@protocol APSUnitManagerProtocol;

///--------------------
/// @name Notifications
///--------------------

/**
 *  Posted before the media player enters fullscreen
 */
extern NSString *const APSMediaPlayerWillEnterFullscreenNotification;
/**
 *  Posted before the media player exists fullscreen
 */
extern NSString *const APSMediaPlayerWillExitFullscreenNotification;
/**
 *  Posted when the user taps on the media player surface
 */
extern NSString *const APSMediaPlayerWasTappedNotification;
/**
 *  Posted when the video controls bar becomes visible
 */
extern NSString *const APSMediaPlayerControlsDisplayedNotification;
/**
 *  Posted when the video controls bar becomes hidden
 */
extern NSString *const APSMediaPlayerControlsHiddenNotification;
/**
 *  Posted every time the internal status of the media player changes. This will happen roughly once every second.
 */
extern NSString *const APSMediaPlayerUpdateNotification;
/**
 *  Posted when a media unit finishes playback, before the remaining playlist units are processed. The `userInfo` dictionary contains the APSMediaUnit object that just finished playback under the `unit` key.
 */
extern NSString *const APSMediaPlayerUnitFinishedNotification;
/**
 *  Posted when the media player encounters an error in the process of unit playback. The `userInfo` dictionary contains the NSError object that represents the error under the `error` key.
 */
extern NSString *const APSMediaPlayerErrorNotification;
/**
 *  Posted when the media player playback state has changed. You can immediately get the new state using the `playbackState` method of the APSMediaPlayer instance. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMoviePlaybackState) on MPMoviePlaybackState for more details about the available playback states .
 */
extern NSString *const APSMediaPlayerStatusChangedNotification;
/**
 *  Posted when a trackable playback event occurs.
 *  The `userinfo` dictionary contains additional information about the tracked event:
 *  - the `kAPSMediaPlayerEventDescription` key returns a string description of the tracked event
 *  - the `kAPSMediaPlayerEventType` key returns one of the possible event type constants
 *  - the `kAPSMediaPlayerEventURLs` key returns an array of NSURLs that were pinged to track the event
 */
extern NSString *const APSMediaPlayerTrackedEventNotification;
/**
 *  Posted when the player license is invalid. Playback will be disabled.
 */
extern NSString *const APSMediaPlayerInvalidLicenseNotification;


///-------------------------------------
/// @name Available Tracking Events
///-------------------------------------
extern NSString *const APSMediaPlayerEventLaunch;
extern NSString *const APSMediaPlayerEventStart;
extern NSString *const APSMediaPlayerEventFinish;
extern NSString *const APSMediaPlayerEventExitFullscreen;
extern NSString *const APSMediaPlayerEventFullscreen;
extern NSString *const APSMediaPlayerEventImpression;
extern NSString *const APSMediaPlayerEventCreativeView;
extern NSString *const APSMediaPlayerEventResume;
extern NSString *const APSMediaPlayerEventPause;
extern NSString *const APSMediaPlayerEventRewind;
extern NSString *const APSMediaPlayerEventForward;
extern NSString *const APSMediaPlayerEventMute;
extern NSString *const APSMediaPlayerEventUnmute;
extern NSString *const APSMediaPlayerEventError;
extern NSString *const APSMediaPlayerEventComplete;
extern NSString *const APSMediaPlayerEventClose;
extern NSString *const APSMediaPlayerEventCloseLinear;
extern NSString *const APSMediaPlayerEventSkip;
extern NSString *const APSMediaPlayerEventClick;
extern NSString *const APSMediaPlayerEventIconView;
extern NSString *const APSMediaPlayerEventExpand;
extern NSString *const APSMediaPlayerEventCollapse;
extern NSString *const APSMediaPlayerEventUpdate;
extern NSString *const APSMediaPlayerEventSeeked;

#define kAPSMediaPlayerCurrentPlaybackTime @"current_playback_time"
#define kAPSMediaPlayerCurrentDuration @"current_duration"
#define kAPSMediaPlayerError @"error"
#define kAPSMediaPlayerSeekStart @"seek_start"

/**
 *  The `APSMediaPlayerActionDelegate` protocol declares the two methods that a class must implement in order to become an `APSMediaPlayer` actionDelegate. The object implementing `APSMediaPlayer` will receive information about the URLs that need to be executed as the user interacts with the player.
 */
@protocol APSMediaPlayerActionDelegate <NSObject>
/**
 *  Returns a Boolean value indicating whether the receiver is able to interpret and react to the given input `NSURL`.
 *
 *  @param url The URL that needs to be launched.
 *
 *  @return `YES` if the object can interpret and react to the given input URL, `NO` otherwise.
 */
- (BOOL)canRespondTo:(NSURL*)url;
/**
 *  If the `APSMediaPlayerActionDelegate` implementing object returns `YES` from the `canRespondTo` method for a certain URL, this method will be triggered to request effective execution.
 *
 *  @param url The URL that needs to be launched.
 */
- (void)respondTo:(NSURL*)url;
@end

/**
 * The block to be executed when the current playlist is completed
 * @since v1.7
 */
typedef void (^APSMediaPlayerFinishBlock)();



/**
 The APSMediaPlayer handles playback and rendering of APSMediaUnits and APSMediaOverlays.
 
 ## Notifications
 
 - **APSMediaPlayerWillEnterFullscreenNotification** - Posted before the media player enters fullscreen
 - **APSMediaPlayerWillExitFullscreenNotification** - Posted before the media player exists fullscreen
 - **APSMediaPlayerWasTappedNotification** - Posted when the user taps on the media player surface
 - **APSMediaPlayerControlsDisplayedNotification** - Posted when the video controls bar becomes visible
 - **APSMediaPlayerControlsHiddenNotification** - Posted when the video controls bar becomes hidden
 - **APSMediaPlayerUpdateNotification** - Posted every time the internal status of the media player changes. This will happen roughly once every second.
 - **APSMediaPlayerUnitFinishedNotification** - Posted when a media unit finishes playback, before the remaining playlist units are processed. The `userInfo` dictionary contains the APSMediaUnit object that just finished playback under the `unit` key.
 - **APSMediaPlayerErrorNotification** - Posted when the media player encounters an error in the process of unit playback. The `userInfo` dictionary contains the NSError object that represents the error under the `error` key.
 - **APSMediaPlayerStatusChangedNotification** - Posted when the media player playback state has changed. You can immediately get the new state using the `playbackState` method of the APSMediaPlayer instance. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMoviePlaybackState) on MPMoviePlaybackState for more details about the available playback states.
 - **APSMediaPlayerTrackedEventNotification**
 Posted when a trackable playback event occurs.
 The `userinfo` dictionary contains additional information about the tracked event:
     - the `kAPSMediaPlayerEventDescription` key returns a string description of the tracked event
     - the `kAPSMediaPlayerEventType` key returns one of the possible event type constants
     - the `kAPSMediaPlayerEventURLs` key returns an array of NSURLs that were pinged to track the event
 - **APSMediaPlayerInvalidLicenseNotification**
 Posted when the player license is invalid. Playback will be disabled.
 
 ## Constants
 
 - *kAPSMediaPlayerOverlayControllersGroup* - The group name that 3rd party overlay controllers must use when registering with the player.
 */
@interface APSMediaPlayer : KRHub <TSMiniWebBrowserDelegate>

/**-----------------------------------------------------------------------------
 * @name Accessing the APSMediaPlayer Instance and its View
 * -----------------------------------------------------------------------------
 */

/**
 *  Returns the shared `APSMediaPlayer` instance, creating it if necessary.
 *
 *  @return The shared `APSMediaPlayer` instance
 */
+ (instancetype)sharedInstance;
/**
 *  The container `UIView` of the player.
 */
@property (nonatomic, readonly) UIView *view;
/**
 *  Call this method to set the player view frame.
 *
 *  @param frame `CGRect` player view frame.
 */
- (void)setFrame:(CGRect)frame;

/**-----------------------------------------------------------------------------
 * @name Working with Media Units
 * -----------------------------------------------------------------------------
 */
/**
 *  Sets and begins playback of an array of media units.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects.
 */
- (void)playMediaUnits:(NSArray*)mediaUnits;
/**
 *  Inserts new media units after the current one, in the current playlist.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to be inserted into the playlist after the current unit.
 */
- (void)insertMediaUnits:(NSArray*)mediaUnits;
/**
 *  Replaces the currently running media unit with multiple other units. Playback of the new units is started automatically.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to be inserted into the playlist instead of the current unit.
 */
- (void)replaceCurrentUnitWithUnits:(NSArray*)mediaUnits;
/**
 *  Sets new units to the playlist, clearing any old ones.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to create a new playlist.
 */
- (void)setMediaUnits:(NSArray*)mediaUnits;
/**
 *  Returns the currently playing media unit.
 *
 *  @return An `APSMediaUnit` object representing the current unit.
 */
- (APSMediaUnit*)currentUnit;
/**
 *  Sets the video clip URL for the current media unit. The clip is processeed immmediately.
 *
 *  @param url The URL of the video clip.
 */
- (void)setCurrentURL:(NSURL*)url;
/**
 *  Adds additional overlays to display over the current unit.
 *
 *  @param overlays Additional `APSMediaOverlay` objects to inject.
 */
- (void)addOverlays:(NSArray*)overlays;
/**
 *  Adds additional events to the current unit's timeline.
 *
 *  @param overlays Additional `APSMediaEvent` objects to inject.
 */
- (void)addEvents:(NSArray*)events;

/**-----------------------------------------------------------------------------
 * @name Tracking Playback Events
 * -----------------------------------------------------------------------------
 */
/**
 *  This method triggers an `APSMediaPlayerTrackedEventNotification` notification.
 *  @warning Also sends tracking information to one or more servers. All specified URLs will be requested via GET. If the given object is an instance of the `APSMediaUnit` or the `APSMediaOverlay` classes, the `trackingURLs` dictionary property will be searched for the `type` key to identify the URLs that need to be pinged. Alternatively, you can pass a `NSArray`, a `NSURL` or a `NSString` as the object parameter. See "Available Tracking Events" for a list of supported event types.
 *
 *  @param event The specific event subtype. May be nil for simple events.
 *  @param type  The tracked event type. See "Available Tracking Events".
 *  @param object The `APSMediaUnit` or `APSMediaOverlay` instance that generated the notification. Can be nil for non-unit related events.
 *  @param metadata Additional key-value pairs to send via the notification's userInfo to subscribers.
 *  @param urls An array of `NSURL` objects representing addresses that should be pinged. Also accepts an array of `NSString` objects, a single `NSURL` or a single `NSString`. 
 */
- (void)trackEvent:(NSString*)event type:(NSString*)type forObject:(id)object metadata:(NSDictionary*)metadata urls:(id)urls;

/**
 *  This is a wrapper for trackEvent:type:forObject:metadata:urls:
 */
- (void)trackEvent:(NSString*)event type:(NSString*)type forObject:(id)object;

/**-----------------------------------------------------------------------------
 * @name URL Handling
 * -----------------------------------------------------------------------------
 */
/**
 *  The player's action delegate. Any intent to execute specific URLs as a result of user interaction will be notified to the delegate for action.
 */
@property (nonatomic, weak) id<APSMediaPlayerActionDelegate> actionDelegate;
/**
 *  The view controller that will be used to present any modal views by the player.
 */
@property (nonatomic, weak) UIViewController *modalViewControllerRoot;
/**
 *  Instructs the player that a new URL needs to be interpreted and executed. This method will first ask the actionDelegate to respond to the given URL. If the actionDelegate declines to respond and the URL has a web scheme (`http://' or 'https://') then an in-app web browser window will be displayed modally.
 *
 *  @param url The URL that needs to be loaded.
 */
- (void)openURL:(NSURL*)url;
/**
 *  Instructs the player that a new URL needs to be interpreted and executed. This method also specifies the calling overlay controller, as it can define specific behavior for the player upon returning to the foreground after the playback interruption (see `onWebviewDismiss` in `APSMediaPlayerOverlayController.h`).
 *
 *  @param url     The URL that needs to be loaded.
 *  @param overlay The calling overlay controller.
 */
- (void)openURL:(NSURL*)url from:(APSMediaPlayerOverlayController*)overlayController;

/**-----------------------------------------------------------------------------
 * @name Handling Playback
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a Boolean value specifing if the player is currently rendering a playlist of units (read-only).
 */
@property (nonatomic, readonly) BOOL isProcessing;
/**
 *  Starts playback of the current unit.
 */
- (void)play;
/**
 *  Pauses playback of the current unit.
 */
- (void)pause;
- (void)interrupt;
/**
 *  Stops playback of the current unit.
 */
- (void)stop;
/**
 *  Proceeds to the next unit in the playlist and sends a skip event.
 */
- (void)skip;
/**
 *  Proceeds to the next unit in the playlist and sends an exit event.
 */
- (void)next;
/**
 *  Proceeds to the next unit in the playlist.
 */
- (void)step;
/**
 *  Replays the most recently played unit in the current playlist that has the `canReplay` property set to `YES`. If no such units are found, the current unit is restarted.
 */
- (void)previous;
/**
 *  A block object that will get executed when a playlist of units is finished rendering by the player.
 */
@property (nonatomic, copy) APSMediaPlayerFinishBlock onFinish;

/**-----------------------------------------------------------------------------
 * @name Getting Playback Information
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns the current playback time.
 *
 *  @return The current playback time.
 */
- (NSTimeInterval)currentPlaybackTime;
/**
 *  Sets the current playback time.
 *
 *  @param playbackTime The playback time to be set.
 */
- (void)setCurrentPlaybackTime:(NSTimeInterval)playbackTime;
/**
 *  Returns the current unit's video clip total duration.
 *
 *  @return The video total duration.
 */
- (NSTimeInterval)duration;
/**
 *  Returns the current unit's video clip playable duration (the time interval that has already buffered and is ready for playback).
 *
 *  @return The video playable duration.
 */
- (NSTimeInterval)playableDuration;
/**
 *  Returns the current unit's playback state. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMoviePlaybackState) for more details about `MPMoviePlaybackState`.
 *
 *  @return The current playback state.
 */
- (MPMoviePlaybackState)playbackState;
/**
 *  Returns the current unit's load state. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/c/tdef/MPMovieLoadState) for more details about `MPMovieLoadState`.
 *
 *  @return The current load state.
 */
- (MPMovieLoadState)loadState;
/**
 *  Returns the current unit's movie source type. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMovieSourceType) for more details about `MPMovieSourceType`.
 *
 *  @return The movie source type.
 */
- (MPMovieSourceType)movieSourceType;

/**
 *  Returns `YES` if the player is currently rendering a live stream.
 *
 *  @return `YES` if the player is currently rendering a live stream.
 */
- (BOOL)isStreamingLive;

/**
 *  Obtains the most recent time-based metadata provided by the streamed movie.
 *
 *  @return An array of the most recent `MPTimedMetadata` objects provided by the streamed movie. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/mediaplayer/reference/MPTimedMetadata_Class/Reference/Reference.html#//apple_ref/occ/cl/MPTimedMetadata) for more details about `MPTimedMetadata`.
 */
- (NSArray*)timedMetadata;

/**-----------------------------------------------------------------------------
 * @name Getting Video Thumbnails
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a snapshot image of the current video, at the requested time interval in the playback.
 *
 *  @param time The time when the thumbnail should be taken from the video.
 *
 *  @return The resulting thumbnail.
 *
 *  @warning This method executes blocking operations on the calling thread.
 */
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)time;

/**-----------------------------------------------------------------------------
 * @name Handling Fullscreen
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a Boolean value specifing if the player is currently in fullscreen (read-only).
 */
@property (nonatomic, readonly) BOOL isFullscreen;
/**
 *  Toggle the current fullscreen status.
 */
- (void)toggleFullscreen;
/**
 *  Enter fullscreen mode.
 */
- (void)enterFullscreen;
/**
 *  Exit fullscreen mode.
 */
- (void)exitFullscreen;

/**-----------------------------------------------------------------------------
 * @name Extending
 * -----------------------------------------------------------------------------
 */
/**
 *  Registers a new overlay controller with the player.
 *
 *  @param controllerClass The class of the new overlay controller.
 */
- (void)registerOverlayController:(Class<APSMediaPlayerOverlayControllerProtocol>)controllerClass;
/**
 *  This method instantiates and returns a new object of the class registered for the given overlay type.
 *
 *  @param type The type of controller required.
 *
 *  @return A new object that implements `APSMediaPlayerOverlayControllerProtocol` or `nil` if no controllers are registered for the given type.
 */
- (NSObject<APSMediaPlayerOverlayControllerProtocol>*)overlayControllerForType:(NSString*)type;
/**
 *  Registers a new unit manager to dynamically handle media playback.
 *
 *  @param managerClass The new unit manager object.
 */
- (void)registerUnitManager:(NSObject<APSUnitManagerProtocol>*)managerClass;
/**-----------------------------------------------------------------------------
 * @name Airplay
 * -----------------------------------------------------------------------------
 */
/**
 *  Specifies whether the movie player allows AirPlay movie playback.
 */
@property (nonatomic) BOOL allowsAirPlay;
/**
 *  Indicates whether the movie player is currently playing video via AirPlay.
 */
- (BOOL)airPlayVideoActive;

/**-----------------------------------------------------------------------------
 * @name Other
 * -----------------------------------------------------------------------------
 */
/**
 *  Shows an activity indicator, centrally in the player surface.
 */
- (void)showActivityIndicator;
/**
 *  Hides the player activity indicator.
 */
- (void)hideActivityIndicator;
/**
 *  Resets all displayed overlays.
 */
- (void)resetDisplayedOverlays;
/**
 *  Parses a string format and returns a translated time interval in seconds.
 *
 *  @param string The string format to be translated. Must be in the format @"hh:mm:ss".
 *
 *  @return The translated time interval in seconds.
 */
+ (NSTimeInterval)durationFromString:(NSString*)string;
/**
 *  Specifies whether the player should ignore the device silent switch setting.
 */
@property (nonatomic, assign) BOOL ignoreSilentSwitch;
/**
 *  Specifies whether the player should stop functioning if the currently running device is detected to be jailbroken.
 */
@property (nonatomic, assign) BOOL detectBreachedDevice;
/**
 *  Use this property to store the unique device advertising identifier, that can then be used by 3rd party components.
 */
@property (nonatomic) NSString *advertisingIdentifier;

@end
