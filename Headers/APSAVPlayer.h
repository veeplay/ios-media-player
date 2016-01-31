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
#import "APSAVPlayerView.h"
#import "AVPlayer+View.h"
#import "APSMediaPlayerProtocol.h"


@interface APSAVPlayer : NSObject <MPMediaPlayback, APSMediaPlayerProtocol, KRAdapter>

@end
