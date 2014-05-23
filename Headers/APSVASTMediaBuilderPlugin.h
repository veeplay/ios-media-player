//
//  APSVASTMediaBuilderPlugin.h
//  APSVAST
//
//  Created by gabi on 13.03.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaBuilderPlugin.h"
#import "APSMediaUnit.h"
#import "APSMediaPlayerSkipOverlayController.h"

typedef enum {
    APSResolvMultipleAdsConflictsByDropping,
    APSResolvMultipleAdsConflictsBySelectingFirst,
    APSResolvMultipleAdsConflictsBySelectingRandom
} APSResolvMultipleAdsConflictsBy;

typedef enum {
    APSAdPodFallbackSelectAll,
    APSAdPodFallbackSelectFirst,
    APSAdPodFallbackDrop
} APSAdPodFallback;

typedef enum {
    APSVASTPreContent,
    APSVASTPostContent,
    APSVASTMidContent,
    APSVASTNonLinear
} APSVASTConfigurationOptions;

@interface APSVASTAdBreak : NSObject
@property (nonatomic) NSArray *URLs;
@property (nonatomic) APSVASTConfigurationOptions adType;
@property (nonatomic) NSString *adOffset;
@end

@interface APSVASTMediaBuilderPlugin : NSObject <APSMediaBuilderPlugin> {
    __weak APSMediaBuilder *_builder;
}

@property (nonatomic) NSURL *vmapURL;
@property (nonatomic) NSArray *adBreaks;

@property (nonatomic) APSMediaControlsDisplay controlsDisplayForAds;
@property (nonatomic) NSDictionary *controlsParametersForAds;
@property (nonatomic) MPMovieScalingMode scalingModeForAds;
@property (nonatomic) BOOL allowPinchToFullscreenOnAds;

@property (nonatomic) CGFloat defaultIconHeightPercentage;
@property (nonatomic) CGFloat iconFadeInDuration;

@property (nonatomic) APSMediaOverlayPosition skipButtonPosition;
@property (nonatomic) int defaultSkipOffset;
@property (nonatomic) NSString *skipButtonText;
@property (nonatomic) NSString *skipButtonTextColor;
@property (nonatomic) APSSkipOverlayProgressPosition skipButtonProgressPosition;
@property (nonatomic) NSString *skipButtonProgressCircleColor;
@property (nonatomic) NSString *skipButtonProgressCircleTextColor;
@property (nonatomic) NSString *skipButtonProgressCircleTrackColor;
@property (nonatomic) int skipButtonPadding;
@property (nonatomic) NSString *skipButtonBorderColor;
@property (nonatomic) int skipButtonBorderRadius;
@property (nonatomic) NSString *skipButtonBackgroundColor;
@property (nonatomic) NSString *skipButtonWidth;
@property (nonatomic) NSString *skipButtonHeight;

@property (nonatomic) BOOL showCountdown;
@property (nonatomic) APSMediaOverlayPosition countdownPosition;
@property (nonatomic) NSString *countdownText;
@property (nonatomic) NSString *countdownWidth;
@property (nonatomic) NSString *countdownHeight;
@property (nonatomic) NSString *countdownFont;
@property (nonatomic) int countdownSize;
@property (nonatomic) NSString *countdownColor;

@property (nonatomic) CGSize bannerMaxSize;
@property (nonatomic) BOOL stretchBannersToMaxSize;
@property (nonatomic) APSMediaOverlayPosition bannerPosition;
@property (nonatomic) CGFloat bannerFadeInDuration;
@property (nonatomic) int defaultBannerAdBreakDuration;
@property (nonatomic) int bannerSkipOffset;
@property (nonatomic) BOOL showBannerCloseButton;
@property (nonatomic) UIImage *bannerCloseButtonImage;
@property (nonatomic) NSString *bannerCloseButtonBackgroundColor;
@property (nonatomic) NSString *bannerCloseButtonXColor;
@property (nonatomic) int bannerCloseButtonSize;
@property (nonatomic) float bannerCloseButtonInitialAlpha;
@property (nonatomic) float bannerCloseButtonFinalAlpha;
@property (nonatomic) NSString *bannerCloseButtonProgressColor;
@property (nonatomic) NSString *bannerCloseButtonTrackColor;
@property (nonatomic) CGPoint bannerCloseButtonOffset;

@property (nonatomic) NSArray *defaultAdBreakPositions;

@property (nonatomic) APSResolvMultipleAdsConflictsBy multipleAdsConflictsPolicy;
@property (nonatomic) APSAdPodFallback adPodFallbackStrategy;

@end
