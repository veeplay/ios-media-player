//
//  APSMediaPlayer.h
//  APSVAST
//
//  Created by Appscend on 7/21/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SafariServices/SafariServices.h>
#import <MediaPlayer/MediaPlayer.h>

#import "KRHub.h"
#import "APSMediaBuilder.h"
#import "APSMediaOverlay.h"
#import "APSMediaUnit.h"
#import "APSTypes.h"
#import "APSEvent.h"
#import "APSVASTRegulationInformation.h"

#define kAPSMediaPlayerEventType @"event.type"
#define kAPSMediaPlayerEvent @"event"
#define kAPSMediaPlayerEventURLs @"event.urls"
#define kAPSMediaPlayerEventSource @"event.source"
#define kAPSMediaPlayerCurrentPlaybackTime @"current_playback_time"
#define kAPSMediaPlayerCurrentDuration @"current_duration"
#define kAPSMediaPlayerError @"error"
#define kAPSMediaPlayerSeekStart @"seek_start"
#define kAPSMediaPlayerSeekTo @"seek_to"

#define kAPSMediaPlayerPlaybackDidFinishReason @"finish_reason"
#define KAPSMediaPlayerCurrentUnit @"unit"

#define kAPSMediaPlayerOverlayControllersGroup @"com.appscend.mp.controllers.overlay"
#define kAPSMediaPlayerUnitManagersGroup @"com.appscend.mp.unitmanager"
#define kAPSMediaPlayerBackendsGroup @"com.appscend.mp.backend"
#define kAPSMediaPlayerControlPluginsGroup @"com.appscend.mp.controlplugin"

typedef NSString* APSBackendPlayer;

@protocol APSUnitManagerProtocol;

///--------------------
/// @name Notifications
///--------------------

/**
 *  Posted when the fullscreen button was pressed and internal fullscreen handling is disabled
 */
extern NSString * _Nonnull const APSMediaPlayerToggleFullscreenNotification;
/**
 *  Posted before the media player enters fullscreen
 */
extern NSString * _Nonnull const APSMediaPlayerWillEnterFullscreenNotification;
/**
 *  Posted after the media player enters fullscreen
 */
extern NSString * _Nonnull const APSMediaPlayerDidEnterFullscreenNotification;
/**
 *  Posted before the media player exists fullscreen
 */
extern NSString * _Nonnull const APSMediaPlayerWillExitFullscreenNotification;
/**
 *  Posted after the media player exists fullscreen
 */
extern NSString * _Nonnull const APSMediaPlayerDidExitFullscreenNotification;
/**
 *  Posted before starting Picture in Picture mode
 */
extern NSString * _Nonnull const APSMediaPlayerWillStartPictureInPictureNotification;
/**
 *  Posted after Picture in Picture mode was started
 */
extern NSString * _Nonnull const APSMediaPlayerDidStartPictureInPictureNotification;
/**
 *  Posted before stopping Picture in Picture mode
 */
extern NSString * _Nonnull const APSMediaPlayerWillStopPictureInPictureNotification;
/**
 *  Posted after stopping Picture in Picture mode
 */
extern NSString * _Nonnull const APSMediaPlayerDidStopPictureInPictureNotification;
/**
 *  Posted when the user taps on the media player surface
 */
extern NSString * _Nonnull const APSMediaPlayerWasTappedNotification;
/**
 *  Posted when the video controls bar becomes visible
 */
extern NSString * _Nonnull const APSMediaPlayerControlsDisplayedNotification;
/**
 *  Posted when the video controls bar becomes hidden
 */
extern NSString * _Nonnull const APSMediaPlayerControlsHiddenNotification;
/**
 *  Posted every time the internal status of the media player changes. This will happen roughly once every second.
 */
extern NSString * _Nonnull const APSMediaPlayerUpdateNotification;
/**
 *  Posted when a media unit finishes playback, before the remaining playlist units are processed. The `userInfo` dictionary contains the APSMediaUnit object that just finished playback under the `KAPSMediaPlayerCurrentUnit` key.
 */
extern NSString * _Nonnull const APSMediaPlayerUnitFinishedNotification;
/**
 *  Posted when the media player encounters an error in the process of unit playback. The `userInfo` dictionary contains the NSError object that represents the error under the `error` key.
 */
