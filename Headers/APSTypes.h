//
//  APSTypes.h
//  Veeplay
//
//  Created by gabi on 28.01.2016.
//  Copyright © 2016 Appscend. All rights reserved.
//

#ifndef APSTypes_h
#define APSTypes_h

typedef NS_ENUM(NSInteger, APSMoviePlayerSourceType) {
    APSMoviePlayerSourceTypeOnDemand,
    APSMoviePlayerSourceTypeLive
};

typedef NS_ENUM(NSInteger, APSMoviePlaybackState) {
    APSMoviePlaybackStateStopped,
    APSMoviePlaybackStatePlaying,
    APSMoviePlaybackStatePaused,
    APSMoviePlaybackStateInterrupted,
    APSMoviePlaybackStateSeekingForward,
    APSMoviePlaybackStateSeekingBackward
};

typedef NS_OPTIONS(NSUInteger, APSMovieLoadState) {
    APSMovieLoadStateUnknown        = 0,
    APSMovieLoadStatePlayable       = 1 << 0,
    APSMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    APSMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

typedef NS_ENUM(NSInteger, APSMovieSourceType) {
    APSMovieSourceTypeUnknown,
    APSMovieSourceTypeFile,     // Local or progressively downloaded network content
    APSMovieSourceTypeStreaming // Live or on-demand streaming content
};

typedef NS_ENUM(NSInteger, APSMovieControlStyle) {
    APSMovieControlStyleNone,       // No controls
    APSMovieControlStyleEmbedded,   // Controls for an embedded view
    APSMovieControlStyleFullscreen, // Controls for fullscreen playback
    
    APSMovieControlStyleDefault = APSMovieControlStyleEmbedded
};

typedef NS_ENUM(NSInteger, APSMovieScalingMode) {
    APSMovieScalingModeNone,       // No scaling
    APSMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    APSMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    APSMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};

typedef NS_ENUM(NSInteger, APSMovieFinishReason) {
    APSMovieFinishReasonPlaybackEnded,
    APSMovieFinishReasonPlaybackError,
    APSMovieFinishReasonUserExited
};

typedef void (^APSThumbnailGeneratedBlock)(UIImage *thumbnail);

#endif /* APSTypes_h */
