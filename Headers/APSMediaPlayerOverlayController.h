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

@protocol APSMediaPlayerOverlayController <KRAdapter>

- (void)startWithParameters:(id)parameters;

@optional
- (void)update;
- (void)overlayWillBeRemoved;

- (NSTimeInterval)currentPlaybackTime;
- (NSTimeInterval)playableDuration;
- (void)setCurrentPlaybackTime:(NSTimeInterval)playbackTime;
- (UIImage*)thumbnailImageAtTime:(NSTimeInterval)time;
- (NSTimeInterval)duration;
- (MPMoviePlaybackState)playbackState;
- (MPMovieLoadState)loadState;
- (MPMovieSourceType)movieSourceType;
- (void)play;
- (void)stop;
- (void)pause;
- (void)setParentOverlay:(APSMediaOverlay*)overlay;
- (void)fullscreenToggled;
- (void)cleanup;
@end