extern NSString * _Nonnull const APSMediaPlayerErrorNotification;
/**
 *  Posted when the media player playback state has changed. You can immediately get the new state using the `playbackState` method of the APSMediaPlayer instance.
 */
extern NSString * _Nonnull const APSMediaPlayerStatusChangedNotification;
/**
 *  Posted when a trackable playback event occurs.
 *  The `userinfo` dictionary contains additional information about the tracked event:
 *  - the `kAPSMediaPlayerEventDescription` key returns a string description of the tracked event
 *  - the `kAPSMediaPlayerEventType` key returns one of the possible event type constants
 *  - the `kAPSMediaPlayerEventURLs` key returns an array of NSURLs that were pinged to track the event
 *  - the `kAPSMediaPlayerCurrentPlaybackTime` key returns the playback time when the event was triggered
 *  - the `kAPSMediaPlayerCurrentDuration` key returns the total duration of the unit that triggered the event
 *  - the `kAPSMediaPlayerError` is present in case the event signals an error
 *  - the `kAPSMediaPlayerSeekStart` is present for `APSMediaPlayerEventSeeked` events and indicates the playback time when the seek started
 *  - the `kAPSMediaPlayerSeekTo` is present for `APSMediaPlayerEventSeeked` events and indicates the requested playback time to seek to
 */
extern NSString * _Nonnull const APSMediaPlayerTrackedEventNotification;
/**
 *  Posted when the player license is invalid. Playback will be disabled.
 */
extern NSString * _Nonnull const APSMediaPlayerInvalidLicenseNotification;
/**
 *  Posted when the internal minibrowser will open because an ad was tapped
 */
extern NSString * _Nonnull const APSMediaPlayerWillOpenMiniBrowser;
/**
 *  Posted when the internal minibrowser will be dismissed
 */
extern NSString * _Nonnull const APSMediaPlayerWillCloseMiniBrowser;
/**
 *  Posted when the internal player backend finished playback
 */
extern NSString * _Nonnull const APSMediaPlayerPlaybackDidFinishNotification;
/**
 *  Posted when the media load state changed
 */
extern NSString * _Nonnull const APSMediaPlayerLoadStateDidChangeNotification;
/**
 *  Posted when the duration of the played media becomes available
 */
extern NSString * _Nonnull const APSMediaPlayerDurationAvailableNotification;
/**
 *  Posted when the media playback state changed
 */
extern NSString * _Nonnull const APSMediaPlayerPlaybackStateDidChangeNotification;
/**
 *  Posted when the volume changed
 */
extern NSString * _Nonnull const APSMediaPlayerVolumeDidChangeNotification;

///-------------------------------------
/// @name Available Tracking Events
///-------------------------------------
extern NSString * _Nonnull const APSMediaPlayerEventLaunch;
extern NSString * _Nonnull const APSMediaPlayerEventStart;
extern NSString * _Nonnull const APSMediaPlayerEventFinish;
extern NSString * _Nonnull const APSMediaPlayerEventPlaylistFinish;
extern NSString * _Nonnull const APSMediaPlayerEventExitFullscreen;
extern NSString * _Nonnull const APSMediaPlayerEventFullscreen;
extern NSString * _Nonnull const APSMediaPlayerEventImpression;
extern NSString * _Nonnull const APSMediaPlayerEventViewableImpressionViewable;
extern NSString * _Nonnull const APSMediaPlayerEventViewableImpressionNotViewable;
extern NSString * _Nonnull const APSMediaPlayerEventViewableImpressionUndetermined;
extern NSString * _Nonnull const APSMediaPlayerEventCreativeView;
extern NSString * _Nonnull const APSMediaPlayerEventResume;
extern NSString * _Nonnull const APSMediaPlayerEventPause;
extern NSString * _Nonnull const APSMediaPlayerEventRewind;
extern NSString * _Nonnull const APSMediaPlayerEventForward;
extern NSString * _Nonnull const APSMediaPlayerEventMute;
extern NSString * _Nonnull const APSMediaPlayerEventUnmute;
extern NSString * _Nonnull const APSMediaPlayerEventError;
extern NSString * _Nonnull const APSMediaPlayerEventComplete;
extern NSString * _Nonnull const APSMediaPlayerEventClose;
extern NSString * _Nonnull const APSMediaPlayerEventCloseLinear;
extern NSString * _Nonnull const APSMediaPlayerEventSkip;
extern NSString * _Nonnull const APSMediaPlayerEventClick;
extern NSString * _Nonnull const APSMediaPlayerEventIconView;
extern NSString * _Nonnull const APSMediaPlayerEventExpand;
extern NSString * _Nonnull const APSMediaPlayerEventCollapse;
extern NSString * _Nonnull const APSMediaPlayerEventUpdate;
extern NSString * _Nonnull const APSMediaPlayerEventPosition;
extern NSString * _Nonnull const APSMediaPlayerEventSeeked;
extern NSString * _Nonnull const APSMediaPlayerEventSSAIAdStarted;
extern NSString * _Nonnull const APSMediaPlayerEventSSAIAdEnded;
extern NSString * _Nonnull const APSMediaPlayerEventAdBreakTriggered;
extern NSString * _Nonnull const APSMediaPlayerEventAdRequested;

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
- (BOOL)canRespondTo:(NSURL*_Nonnull)url;
/**
 *  If the `APSMediaPlayerActionDelegate` implementing object returns `YES` from the `canRespondTo` method for a certain URL, this method will be triggered to request effective execution.
 *
 *  @param url The URL that needs to be launched.
 */
