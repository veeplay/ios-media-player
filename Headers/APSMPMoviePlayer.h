//
//  APSMPMoviePlayer.h
//  APSVAST
//
//  Created by Ovidiu on 10/02/15.
//  Copyright (c) 2015 Appscend. All rights reserved.
//

#import <MediaPlayer/MediaPlayer.h>
#import "APSMediaPlayerProtocol.h"
#import "KRAdapter.h"

@interface APSMPMoviePlayer : MPMoviePlayerController <APSMediaPlayerProtocol, KRAdapter>

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
/**
 *  The priority based on which the backend will be selected
 */
+ (NSInteger) backendPriority;

@end
