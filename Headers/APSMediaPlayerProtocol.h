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
#import "APSTypes.h"

/**
 * This protocol allows 3rd party implementations of the media rendering engine that stands behind Veeplay. This protocol extends the `KRAdapter` protocol, so objects should also implement a `type` method, returning a unique string to register under.
 
  To use:
 
  - Create a new class that implements this protocol
  - Register it with the player shared instance:
 
            [[APSMediaPlayer sharedInstance] registerClass:[<YOURCLASS> class] inGroup:kAPSMediaPlayerBackendsGroup];
 
  - Set up the class with the player:
 
            [[APSMediaPlayer sharedInstance] setBackendPlayerClass:[<YOURCLASS> class]];
 */
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
@property (nonatomic) APSMovieScalingMode scalingMode;

/**
 *  Get or set if the player should autoplay an URL as soon as it is provided
 */
@property (nonatomic) BOOL shouldAutoplay;

/**
 *  Get the current playback state
 */
@property (nonatomic, readonly) APSMoviePlaybackState playbackState;

/**
 *  Get the current state of the buffer
 */
@property (nonatomic, readonly) APSMovieLoadState loadState;

/**
 *  Get the current media's source type (e.g. file or stream)
 */
@property (nonatomic) APSMovieSourceType movieSourceType;

/**
 *  Set or get how the player controls will appear
 */
@property (nonatomic) APSMovieControlStyle controlStyle;

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
 *  @return The stream's type as a `APSMovieStreamSourceType` enum
 *
 */
- (APSMovieStreamSourceType) streamSourceType;

/**
 *  Request a thumbnail image
 *
 *  @param playbackTime The time when the thumbnail should be taken from the video.
 *  @param block The block to be invoked on thumbnail generation completion.
 *
 *  @warning This method should execute blocking operations on a background thread, and should invoke the callback block on the main thread.
 */
- (void) thumbnailAt:(NSTimeInterval) playbackTime withCompletionBlock:(APSThumbnailGeneratedBlock)block;

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

-(BOOL)needsInitialPlaybackTimeDispatch;


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

/**
 *  This is invoked by the player before setting a new URL for playback
 *
 *  @param url A NSURL instance pointing to the media location
 *
 */
- (void) willSetURL:(NSURL*)url;

/**
 *  This is invoked by the player after setting a new URL for playback
 *
 *  @param url A NSURL instance pointing to the media location
 *
 */
- (void) didSetURL:(NSURL*)url;

/**
 *  This is invoked by the player after playback is complete
 */
- (void) clear;

@end
