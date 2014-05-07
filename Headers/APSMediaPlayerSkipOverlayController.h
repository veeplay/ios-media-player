//
//  APSMediaPlayerSkipOverlayController.h
//  APSVAST
//
//  Created by gabi on 26.07.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"
#import "KAProgressLabel.h"

typedef enum {
    kAPSSkipOverlayProgressPositionLeft,
    kAPSSkipOverlayProgressPositionRight,
    kAPSSkipOverlayProgressPositionHidden
} APSSkipOverlayProgressPosition;

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

@interface APSMediaPlayerSkipOverlayController : UIViewController <APSMediaPlayerOverlayController> {
    UILabel *_label;
    NSString *_textTemplate;
    KAProgressLabel *_progress;
    int _offset;
    UIButton *_button;
    BOOL _animationStarted;
}

@end
