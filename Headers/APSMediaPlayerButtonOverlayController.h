//
//  APSMediaPlayerButtonOverlayController.h
//  APSVAST
//
//  Created by Appscend on 7/22/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSButtonOverlay;
#define kAPSButtonOverlayClickthrough @"clickThrough"
#define kAPSButtonOverlayClicktracking @"clickTracking"
#define kAPSButtonOverlayWebviewDismissAction @"dismissAction"

/**
 The `APSMediaPlayerButtonOverlayController` allows placing a transparent overlay in a specific area of the player surface, that can trigger the launch of a specific URL. The `APSMediaPlayer` instance will query the `actionDelegate` object to interpret and launch the specified URL. If the `actionDelegate` cannot respond to the URL, and the URL has a web scheme (http or https), it will be launched automatically in the in-app web browser.
 
 ## Configuration
 
 To create an `APSMediaOverlay` of button type:
 
 - set the overlay object's `type` property to `APSButtonOverlay`
 - set the overlay object's `properties` property to a `NSDictionary` that can have the following keys and values:
 
     - *kAPSButtonOverlayClickthrough*: set this key to a `NSURL` reprezenting the URL that should be launched when the overlay is tapped.
     - *kAPSButtonOverlayClicktracking*: set this key to a `NSArray` of `NSURL` objects that will be tracked by the player when the overlay is tapped (see `[APSMediaPlayer track:forEvent:type:]`). Note that the `kAPSButtonOverlayClickthrough` key must also be set for tracking to happen
     - *kAPSButtonOverlayWebviewDismissAction*: set this key to a NSNumber created from the `APSWebviewDismissedAction` value that defines the expected playlist behavior on in-app web browser dismiss.
 */
@interface APSMediaPlayerButtonOverlayController : APSMediaPlayerOverlayController
@end
