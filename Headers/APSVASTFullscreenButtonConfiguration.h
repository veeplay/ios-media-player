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
 The position of the skip ad overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomRight`.
 */
@property (nonatomic) APSMediaOverlayPosition position;
/**
 The internal padding that the skip overlay should apply to its content.
 
 Defaults to 5.
 */
@property (nonatomic) int padding;
/**
 The URL to the icon which will be used for the "enter fullscreen" action
 
 Defaults to APSMediaPlayer.bundle/Controls/fullscreen.png
 */
@property (nonatomic, strong) NSString *enterIconLocation;
/**
 The URL to the icon which will be used for the "leave fullscreen" action
 
 Defaults to APSMediaPlayer.bundle/Controls/fullscreen-exit.png
 */
@property (nonatomic, strong) NSString *leaveIconLocation;
/**
 The color of the border for the skip overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *borderColor;
/**
 The corner radius of the border for the skip overlay.
 
 Defaults to 5.
 */
@property (nonatomic) int borderRadius;
/**
 The background color for the skip overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *backgroundColor;
/**
 The width of the skip overlay.
 
 Defaults to @"75".
 */
@property (nonatomic) NSString *width;
/**
 The height of the skip overlay.
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *height;
@end