//
//  APSPiPPlayer.h
//  Veeplay
//
//  Created by Ovidiu on 05/02/16.
//  Copyright © 2016 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <AVKit/AVKit.h>
#import "KRAdapter.h"
#import "APSMediaPlayerProtocol.h"
#import "AVPlayer+View.h"

@interface APSPiPPlayer : NSObject <MPMediaPlayback, APSMediaPlayerProtocol, AVPictureInPictureControllerDelegate, KRAdapter>

/**-----------------------------------------------------------------------------
 * @name Accessing the APSAVPlayer's view
 * -----------------------------------------------------------------------------
 */

/**
 *  The container `UIView` of the player.
 */
@property (nonatomic, strong) UIView *view;

/**-----------------------------------------------------------------------------
 * @name Properties
 * -----------------------------------------------------------------------------
 */

/**
 *  Returns a Boolean value specifing if the player is ready to play media
 */
@property (nonatomic, readonly) BOOL isPreparedToPlay;

/**
 *  Get or set the initial time in stream from which the player will start playing the media
 */
@property (nonatomic) NSTimeInterval initialPlaybackTime;

/**
 *  Get or set the current position in stream
 */
@property (nonatomic) NSTimeInterval currentPlaybackTime;

/**
 *  Get the duration of the buffered content
 */
@property (nonatomic, readonly) NSTimeInterval playableDuration;

/**
 *  Get the total duration of the video
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 *  Get or set the current playback rate
 */
@property (nonatomic) float currentPlaybackRate;

/**
 *  Get or set the current media's URL
 */
@property (nonatomic, strong) NSURL *contentURL;

/**
 *  Get or set the scaling mode of the video according to its viewport
 */
@property (nonatomic) MPMovieScalingMode scalingMode;

/**
 *  Get or set if the player should autoplay an URL as soon as it is provided
 */
@property (nonatomic) BOOL shouldAutoplay;

/**
 *  Get the current playback state
 */
@property (nonatomic, readonly) MPMoviePlaybackState playbackState;

/**
 *  Get the current state of the buffer
 */
@property (nonatomic, readonly) MPMovieLoadState loadState;

/**
 *  Get the current media's source type (e.g. file or stream)
 */
@property (nonatomic) MPMovieSourceType movieSourceType;

/**
 *  Set how the player controls will appear
 */
@property (nonatomic) MPMovieControlStyle controlStyle;

/**
 *  Obtains the most recent time-based metadata provided by the streamed movie.
 *
 *  Returns an array of the most recent MPTimedMetadata objects provided by the media stream.
 */
@property (nonatomic, readonly) NSArray *timedMetadata;


/**
 *  Specifies whether the movie player allows AirPlay movie playback.
 */
@property(nonatomic) BOOL allowsAirPlay;


/**
 *  Check out if AirPlay video is started or stopped.
 */
@property(nonatomic, readonly) BOOL airPlayVideoActive;

@end
