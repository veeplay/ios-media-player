//
//  APSMediaPlayerClosableOverlayController.h
//  APSMediaPlayer
//
//  Created by gabi on 03.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"
@class KAProgressLabel;

#define kAPSCloseImage @"aps_cls_image"
#define kAPSCloseSize @"aps_cls_size"
#define kAPSCloseBackgroundColor @"aps_cls_backcolor"
#define kAPSCloseXColor @"aps_cls_xcolor"
#define kAPSCloseProgressColor @"aps_cls_pcolor"
#define kAPSCloseProgressTrackColor @"aps_cls_ptcolor"
#define kAPSCloseOffsetX @"aps_cls_ox"
#define kAPSCloseOffsetY @"aps_cls_oy"
#define kAPSCloseInitialAlpha @"aps_cls_ia"
#define kAPSCloseFinalAlpha @"aps_cls_fa"
#define kAPSCloseHidden @"aps_cls_no"
#define kAPSCloseOffset @"aps_cls_offset"
#define kAPSCloseTrackingURLs @"aps_cls_tracking"

/**
 The `APSMediaPlayerClosableOverlayController` class is meant to be a superclass for overlay controllers that need to display a configurable close button to remove the overlay from screen.
 
 The class adds a set of standard keys to any overlay controller's own defined keys, to handle close button configuration. Methods are also exposed to allow a subclass to add and remove the close button from its view stack.
 */
@interface APSMediaPlayerClosableOverlayController : APSMediaPlayerOverlayController
/**
 This method adds the close button to the current view stack.
 
 The close button is configurable using the provided dictionary structure. Available configuration keys and values are:
 
 - `kAPSCloseImage`: if set to a `UIImage`, that image will be used instead of the standard progress-wheel close button.
 - `kAPSCloseSize`: a `NSNumber` reprezenting the lenght of a side of the close button square, in points. Defaults to 16.
 - `kAPSCloseBackgroundColor`: the background color of the close button view. Set this to a `UIColor` or a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 - `kAPSCloseXColor`: the color of the X symbol in the center of the player. Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 - `kAPSCloseProgressColor`: the color of the circular bar that indicates the currently elapsed time until the close button can be tapped. Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 - `kAPSCloseProgressTrackColor`: the color of the circular bar that indicates the total time until the close button can be tapped. Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 - `kAPSCloseOffsetX`: the horizontal offset of the close button, relative to the right margin of the overlay's view. Set this to a `NSNumber`. Defaults to 0.
 - `kAPSCloseOffsetY`: the vertical offset of the close button, relative to the top margin of the overlay's view. Set this to a `NSNumber`. Defaults to 0.
 - `kAPSCloseInitialAlpha`: a `NSNumber` indicating the opacity of the close button before it is activated for receiving taps. Defaults to 0.5.
 - `kAPSCloseFinalAlpha`: a `NSNumber` indicating the opacity of the close button after it has been activated for receiving taps. Defaults to 0.7.
 - `kAPSCloseHidden`: set this key to @YES to skip displaying the close button for this overlay. Defaults to @NO.
 - `kAPSCloseOffset`: a `NSNumber` that indicates the offset, in seconds, after which the close button should become activated for receiving taps. Defaults to 3.
 - `kAPSCloseTrackingURLs`: a `NSArray` of `NSURL`s that will be tracked by the player when the close button is tapped and the overlay is removed (see `[APSMediaPlayer track:forEvent:type:]`).
 @param parameters A dictionary containing configuration information.
 */
- (void)addCloseButtonWithParameters:(NSDictionary*)parameters;
/**
 *  This method removes the close button from the current view stack.
 */
- (void)removeCloseButton;
@end
