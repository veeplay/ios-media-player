//
//  APSMediaPlayerVimeoOverlayController.h
//  APSMediaPlayer
//
//  Created by gabi on 26.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSVimeoOverlay;

#define kAPSVimeoURL @"aps_vimeo_url"

__deprecated @interface APSMediaPlayerVimeoOverlayController : APSMediaPlayerOverlayController <UIWebViewDelegate>
@end
