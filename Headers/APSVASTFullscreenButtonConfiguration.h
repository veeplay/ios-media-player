//
//  APSVASTFullscreenButtonConfiguration.h
//  VeesoDemo
//
//  Created by Ovidiu on 16/04/15.
//  Copyright (c) 2015 Veeso. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaOverlay.h"
#import "APSVASTFullscreenOverlayController.h"

@interface APSVASTFullscreenButtonConfiguration : NSObject <NSCopying>
/**
 .
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomRight`.
 */
@property (nonatomic) BOOL visible;
/**
 The position of the fullscreen ad overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomRight`.
 */
@property (nonatomic) APSMediaOverlayPosition position;
/**
 The internal padding that the fullscreen overlay should apply to its content.
 
 Defaults to 5.
 */
@property (nonatomic) int padding;
/**
 An URL to the icon or a UIImage instance which will be used for the "enter fullscreen" action
 
 Defaults to APSMediaPlayer.bundle/Controls/fullscreen.png
 */
@property (nonatomic, strong) id enterIconLocation;
/**
 An URL to the icon or a UIImage instance which will be used for the "leave fullscreen" action
 
 Defaults to APSMediaPlayer.bundle/Controls/fullscreen-exit.png
 */
@property (nonatomic, strong) id leaveIconLocation;
/**
 The color of the border for the fullscreen overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *borderColor;
/**
 The corner radius of the border for the fullscreen overlay.
 
 Defaults to 5.
 */
@property (nonatomic) int borderRadius;
/**
 The background color for the fullscreen overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *backgroundColor;
/**
 The width of the fullscreen overlay.
 
 Defaults to @"75".
 */
@property (nonatomic) NSString *width;
/**
 The height of the fullscreen overlay.
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *height;
@end
