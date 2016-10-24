//
//  APSMediaPlayerSubtitlesOverlayController.h
//  Veeplay
//
//  Created by Ovidiu D. Nitan on 20/10/2016.
//  Copyright © 2016 Appscend. All rights reserved.
//

#import "APSMediaPlayerOverlayController.h"
#define kAPSSubtitlesOverlaySubtitlesURL @"subtitlesURL"
#define kAPSSubtitlesOverlayTextColor @"subtitlesTextColor"
#define kAPSSubtitlesOverlayTextSize @"subtitlesTextSize"
#define kAPSSubtitlesOverlayTextEncoding @"subtitlesTextEncoding"

extern NSString* const APSSubtilesOverlay;

@interface APSMediaPlayerSubtitlesOverlayView : UIView
@end

@interface APSMediaPlayerSubtitlesOverlayController : APSMediaPlayerOverlayController
@property (strong, nonatomic) APSMediaPlayerSubtitlesOverlayView *view;
@end
