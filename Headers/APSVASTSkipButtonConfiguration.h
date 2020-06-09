//
//  APSVASTSkipButtonConfiguration.h
//  APSVAST
//
//  Created by gabi on 03.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaOverlay.h"
#import "APSVASTSkipOverlayController.h"

/**
 *  Holds all configuration parameters for the skip button displayed on top of video ads
 */
@interface APSVASTSkipButtonConfiguration : NSObject <NSCopying>
/**
 The position of the skip ad overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomRight`.
 */
@property (nonatomic) APSMediaOverlayPosition position;
/**
 The default interval of time that needs to pass before the skip overlay is activated for tapping.
 
 The default value is -1, which makes the skip button invisible.
 */
@property (nonatomic) int defaultSkipOffset;
/**
 The text that should be displayed in the skip button.
 
 Defaults to "Skip".
 */
@property (nonatomic) NSString *_Nullable text;
/**
 The color of the text diplayed in the skip button.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor whiteColor]`.
 */
@property (nonatomic) NSString *_Nullable textColor;
/**
 Defines where inside the skip overlay should the progress circle be rendered.
 
 See `APSSkipOverlayProgressPosition` for more details. Defaults to `kAPSSkipOverlayProgressPositionRight`.
 */
@property (nonatomic) APSSkipOverlayProgressPosition progressPosition;
/**
 Defines the color of the progress bar indicating the elapsed time since ad has started.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *_Nullable progressCircleColor;
/**
 Defines the color of the text in the middle of the progress circle, indicating the number of seconds left until skip activation.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *_Nullable progressCircleTextColor;
/**
 Defines the color of the progress bar indicating the total duration of the ad.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 */
@property (nonatomic) NSString *_Nullable progressCircleTrackColor;
/**
 The internal padding that the skip overlay should apply to its content.
 
 Defaults to 5.
 */
@property (nonatomic) int padding;
/**
 The color of the border for the skip overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *_Nullable borderColor;
/**
 The corner radius of the border for the skip overlay.
 
 Defaults to 5.
 */
@property (nonatomic) int borderRadius;
/**
 The background color for the skip overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *_Nullable backgroundColor;
/**
 The width of the skip overlay.
 
 Defaults to @"75".
 */
@property (nonatomic) NSString *_Nonnull width;
/**
 The height of the skip overlay.
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *_Nonnull height;
@end
