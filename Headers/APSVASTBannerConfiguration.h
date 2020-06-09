//
//  APSVASTBannerConfiguration.h
//  APSVAST
//
//  Created by gabi on 03.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "APSMediaOverlay.h"

/**
 *  Holds all configuration parameters for the banner ads displayed.
 */
@interface APSVASTBannerConfiguration : NSObject <NSCopying>
/**
 The maximum allowed size for a non-linear ad. Non-linear ads that define sizes larger than this will be truncated.
 
 Defaults to `CGSizeMake(320, 50)`.
 */
@property (nonatomic) CGSize maxSize;
/**
 Defines if non-linear ads should be stretched to the defined `bannerMaxSize`, should they declare a size smaller than that.
 
 Defaults to `NO`;
 */
@property (nonatomic) BOOL stretchToMaxSize;
/**
 Defines how a non-linear banner overlay should be placed relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottom`.
 */
@property (nonatomic) APSMediaOverlayPosition position;
/**
 Defines the fade-in animation duration for non-linear ads.
 
 Defaults to 0.5.
 */
@property (nonatomic) CGFloat fadeInDuration;
/**
 Defines the default number of seconds that a non-linear ad will be kept on display. This can be overridden by VAST ad configuration.
 
 Defaults to 10.
 */
@property (nonatomic) int defaultAdBreakDuration;
/**
 Defines the default number of seconds after which the non-linear ad close button becomes active.
 
 Defaults to 3.
 */
@property (nonatomic) int skipOffset;
/**
 Indicates whether a close button should be displayed on top of non-linear ads.
 
 Defaults to `YES`.
 */
@property (nonatomic) BOOL showCloseButton;
/**
 *  Defines the image that should be displayed in the non-linear ads close button, instead of the default progress wheel.
 */
@property (nonatomic) UIImage *_Nullable closeButtonImage;
/**
 Defines the background color for the close button displayed on top of non-linear ads.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to [UIColor clearColor].
 */
@property (nonatomic) NSString *_Nullable closeButtonBackgroundColor;
/**
 Defines the color for the X symbol in the center of the close button.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to [UIColor darkGrayColor].
 */
@property (nonatomic) NSString *_Nullable closeButtonXColor;
/**
 Indicates the lenght of a side of the non-linear ads close button square.
 
 Defaults to 20.
 */
@property (nonatomic) int closeButtonSize;
/**
 Indicates the opacity of the non-linear ads close button before it is activated for receiving taps.
 
 Defaults to 0.5.
 */
@property (nonatomic) float closeButtonInitialAlpha;
/**
 Indicates the opacity of the non-linear close button after it has been activated for receiving taps.
 
 Defaults to 0.7.
 */
@property (nonatomic) float closeButtonFinalAlpha;
/**
 The color of the circular bar that indicates the currently elapsed time until the close button can be tapped.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to [UIColor darkGrayColor].
 */
@property (nonatomic) NSString *_Nullable closeButtonProgressColor;
/**
 The color of the circular bar that indicates the total time until the close button can be tapped.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to [UIColor lightGrayColor].
 */
@property (nonatomic) NSString *_Nullable closeButtonTrackColor;
/**
 *  Defines the offset that the non-linear ads close button should have from the top-right edge of the banner itself.
 */
@property (nonatomic) CGPoint closeButtonOffset;
@end
