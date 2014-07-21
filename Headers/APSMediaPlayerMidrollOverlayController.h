//
//  APSMediaPlayerMidrollOverlayController.h
//  APSMediaPlayer
//
//  Created by gabi on 03.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSMidrollOverlay;

#define kAPSMidrollUnits @"units"

/**
 The `APSMediaPlayerMidrollOverlayController` allows the dynamic insertion of media units in the current playlist.
 
 ## Configuration
 
 To create an `APSMediaOverlay` of midroll type:
 
 - set the overlay object's `type` property to `APSMidrollOverlay`
 - set the overlay object's `properties` property to a `NSDictionary` that can have the following keys and values:
 
    - *kAPSMidrollUnits*: `NSArray` containing `APSMediaUnit`s to be inserted at play-time.
 */
@interface APSMediaPlayerMidrollOverlayController : APSMediaPlayerOverlayController
@end