- (void)respondTo:(NSURL*_Nonnull)url;
@end

/**
 * The block to be executed when the current playlist is completed
 * @since v1.7
 */
typedef void (^APSMediaPlayerFinishBlock)(void);

/**
 *  Defines the viewability status of the player according to VAST 4 specifications
 */
typedef NS_ENUM(NSInteger, APSViewability) {
    /**
     *  Player's viewport is more than 50% viewable
     */
    APSViewabilityViewable,
    /**
     *  Player's viewport is less than 50% viewable
     */
    APSViewabilityNotViewable,
    /**
     *  Player's viewpoer could not be determined
     */
    APSViewabilityUndetermined
};

/**
 The APSMediaPlayer handles playback and rendering of APSMediaUnits and APSMediaOverlays.
 
 ## Notifications
 
 - **APSMediaPlayerToggleFullscreenNotification** - Posted with each toggle of the fullscreen status
 - **APSMediaPlayerWillEnterFullscreenNotification** - Posted before the media player enters fullscreen
 - **APSMediaPlayerDidEnterFullscreenNotification** - Posted after the media player enters fullscreen
 - **APSMediaPlayerWillExitFullscreenNotification** - Posted before the media player exists fullscreen
 - **APSMediaPlayerDidExitFullscreenNotification** - Posted after the media player exits fullscreen
 - **APSMediaPlayerWasTappedNotification** - Posted when the user taps on the media player surface
 - **APSMediaPlayerControlsDisplayedNotification** - Posted when the video controls bar becomes visible
 - **APSMediaPlayerControlsHiddenNotification** - Posted when the video controls bar becomes hidden
 - **APSMediaPlayerUpdateNotification** - Posted every time the internal status of the media player changes. This will happen roughly once every second.
 - **APSMediaPlayerUnitFinishedNotification** - Posted when a media unit finishes playback, before the remaining playlist units are processed. The `userInfo` dictionary contains the APSMediaUnit object that just finished playback under the `KAPSMediaPlayerCurrentUnit` key.
 - **APSMediaPlayerErrorNotification** - Posted when the media player encounters an error in the process of unit playback. The `userInfo` dictionary contains the NSError object that represents the error under the `kAPSMediaPlayerError` key.
 - **APSMediaPlayerStatusChangedNotification** - Posted when the media player playback state has changed. You can immediately get the new state using the `playbackState` method of the APSMediaPlayer instance.
 - **APSMediaPlayerTrackedEventNotification** - Posted when a trackable playback event occurs.
 The `userinfo` dictionary contains additional information about the tracked event:
 - the `kAPSMediaPlayerEventDescription` key returns a string description of the tracked event
 - the `kAPSMediaPlayerEventType` key returns one of the possible event type constants
 - the `kAPSMediaPlayerEventURLs` key returns an array of NSURLs that were pinged to track the event
 - the `kAPSMediaPlayerCurrentPlaybackTime` key returns the playback time when the event was triggered
 - the `kAPSMediaPlayerCurrentDuration` key returns the total duration of the unit that triggered the event
 - the `kAPSMediaPlayerError` is present in case the event signals an error
 - the `kAPSMediaPlayerSeekStart` is present for `APSMediaPlayerEventSeeked` events and indicates the playback time when the seek started
 - the `kAPSMediaPlayerSeekTo` is present for `APSMediaPlayerEventSeeked` events and indicates the requested playback time to seek to
 - **APSMediaPlayerInvalidLicenseNotification** - Posted when the player license is invalid. Playback will be disabled.
 - **APSMediaPlayerWillOpenMiniBrowser** - Posted when the internal minibrowser will be opened.
 - **APSMediaPlayerWillCloseMiniBrowser** - Posted when the internal minibrowser will be dismissed.
 - **APSMediaPlayerPlaybackDidFinishNotification** - Posted when the internal player backend finished playback. The reason for playback finish in the form of a `APSMovieFinishReason` value can be retrieved from the userInfo dictionary attached to the notification, under the `kAPSMediaPlayerPlaybackDidFinishReason` key.
 - **APSMediaPlayerLoadStateDidChangeNotification** - Posted when the media load state changed. Value can be retrieved from player shared instance.
 - **APSMediaPlayerDurationAvailableNotification** - Posted when the duration of the played media becomes available. Value can be retrieved from player shared instance.
 - **APSMediaPlayerPlaybackStateDidChangeNotification** - Posted when the media playback state changed. Value can be retrieved from player shared instance.
 - **APSMediaPlayerVolumeDidChangeNotification** - Posted when the volume changed. Value can be retrieved from player shared instance.
 
 ## Adapter groups
 
 - *kAPSMediaPlayerOverlayControllersGroup* - The group name that 3rd party overlay controllers must use when registering with the player. See `APSMediaPlayerOverlayControllerProtocol` for more details.
 - *kAPSMediaPlayerUnitManagersGroup* - The group name that 3rd party unit managers must use when registering with the player. See `APSUnitManagerProtocol` for more details.
 - *kAPSMediaPlayerBackendsGroup* - The group name that 3rd party backend renderers must use when registering with the player. See `APSMediaPlayerProtocol` for more details.
 - *kAPSMediaPlayerControlPluginsGroup* - The group name that 3rd party control plugins must use when registering with the player. See `APSControlPluginProtocol` for more details.
 */
