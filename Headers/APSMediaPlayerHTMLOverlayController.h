//
//  APSMediaPlayerHTMLOverlayViewController.h
//  APSVAST
//
//  Created by gabi on 31.07.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"
#import "APSMediaPlayerClosableOverlayController.h"

extern NSString* const APSHTMLOverlay;
#define kAPSHTMLCodeContent @"aps_html_content"
#define kAPSHTMLIframeSource @"aps_html_iframesource"
#define kAPSHTMLScriptSource @"aps_html_scriptsource"
#define kAPSHTMLPageSource @"aps_html_source"
#define kAPSHTMLWidth @"aps_html_width"
#define kAPSHTMLHeight @"aps_html_height"
#define kAPSHTMLErrorURLs @"aps_html_errors"

/**
 The `APSMediaPlayerHTMLOverlayController` allows the inline loading of HTML content inside an overlay placed on top of video content.
 
 ## Configuration
 
 To create an `APSMediaOverlay` of HTML type:
 
 - set the overlay object's `type` property to `APSHTMLOverlay`
 - set the overlay object's `properties` property to a `NSDictionary` that can have the following keys and values:
 
     - *kAPSHTMLCodeContent*: the actual HTML `NSString` to be loaded.
     - *kAPSHTMLIframeSource*: `NSString` containing the URL that should be loaded inside an iframe element.
     - *kAPSHTMLScriptSource*: `NSString` containing the URL of the JavaScript file that should be loaded and executed.
     - *kAPSHTMLPageSource*: `NSString` containing the URL to load directly in the webview container.
     - *kAPSHTMLWidth*: `NSNumber` corresponding to the integer value to be set for the meta viewport width property.
     - *kAPSHTMLHeight*: `NSNumber` corresponding to the integer value to be set for the meta viewport height property.
     - *kAPSHTMLErrorURLs*: `NSArray` containing `NSURL`s to be tracked in case of error.
 */
@interface APSMediaPlayerHTMLOverlayController : APSMediaPlayerClosableOverlayController <APSMediaPlayerOverlayController, UIWebViewDelegate>
@end
