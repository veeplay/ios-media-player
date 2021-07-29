//
//  APSAVPlayer.h
//  APSVAST
//
//  Created by Ovidiu on 04/02/15.
//  Copyright (c) 2015 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KRAdapter.h"
#import "APSMediaPlayerProtocol.h"

/** The `APSAVPlayer` is a media backend renderer that handles playback via the native `AVPlayer` classes. See `APSMediaPlayerProtocol` for more details.
 
 To use, set up with the player shared instance:
 
        [sharedInstance setBackendPlayerClass:[APSAVPlayer class]];
 
 */
@interface APSAVPlayer : NSObject <MPMediaPlayback, APSMediaPlayerProtocol, KRAdapter>

@end