@interface APSMediaPlayer : KRHub <UIViewControllerTransitioningDelegate, UIViewControllerAnimatedTransitioning, SFSafariViewControllerDelegate>

/**-----------------------------------------------------------------------------
 * @name Accessing the APSMediaPlayer Instance and its View
 * -----------------------------------------------------------------------------
 */

/**
 *  Returns the shared `APSMediaPlayer` instance, creating it if necessary.
 *
 *  @return The shared `APSMediaPlayer` instance
 */
+ (instancetype _Nonnull )sharedInstance;
/**
 *  List of supported media types
 *
 *  @return An array of supported media types by APSMediaPlayer
 */
+ (NSArray<NSString*> *_Nonnull)supportedMimeTypes;
/**
 *  The container `UIView` of the player.
 */
@property (nonatomic, readonly) UIView *_Nonnull view;
/**
 *  Call this method to set the player view frame.
 *
 *  @param frame `CGRect` player view frame.
 */
- (void)setFrame:(CGRect)frame;

/**
 *  The backend player to use - call this if you are using constants instead of classes. Otherwise, use `backendPlayerClass`.
 */
@property (nonatomic) _Nonnull APSBackendPlayer backendPlayer;

/**
 *  A class which is compliant to `APSMediaPlayerProtocol` and which will be used as a backend player. Use `[APSAVPlayer class]` for the AVPlayer-based backend or `[APSMPMoviePlayer class]` for the MPMoviePlayerController-based backend.
 */
@property (nonatomic, strong) Class _Nonnull backendPlayerClass;
/**
 *  Enable debug logging
 */
@property (nonatomic) BOOL debug;
/**
 *  The user agent that should be used when making HTTP requests.
 */
@property (nonatomic) NSString * _Nullable userAgent;

/**
 * Consent information regarding GDPR and other regulations
 */
@property (nonatomic) APSVASTRegulationInformation * _Nullable regulationInformation;

/**
 *  Set this to NO to disable internal fullscreen handling. Fullscreen functionality should be implemented externally, using the available methods and notifications emitted by the player.
 */
@property (nonatomic) BOOL internalFullscreenSupport;

/**
 *  Set this to NO if you don't want the player to automatically leave fullscreen state after stopping or playing all media units
 */
