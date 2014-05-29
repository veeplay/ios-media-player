//
//  APSMediaPlayerSkipOverlayController.h
//  APSVAST
//
//  Created by gabi on 26.07.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

/**
 *  Defines where inside the skip overlay should the progress circle be rendered.
 */
typedef NS_ENUM(NSInteger, APSSkipOverlayProgressPosition) {
    /**
     *  Render the progress circle in the left side of the skip overlay.
     */
    kAPSSkipOverlayProgressPositionLeft,
    /**
     *  Render the progress circle in the right side of the skip overlay.
     */
    kAPSSkipOverlayProgressPositionRight,
    /**
     *  Do not render the progress circle.
     */
    kAPSSkipOverlayProgressPositionHidden
};

extern NSString* const APSSkipOverlay;
#define kAPSSkipOverlayOffset @"aps_skip_offset"
#define kAPSSkipOverlayString @"aps_skip_text"
#define kAPSSkipOverlayStringColor @"aps_skip_textcolor"
#define kAPSSkipOverlayProgressPosition @"aps_skip_progressposition"
#define kAPSSkipOverlayProgressStringColor @"aps_skip_progressstringcolor"
#define kAPSSkipOverlayProgressColor @"aps_skip_progresscolor"
#define kAPSSkipOverlayProgressTrackColor @"aps_skip_progresstrackcolor"
#define kAPSSkipOverlayPadding @"aps_skip_padding"
#define kAPSSkipOverlayBorderColor @"aps_skip_bordercolor"
#define kAPSSkipOverlayBorderRadius @"aps_skip_borderradius"
#define kAPSSkipOverlayColor @"aps_skip_color"

@interface APSVASTSkipOverlayController : UIViewController <APSMediaPlayerOverlayController>
@end
