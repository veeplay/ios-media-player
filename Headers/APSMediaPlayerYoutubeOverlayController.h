//
//  APSMediaPlayerYoutubeOverlayController.h
//  APSMediaPlayer
//
//  Created by gabi on 26.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSYoutubeOverlay;

#define kAPSYoutubeURL @"aps_youtube_url"

__deprecated @interface APSMediaPlayerYoutubeOverlayController : APSMediaPlayerOverlayController <UIWebViewDelegate>
@end
