//
//  APSMediaPlayerImageOverlayController.h
//  APSVAST
//
//  Created by gabi on 24.07.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"
#import "APSMediaPlayerClosableOverlayController.h"

extern NSString *_Nonnull const APSImageOverlay;
#define kAPSImageOverlayClickthrough @"clickThrough"
#define kAPSImageOverlayClicktracking @"clickTracking"
#define kAPSImageOverlayViewtracking @"viewTracking"
#define kAPSImageOverlayResourceURL @"url"
#define kAPSImageOverlayErrorURLs @"errorTracking"
#define kAPSImageOverlayBackgroundColor @"backgroundColor"
#define kAPSImageOverlayStretchMode @"stretchMode"
#define kAPSImageOverlayWebviewDismissAction @"dismissAction"

/**
 The `APSMediaPlayerImageOverlayController` allows placing an image on top of video content.
 
 ## Configuration
 
 To create an `APSMediaOverlay` of image type:
 
 - set the overlay object's `type` property to `APSImageOverlay`
 - set the overlay object's `properties` property to a `NSDictionary` that can have the following keys and values:
 
     - *kAPSImageOverlayClickthrough*: set this key to a `NSURL` reprezenting the URL that should be launched when the overlay is tapped.
     - *kAPSImageOverlayClicktracking*: set this key to a `NSArray` of `NSURL` objects that will be tracked by the player when the overlay is tapped (see `[APSMediaPlayer track:forEvent:type:]`). Note that the `kAPSImageOverlayClickthrough` key must also be set for tracking to happen.
     - *kAPSImageOverlayWebviewDismissAction*: set this key to a NSNumber created from the `APSWebviewDismissedAction` value that defines the expected playlist behavior on in-app web browser dismiss.
     - *kAPSImageOverlayViewtracking*: set this key to a `NSArray` of `NSURL` objects that will be tracked by the player when the overlay is displayed (see `[APSMediaPlayer track:forEvent:type:]`).
     - *kAPSImageOverlayResourceURL*: `NSURL` reprezenting the image to be loaded.
     - *kAPSImageOverlayErrorURLs*: set this key to a `NSArray` of `NSURL` objects that will be tracked by the player when there is an error loading the image (see `[APSMediaPlayer track:forEvent:type:]`).
     - *kAPSImageOverlayBackgroundColor*: the background color of the overlay. Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
     - *kAPSImageOverlayStretchMode*: `NSString` reprezenting the possible ways of scaling the image in the overlay surface. Possible values are:
 
        - "aspectFit", that will set the overlay's `contentMode` to `UIViewContentModeScaleAspectFit`
        - "aspectFill", that will set the overlay's `contentMode` to `UIViewContentModeScaleAspectFill`
        - "fill", that will set the overlay's `contentMode` to `UIViewContentModeScaleToFill`
        - "center", that will set the overlay's `contentMode` to `UIViewContentModeCenter`
        - "bottom", that will set the overlay's `contentMode` to `UIViewContentModeTop`
        - "top", that will set the overlay's `contentMode` to `UIViewContentModeBottom`
        - "left", that will set the overlay's `contentMode` to `UIViewContentModeLeft`
        - "right", that will set the overlay's `contentMode` to `UIViewContentModeRight`
 */
@interface APSMediaPlayerImageOverlayController : APSMediaPlayerClosableOverlayController
@end
