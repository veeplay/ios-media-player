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

/** The `APSMPMoviePlayer` is a media backend renderer that handles playback via the native `MPMoviePlayer` classes. See `APSMediaPlayerProtocol` for more details.
 
 To use, set up with the player shared instance:
 
 [sharedInstance setBackendPlayerClass:[APSMPMoviePlayer class]];
 
 */
@interface APSMPMoviePlayer : MPMoviePlayerController <APSMediaPlayerProtocol, KRAdapter>

@end
