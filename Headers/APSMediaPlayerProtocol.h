//
//  APSMediaPlayerProtocol.h
//  APSVAST
//
//  Created by Ovidiu on 10/02/15.
//  Copyright (c) 2015 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>

typedef NS_ENUM(NSInteger, APSMoviePlayerSourceType) {
    APSMoviePlayerSourceTypeOnDemand,
    APSMoviePlayerSourceTypeLive
};

typedef NS_ENUM(NSInteger, APSAVPlayerSeekStatus) {
    APSAVPlayerSeekStatusNoSeeking,
    APSAVPlayerSeekStatusBackward,
    APSAVPlayerSeekStatusForward
};

@protocol APSMediaPlayerProtocol <NSObject>

@required
/**-----------------------------------------------------------------------------
 * @name Accessing the APSAVPlayer's view
 * -----------------------------------------------------------------------------
 */

/**
 *  The container `UIView` of the player.
 */
@property (nonatomic, readonly) UIView *view;

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
 *  Set or get how the player controls will appear
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


/**-----------------------------------------------------------------------------
 * @name Required protocol methods
 * -----------------------------------------------------------------------------
 */

/**
 *  Create a APSAVPlayer instance
 *
 *  @param urls A NSArray of NSURLs pointing to the media location
 *
 *  @return The `APSAVPlayer` instance
 */
- (id) initWithURLs:(NSArray *) urls;

/**
 *  Prepare to play media. This is also automatically called on play
 */
- (void) prepareToPlay;

/**
 *  Play the current media in the queue
 */
- (void) play;

/**
 *  Pause the current playing media
 */
- (void) pause;

/**
 *  Stop the player, remove all the items from the queue and remove the player's CALayer from its superlayer
 */
- (void) stop;

/**
 *  Play the media with an increased playback rate (speed)
 */
- (void)beginSeekingForward;

/**
 *  Rewind the media
 */
- (void)beginSeekingBackward;

/**
 *  Stop the seeking process startd by beginSeekingForward or beginSeekingBackward;
 */
- (void)endSeeking;

/**
 *  Get the stream's source type. Different by movieSourceType because it returns if the stream is
 *  a VOD stream or a live stream.
 *
 *  @return The stream's type as a `APSMoviePlayerSourceType` enum
 *
 */
- (APSMoviePlayerSourceType) streamSourceType;

/**
 *  Request a thumbnail image
 *
 *  @param playbackTime The time, in seconds, when the thumbnail should be taken from the video
 *
 *  @return The thumbnail image
 *
 */
- (UIImage *) thumbnailAt:(NSTimeInterval) playbackTime;

/**
 *  Request a thumbnail image
 *
 *  @param playbackTime The time, in seconds, when the thumbnail should be taken from the video
 *
 *  @param option Precision
 *
 *  @return The thumbnail image
 *
 */
- (UIImage *)thumbnailImageAtTime:(NSTimeInterval)playbackTime timeOption:(MPMovieTimeOption)option;

/**
 *  Request a thumbnail image
 *
 *  @param playbackTimes A NSArray of NSTimeInterval, in seconds, when the thumbnail should be taken from the video
 *
 *  @param option Precision
 *
 *  @return The thumbnail image
 *
 */
- (void)requestThumbnailImagesAtTimes:(NSArray *)playbackTimes timeOption:(MPMovieTimeOption)option;


@optional
/**-----------------------------------------------------------------------------
 * @name Optional protocol methods
 * -----------------------------------------------------------------------------
 */


/**
 *  Add an URL to the current play queue
 *
 *  @param url A NSURL instance pointing to the media location
 *
 */
- (void) appendURL:(NSURL *)url;

/**
 *  Insert an URL to the current play queue at the given position
 *
 *  @param url A NSURL instance pointing to the media location
 *
 *  @param index
 *
 */
- (void) insertURL:(NSURL *)url atIndex:(NSInteger)index;

/**
 *  The priority based on which the backend will be selected
 */
+ (NSInteger) backendPriority;

@end