@property (nonatomic) BOOL leaveFullscreenOnStop;

/**
 *  Enable auto-fullscreen on device orientation
 */
@property (nonatomic) BOOL fullscreenOnLandscapeRotate;

/**
 *  Enable Google's IMA SDK
 */
@property (nonatomic) BOOL preferGoogleIma;

/**
 *  Define allowed orientations for fullscreen mode
 */
@property (nonatomic) APSFullscreenOrientationBehaviour fullscreenOrientationBehaviour;

/**
 *  Overwrite orientations allowed by the app. This is used for fullscreen support. Falls back to settings from the app's plist as well as settings on the root view controller.
 */
@property (nonatomic) UIInterfaceOrientation allowedAppInterfaceOrientation;

/**-----------------------------------------------------------------------------
 * @name Working with Media Units
 * -----------------------------------------------------------------------------
 */
/**
 *  Prepare media units so they can be gapless played (when supported)
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects.
 *
 */
- (void)prepareMediaUnits:(NSArray *_Nonnull)mediaUnits;
/**
 *  Sets and begins playback of an array of media units.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects.
 */
- (void)playMediaUnits:(NSArray *_Nonnull)mediaUnits;
/**
 *  Inserts new media units after the current one, in the current playlist.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to be inserted into the playlist after the current unit.
 */
- (void)insertMediaUnits:(NSArray *_Nonnull)mediaUnits;
/**
 *  Replaces the currently running media unit with multiple other units. Playback of the new units is started automatically.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to be inserted into the playlist instead of the current unit.
 */
- (void)replaceCurrentUnitWithUnits:(NSArray *_Nonnull)mediaUnits;
/**
 *  Sets new units to the playlist, clearing any old ones.
 *
 *  @param mediaUnits An array of `APSMediaUnit` objects to create a new playlist.
 */
- (void)setMediaUnits:(NSArray *_Nonnull)mediaUnits;
/**
 *  Returns the currently playing media unit.
 *
 *  @return An `APSMediaUnit` object representing the current unit.
 */
- (APSMediaUnit *_Nullable)currentUnit;
/**
 *  Sets the video clip URL for the current media unit. The clip is processeed immmediately.
 *
 *  @param url The URL of the video clip.
 */
- (void)setCurrentURL:(NSURL *_Nonnull)url;
/**
 *  Adds additional overlays to display over the current unit.
 *
 *  @param overlays Additional `APSMediaOverlay` objects to inject.
 */
- (void)addOverlays:(NSArray *_Nonnull)overlays;
/**
 *  Adds additional events to the current unit's timeline.
 *
 *  @param overlays Additional `APSMediaEvent` objects to inject.
 */
- (void)addEvents:(NSArray *_Nonnull)events;

/**-----------------------------------------------------------------------------
 * @name Tracking Playback Events
 * -----------------------------------------------------------------------------
 */
/**
 *  This method triggers an `APSMediaPlayerTrackedEventNotification` notification.
 *  @warning Also sends tracking information to one or more servers. All specified URLs will be requested via GET. If the given object is an instance of the `APSMediaUnit` or the `APSMediaOverlay` classes, the `trackingURLs` dictionary property will be searched for the `type` key to identify the URLs that need to be pinged. Alternatively, you can pass a `NSArray`, a `NSURL` or a `NSString` as the object parameter. See "Available Tracking Events" for a list of supported event types.
 *
 *  @param event The APSEvent object containing event info.
 */
- (void)trackEvent:(APSEvent *_Nonnull)event;
/*
*  Old method to track event. This is deprecated now, please use `-trackEvent:(APSEvent *)event`.
*
*  @param event The specific event subtype. May be nil for simple events.
*  @param type  The tracked event type. See "Available Tracking Events".
*  @param object The `APSMediaUnit` or `APSMediaOverlay` instance that generated the notification. Can be nil for non-unit related events.
*  @param metadata Additional key-value pairs to send via the notification's userInfo to subscribers.
*  @param urls An array of `NSURL` objects representing addresses that should be pinged. Also accepts an array of `NSString` objects, a single `NSURL` or a single `NSString`.
*/
- (void)trackEvent:(NSString *_Nonnull)event type:(NSString *_Nonnull)type forObject:(id _Nullable)object metadata:(NSDictionary *_Nullable)metadata urls:(id _Nullable )urls __deprecated_msg("use trackEvent: instead");

