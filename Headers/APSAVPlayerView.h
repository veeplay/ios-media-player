//
//  APSMoviePlayerView.h
//  CustomMoviePlayer
//
//  Created by Ovidiu on 04/02/15.
//  Copyright (c) 2015 Ovidiu. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AVPlayer;

@interface APSAVPlayerView : UIView

/**-----------------------------------------------------------------------------
 * @name Setting and getting AVPlayer instance
 * -----------------------------------------------------------------------------
 */
/**
 *  Get the AVPlayer instance associated with the current view.
 */
- (AVPlayer *_Nullable)player;

/**
 *  Set an AVPlayer instance to the current view.
 *
 *  @param player An AVPlayer instance
 *
 */
- (void)setPlayer:(AVPlayer *_Nullable)player;

@end
