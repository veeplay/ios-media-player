//
//  APSVASTCountdownConfiguration.h
//  APSVAST
//
//  Created by gabi on 03.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaOverlay.h"

/**
 *  Holds all configuration parameters for the coundown overlay displayed on top of video ads.
 */
@interface APSVASTCountdownConfiguration : NSObject <NSCopying>
/**
 Indicates whether the countdown until the next media starts should be displayed during video ads.
 
 Defaults to `YES`;
 */
@property (nonatomic) BOOL show;
/**
 The position of the countdown overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomLeft`.
 */
@property (nonatomic) APSMediaOverlayPosition position;
/**
 *  The text to be displayed in the countdown overlay. Use the "__remaining__" placeholder for the number of seconds.
 */
@property (nonatomic) NSString *text;
/**
 The width of the countdown overlay.
 
 Defaults to @"64%".
 */
@property (nonatomic) NSString *width;
/**
 *  The height of the countdown overlay.
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *height;
/**
 The font family to be used for the text in the countdown overlay.
 
 Defaults to @"Helvetica".
 */
@property (nonatomic) NSString *font;
/**
 The size of the font to be used for the text in the countdown overlay.
 
 Defaults to 13.
 */
@property (nonatomic) int size;
/**
 The color of the font to be used for the text in the countdown overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor whiteColor]`.
 */
@property (nonatomic) NSString *color;
@end