/**
 *  This is a wrapper for trackEvent:type:forObject:metadata:urls:
 *
 *  @param event The specific event subtype. May be nil for simple events.
 *  @param type  The tracked event type. See "Available Tracking Events".
 *  @param object The `APSMediaUnit` or `APSMediaOverlay` instance that generated the notification. Can be nil for non-unit related events.
 */
- (void)trackEvent:(NSString *_Nonnull)event type:(NSString *_Nonnull)type forObject:(id _Nullable)object __deprecated_msg("use trackEvent: instead");

/**-----------------------------------------------------------------------------
 * @name URL Handling
 * -----------------------------------------------------------------------------
 */
/**
 *  The player's action delegate. Any intent to execute specific URLs as a result of user interaction will be notified to the delegate for action.
 */
@property (nonatomic, weak) id<APSMediaPlayerActionDelegate> _Nullable actionDelegate;
/**
 *  The view controller that will be used to present any modal views by the player.
 */
@property (nonatomic, weak) UIViewController *_Nullable modalViewControllerRoot;
/**
 *  Instructs the player that a new URL needs to be interpreted and executed. This method will first ask the actionDelegate to respond to the given URL. If the actionDelegate declines to respond and the URL has a web scheme (`http://' or 'https://') then an in-app web browser window will be displayed modally.
 *
 *  @param url The URL that needs to be loaded.
 */
- (void)openURL:(NSURL*_Nonnull)url;
/**
 *  Instructs the player that a new URL needs to be interpreted and executed. This method also specifies the calling overlay controller, as it can define specific behavior for the player upon returning to the foreground after the playback interruption (see `onWebviewDismiss` in `APSMediaPlayerOverlayController.h`).
 *
 *  @param url     The URL that needs to be loaded.
 *  @param overlayController The calling overlay controller.
 */
- (void)openURL:(NSURL*_Nonnull)url from:(APSMediaPlayerOverlayController*_Nullable)overlayController;

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
/**
 *  Interrupts video playback - same as pause, but will not trigger the same events as human interaction would.
 */
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
@property (nonatomic, copy) APSMediaPlayerFinishBlock _Nullable onFinish;

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
 *  Returns the current unit's playback state.
 *
 *  @return The current playback state.
 */
- (APSMoviePlaybackState)playbackState;
/**
 *  Returns the current unit's load state.
 *
 *  @return The current load state.
 */
- (APSMovieLoadState)loadState;
/**
 *  Returns the current unit's movie source type.
 *
 *  @return The movie source type.
 */
- (APSMovieSourceType)movieSourceType;

/**
 *  Returns `YES` if the player is currently rendering a live stream.
 *
 *  @return `YES` if the player is currently rendering a live stream.
 */
- (BOOL)isStreamingLive;

/**
 *  Obtains the most recent time-based metadata provided by the streamed movie.
 *
 *  @return An array of the most recent `MPTimedMetadata` objects provided by the streamed movie. See Apple's [documentation](https://developer.apple.com/library/ios/documentation/mediaplayer/reference/MPTimedMetadata_Class/Reference/Reference.html#//apple_ref/occ/cl/MPTimedMetadata) for_Nullable more details about `MPTimedMetadata`.
 */
- (NSArray*_Nullable)timedMetadata;
/**
 *  Set the sound volume of the player, in the range of 0.0 to 1.0.
 *
 *  @param volume `CGFloat` sound volume.
 */
- (void)setVolume:(CGFloat)volume;
/**
 * Get the sound volume of the player, in the range of 0.0 to 1.0.
 *
 * @return The sound volume of the player
 */
-(CGFloat)getVolume;
/**
 *  Mute the player
 *
 *  @param mute `BOOL` set YES to mute or NO to unmute.
 */
- (void)setMute:(BOOL)mute;
/**
 * Get if the player is muted or no
 *
 * @return The mute status
 */
-(BOOL)getMute;
/**
 *  Get the player's viewability state
 *
 *  @return Player's viewability state
 */
@property (nonatomic, readonly) APSViewability viewability;
/**
 *  Returns a NSDictionary with available subtitles
 *  The dictionary has the form {"language_code" : "Language Name"}
 *
 *  @return A `NSDictionary` with available subtitles
 */
- (NSDictionary *_Nonnull)availableSubtitles;
/**
 *  Enable the corresponding subtitle for the given language
 *
 *  @param language `NSString` the language code to enable
 *
 */
