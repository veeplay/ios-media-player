//
//  APSTypes.h
//  Veeplay
//
//  Created by gabi on 28.01.2016.
//  Copyright © 2016 Appscend. All rights reserved.
//

#ifndef APSTypes_h
#define APSTypes_h

/** If the movie source type is a stream, this identifies the type of stream (on-demand or live)
 */
typedef NS_ENUM(NSInteger, APSMovieStreamSourceType) {
    /** On-demand stream, has start and end */
    APSMoviePlayerSourceTypeOnDemand,
    /** Live stream, doesn't have a start or end */
    APSMoviePlayerSourceTypeLive
};

/** The different playback states the player can be in 
 */
typedef NS_ENUM(NSInteger, APSMoviePlaybackState) {
    /** Media stopped */
    APSMoviePlaybackStateStopped,
    /** Media playing */
    APSMoviePlaybackStatePlaying,
    /** Media paused */
    APSMoviePlaybackStatePaused,
    /** Media interrupted - streaming error, buffering issue */
    APSMoviePlaybackStateInterrupted,
    /** Seeking forward */
    APSMoviePlaybackStateSeekingForward,
    /** Seeking backward */
    APSMoviePlaybackStateSeekingBackward
};

/** The different load states any media can have during its lifetime
 */
typedef NS_OPTIONS(NSUInteger, APSMovieLoadState) {
    /** Unknown, initial load state */
    APSMovieLoadStateUnknown        = 0,
    /** The media is now playable - enough content has buffered */
    APSMovieLoadStatePlayable       = 1 << 0,
    /** The media is now completely playable - all content has been buffered */
    APSMovieLoadStatePlaythroughOK  = 1 << 1,
    /** Playback is stalled - streaming error, buffering issue. Media will automatically pause */
    APSMovieLoadStateStalled        = 1 << 2
};

/** The different movie source types available
 */
typedef NS_ENUM(NSInteger, APSMovieSourceType) {
    /** Unknown media source type */
    APSMovieSourceTypeUnknown,
    /** Local or progressively downloaded network content */
    APSMovieSourceTypeFile,
    /** Live or on-demand streaming content */
    APSMovieSourceTypeStreaming
};

/** Types of native controls that some backend renderers can use. These are provided by the OS, and are separate from the controls bar provided by the library. */
typedef NS_ENUM(NSInteger, APSMovieControlStyle) {
    /** No controls */
    APSMovieControlStyleNone,
    /** Controls for an embedded view */
    APSMovieControlStyleEmbedded,
    /** Controls for fullscreen playback */
    APSMovieControlStyleFullscreen,
    APSMovieControlStyleDefault = APSMovieControlStyleNone
};

/** Types of possible media scaling modes 
 */
typedef NS_ENUM(NSInteger, APSMovieScalingMode) {
    /** No scaling */
    APSMovieScalingModeNone,
    /** Uniform scale until one dimension fits */
    APSMovieScalingModeAspectFit,
    /** Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents */
    APSMovieScalingModeAspectFill,
    /** Non-uniform scale. Both render dimensions will exactly match the visible bounds */
    APSMovieScalingModeFill
};

/** Types of possible media playback finish reasons */
typedef NS_ENUM(NSInteger, APSMovieFinishReason) {
    /** Playback reached end of media */
    APSMovieFinishReasonPlaybackEnded,
    /** There was an error playing the media */
    APSMovieFinishReasonPlaybackError,
    /** Playback was ended by user action */
    APSMovieFinishReasonUserExited
};

/** Possible settings for fullscreen orientation handling */
typedef NS_ENUM(NSInteger, APSFullscreenOrientationBehaviour) {
    /** Default fullscreen orientation - matches phone orientation, according to user and app level settings */
    APSDefaultOrientation,
    /** Force portrait orientation for videos in fullscreen mode */
    APSForcePortrait,
    /** Force landscape orientation for videos in fullscreen mode */
    APSForceLandscape
};

/** A block that is used by the thumbnail generation methods to asynchronously return an image */
typedef void (^APSThumbnailGeneratedBlock)(UIImage *_Nullable thumbnail);

#endif /* APSTypes_h */
