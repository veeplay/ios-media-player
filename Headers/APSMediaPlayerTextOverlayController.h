//
//  APSMediaPlayerTextOverlayController.h
//  APSVAST
//
//  Created by Appscend on 7/23/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSTextOverlay;
#define kAPSTextOverlayString @"text"
#define kAPSTextOverlayStringColor @"color"
#define kAPSTextOverlayStringFont @"font"
#define kAPSTextOverlayStringSize @"size"

/**
 The `APSMediaPlayerTextOverlayController` allows the displaying of text on top of video content.
 
 ## Configuration
 
 To create an `APSMediaOverlay` of text type:
 
 - set the overlay object's `type` property to `APSTextOverlay`
 - set the overlay object's `parameters` property to a `NSDictionary` that can have the following keys and values:
 
    - *kAPSTextOverlayString*: the `NSString` to be rendered.
    - *kAPSTextOverlayStringColor*: Font color for the rendered text. Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor whiteColor]`.
    - *kAPSTextOverlayStringFont*: `NSString` indicating the font family to be used. Defaults to @"Helvetica".
    - *kAPSTextOverlayStringSize*: `NSNumber` indicating the font size to be used. Defaults to 13.
 
 ## Replacable Placeholders
 
 The `APSMediaPlayerTextOverlayController` will replace the following string placeholders with dynamic information:
 
 - *`__remaining__`* will be replaced with the remaining number of seconds for the current video clip being rendered.
 - *`__ad_index__`* will be replaced with the current ad index within the ad break.
 - *`__total_ads__`* will be replaced with the total number of ads within the ad break.
 */
@interface APSMediaPlayerTextOverlayController : APSMediaPlayerOverlayController
@end