- (void)enableSubtitle:(NSString *_Nonnull)language;
/**
*  Returns a NSDictionary with available audio tracks
*  The dictionary has the form {"track_id" : "Track name"}
*
*  @return A `NSDictionary` with available audio tracks
*/
- (NSDictionary *_Nonnull)availableAudioTracks;
/**
*  Select the corresponding audio track for the given audio track ID
*
*  @param trackId `NSString` the audio track ID to enable
*
*/
- (void) enableAudioTrack:(NSString *_Nonnull)trackId;

/**-----------------------------------------------------------------------------
 * @name Getting Video Thumbnails
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a snapshot image of the current video, at the requested time interval in the playback.
 *
 *  @param playbackTime The time when the thumbnail should be taken from the video.
 *  @param block The block to be invoked on thumbnail generation completion.
 *
 *  @warning This method executes blocking operations on a background thread, and invokes the callback block on the main thread.
 */
- (void) thumbnailAt:(NSTimeInterval) playbackTime withCompletionBlock:(APSThumbnailGeneratedBlock _Nonnull)block;

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
 * @name Handling Picture in Picture
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a Boolean value specifing if Picture in Picture is currently active
 */
- (BOOL) isPictureInPictureActive;
/**
 *  Toggle Picture in Picture mode
 */
- (void) togglePictureInPicture;
/**
 *  Start Picture in Picture mode
 */
- (void) startPictureInPicture;
/**
 *  Stop Picture in Picture mode
 */
- (void) stopPictureInPicture;

/**-----------------------------------------------------------------------------
 * @name Extending
 * -----------------------------------------------------------------------------
 */
/**
 *  Registers a new overlay controller with the player.
 *
 *  @param controllerClass The class of the new overlay controller.
 */
- (void)registerOverlayController:(Class<APSMediaPlayerOverlayControllerProtocol>_Nonnull)controllerClass;
/**
 *  This method instantiates and returns a new object of the class registered for the given overlay type.
 *
 *  @param type The type of controller required.
 *
 *  @return A new object that implements `APSMediaPlayerOverlayControllerProtocol` or `nil` if no controllers are registered for the given type.
 */
- (NSObject<APSMediaPlayerOverlayControllerProtocol>*_Nullable)overlayControllerForType:(NSString*_Nonnull)type;
/**
 *  Registers a new unit manager to dynamically handle media playback.
 *
 *  @param managerClass The new unit manager object.
 */
- (void)registerUnitManager:(NSObject<APSUnitManagerProtocol>*_Nonnull)managerClass;
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
- (void)resetDisplayedOverlays __deprecated_msg("use resetDisplayedOverlays:animated instead.");
/**
 *  Resets all displayed overlays.
 */
- (void)resetDisplayedOverlays:(BOOL)animated;
/**
 *  Returns an array of units owned by an APSVASTAdbreak object
 */
- (NSArray *_Nonnull)unitsForAdbreak:(APSVASTAdBreak *_Nonnull)adbreak;
/*
 *  Returns an array of current unit's adbreaks
 */
- (NSArray *_Nonnull)adbreaks;
/**
 *  Parses a string format and returns a translated time interval in seconds.
 *
 *  @param string The string format to be translated. Must be in the format @"hh:mm:ss".
 *
 *  @return The translated time interval in seconds.
 */
+ (NSTimeInterval)durationFromString:(NSString*_Nonnull)string;
/**
 *  Specifies whether the player should ignore the device silent switch setting.
 */
@property (nonatomic, assign) BOOL ignoreSilentSwitch;
/**
 *  Specifies whether the player should stop functioning if the currently running device is detected to be jailbroken.
 */
@property (nonatomic, assign) BOOL detectBreachedDevice;
/**
 *  Set this to true to continue playing videos while the app is in background
 */
@property (nonatomic) BOOL enableBackgroundPlayback;
/**
 *  Use this property to store the unique device advertising identifier, that can then be used by 3rd party components.
 */
@property (nonatomic) NSString *_Nullable advertisingIdentifier __deprecated_msg("Use APSVASTAdBreak delegate.");

/**
 *  A NSURLSession used for retrieving data from the internet
 */
@property (nonatomic, readonly, nonnull) NSURLSession *urlSession;

/**
 *  Resets the media player backend.
 */
- (void) clear;

@end
