//
//  APSTimedMetadata.h
//  Veeplay
//
//  Created by Ovidiu on 18/02/15.
//  Copyright (c) 2015 Appscend. All rights reserved.
//

#import <MediaPlayer/MediaPlayer.h>
#import <AVFoundation/AVFoundation.h>
/**
 This class encapsulates timed metadata information retrieved from the video stream. See `[APSMediaPlayer timedMetadata]`.
 */
@interface APSTimedMetadata : MPTimedMetadata

/**-----------------------------------------------------------------------------
 * @name APSTimedMetadata initialization
 * -----------------------------------------------------------------------------
 */

/**
 *  Create and return a new APSTimedMetadata instance based on an AVMetadataItem
 *
 *  @param item An AVMetadataItem instance
 *
 */
- (id) initWithMetadataItem:(AVMetadataItem*)item;

@end
