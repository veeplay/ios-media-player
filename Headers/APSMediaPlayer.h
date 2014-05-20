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

typedef void (^APSMediaPlayerFinishBlock)();

#define kAPSMediaPlayerOverlayControllersGroup @"com.appscend.mp.controllers.overlay"
#define kAPSMediaPlayerFrameworkExtensionsGroup @"com.appscend.mp.frameworkextensions"

#define kAPSMediaPlayerEventType @"com.appscend.mp.event.type"
#define kAPSMediaPlayerEventDescription @"com.appscend.mp.event.description"
#define kAPSMediaPlayerEventURLs @"com.appscend.mp.event.urls"

extern NSString *const APSMoviePlayerWillEnterFullscreenNotification;
extern NSString *const APSMoviePlayerWillExitFullscreenNotification;
extern NSString *const APSMoviePlayerWasTappedNotification;
extern NSString *const APSMoviePlayerControlsDisplayedNotification;
extern NSString *const APSMoviePlayerControlsHiddenNotification;
extern NSString *const APSMoviePlayerUpdateNotification;
extern NSString *const APSMoviePlayerFinishedNotification;
extern NSString *const APSMoviePlayerErrorNotification;
extern NSString *const APSMoviePlayerStatusChangedNotification;
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

@protocol APSMediaPlayerActionDelegate <NSObject>
- (BOOL)canRespondTo:(NSURL*)url;
- (void)respondTo:(NSURL*)url;
@end

@interface APSMediaPlayer : KRHub <TSMiniWebBrowserDelegate>

@property (nonatomic, readonly) BOOL isProcessing;
@property (nonatomic, readonly) BOOL isFullscreen;
@property (nonatomic, assign) BOOL ignoreSilentSwitch;
@property (nonatomic, copy) APSMediaPlayerFinishBlock onFinish;
@property (nonatomic, readonly) UIView *view;
@property (nonatomic, weak) UIViewController *modalViewControllerRoot;
@property (nonatomic, weak) id<APSMediaPlayerActionDelegate> actionDelegate;

+ (APSMediaPlayer*)sharedInstance;

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
