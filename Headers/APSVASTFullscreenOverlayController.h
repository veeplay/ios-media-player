//
//  APSVASTFullscreenOverlayController.h
//  Veeplay
//
//  Created by Ovidiu on 16/04/15.
//  Copyright (c) 2015 Veeplay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

extern NSString* const APSFullscreenOverlay;
#define kAPSFullscreenOverlayPadding @"aps_fullscreen_padding"
#define kAPSFullscreenOverlayBorderColor @"aps_fullscreen_bordercolor"
#define kAPSFullscreenOverlayBorderRadius @"aps_fullscreen_borderradius"
#define kAPSFullscreenOverlayColor @"aps_fullscreen_color"
#define kAPSFullscreenOverlayEnterFullscreenIcon @"aps_fullscreen_enter_icon"
#define kAPSFullscreenOverlayLeaveFullscreenIcon @"aps_fullscreen_leave_icon"

@interface APSVASTFullscreenOverlayController : APSMediaPlayerOverlayController

@end
