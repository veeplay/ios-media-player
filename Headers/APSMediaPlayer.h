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

@protocol APSMediaPlayerActionDelegate <NSObject>
- (BOOL)canRespondTo:(NSURL*)url;
- (void)respondTo:(NSURL*)url;
@end

/**
 * The block to be executed when the current playlist is completed
 * @since v1.7
 */
typedef void (^APSMediaPlayerFinishBlock)();



/**
 *  The APSMediaPlayer handles playback and rendering of APSMediaUnits and APSMediaOverlays.
 */
@interface APSMediaPlayer : KRHub <TSMiniWebBrowserDelegate>

/**
 *  Returns YES if the player is currently rendering a playlist of units. Returns NO if the player is currently idle.
 */
@property (nonatomic, readonly) BOOL isProcessing;


@property (nonatomic, readonly) BOOL isFullscreen;
@property (nonatomic, assign) BOOL ignoreSilentSwitch;
@property (nonatomic, copy) APSMediaPlayerFinishBlock onFinish;
@property (nonatomic, readonly) UIView *view;
@property (nonatomic, weak) UIViewController *modalViewControllerRoot;
@property (nonatomic, weak) id<APSMediaPlayerActionDelegate> actionDelegate;

/**-----------------------------------------------------------------------------
 * @name Accessing the Shared APSMediaPlayer Instance
 * -----------------------------------------------------------------------------
 */

/**
 *  Returns the shared `APSMediaPlayer` instance, creating it if necessary
 *
 *  @return The shared `APSMediaPlayer` instance
 */
+ (instancetype)sharedInstance;

- (void)playMediaUnits:(NSArray*)mediaUnits;
- (void)insertMediaUnits:(NSArray*)mediaUnits;
- (void)replaceCurrentUnitWithUnits:(NSArray*)mediaUnits;
- (void)setMediaUnits:(NSArray*)mediaUnits;
- (APSMediaUnit*)currentUnit;
- (void)resetPlayer;

- (void)track:(NSArray*)urls forEvent:(NSString*)event type:(NSString*)type;

- (void)openURL:(NSURL*)url;
- (void)openURL:(NSURL*)url from:(UIViewController<APSMediaPlayerOverlayController>*)overlay;

- (void)skip;
- (void)next;
- (void)previous;
- (void)pause;
- (void)play;
- (void)stop;
- (void)setCurrentURL:(NSURL*)url;
- (NSTimeInterval)currentPlaybackTime;
- (void)setCurrentPlaybackTime:(NSTimeInterval)playbackTime;
- (NSTimeInterval)duration;
- (NSTimeInterval)playableDuration;
- (MPMoviePlaybackState)playbackState;
- (MPMovieLoadState)loadState;
- (MPMovieSourceType)movieSourceType;
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)time;
- (void)showActivityIndicator;
- (void)hideActivityIndicator;
+ (NSTimeInterval)durationFromString:(NSString*)string;
- (void)clearWithReason:(MPMovieFinishReason)finishReason continue:(BOOL)shouldContinue skipped:(BOOL)skipped error:(NSError*)error;

- (void)resetDisplayedOverlays;
- (void)toggleFullscreen;

@end

#define kAPSMediaPlayerOverlayControllersGroup @"com.appscend.mp.controllers.overlay"
#define kAPSMediaPlayerFrameworkExtensionsGroup @"com.appscend.mp.frameworkextensions"

#define kAPSMediaPlayerEventType @"com.appscend.mp.event.type"
#define kAPSMediaPlayerEventDescription @"com.appscend.mp.event.description"
#define kAPSMediaPlayerEventURLs @"com.appscend.mp.event.urls"

///--------------------
/// @name Notifications
///--------------------

/**
 *  Posted before the media player enters fullscreen
 */
extern NSString *const APSMoviePlayerWillEnterFullscreenNotification;
/**
 *  Posted before the media player exists fullscreen
 */
extern NSString *const APSMoviePlayerWillExitFullscreenNotification;
/**
 *  Posted when the user taps on the media player surface
 */
extern NSString *const APSMoviePlayerWasTappedNotification;
/**
 *  Posted when the video controls bar becomes visible
 */
extern NSString *const APSMoviePlayerControlsDisplayedNotification;
/**
 *  Posted when the video controls bar becomes hidden
 */
extern NSString *const APSMoviePlayerControlsHiddenNotification;
/**
 *  Posted every time the internal status of the media player changes. This will happen roughly once every second.
 */
extern NSString *const APSMoviePlayerUpdateNotification;
/**
 *  Posted when a media unit finishes playback, before the remaining playlist units are processed. The `userInfo` dictionary contains the APSMediaUnit object that just finished playback under the `unit` key.
 */
extern NSString *const APSMoviePlayerUnitFinishedNotification;
/**
 *  Posted when the media player encounters an error in the process of unit playback. The `userInfo` dictionary contains the NSError object that represents the error under the `error` key.
 */
extern NSString *const APSMoviePlayerErrorNotification;
/**
 *  Posted when the media player playback state has changed. You can immediately get the new state using the `playbackState` method of the APSMediaPlayer instance. See Apple's documentation on MPMoviePlaybackState for more details about the available playback states (https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMoviePlaybackState).
 */
extern NSString *const APSMoviePlayerStatusChangedNotification;
/**
 *  Posted when a trackable playback event occurs.
 *  The `userinfo` dictionary contains additional information about the tracked event:
 *  - the `kAPSMediaPlayerEventDescription` key returns a string description of the tracked event
 *  - the `kAPSMediaPlayerEventType` key returns one of the possible event type constants
 *  - the `kAPSMediaPlayerEventURLs` key returns an array of NSURLs that were pinged to track the event
 */
extern NSString *const APSMoviePlayerTrackedEventNotification;

extern NSString *const APSMoviePlayerEventLaunch;
extern NSString *const APSMoviePlayerEventFinish;
extern NSString *const APSMoviePlayerEventExitFullscreen;
extern NSString *const APSMoviePlayerEventFullscreen;
extern NSString *const APSMoviePlayerEventImpression;
extern NSString *const APSMoviePlayerEventCreativeView;
extern NSString *const APSMoviePlayerEventResume;
extern NSString *const APSMoviePlayerEventPause;
extern NSString *const APSMoviePlayerEventRewind;
extern NSString *const APSMoviePlayerEventMute;
extern NSString *const APSMoviePlayerEventUnmute;
extern NSString *const APSMoviePlayerEventError;
extern NSString *const APSMoviePlayerEventComplete;
extern NSString *const APSMoviePlayerEventClose;
extern NSString *const APSMoviePlayerEventCloseLinear;
extern NSString *const APSMoviePlayerEventSkip;
extern NSString *const APSMoviePlayerEventClick;
extern NSString *const APSMoviePlayerEventIconView;
extern NSString *const APSMoviePlayerEventExpand;
extern NSString *const APSMoviePlayerEventCollapse;