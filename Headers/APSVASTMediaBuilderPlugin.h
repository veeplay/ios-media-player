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
#import "APSMediaOverlay.h"
#import "APSVASTSkipOverlayController.h"

#define kAPSVASTFrameworkExtensionsGroup @"com.appscend.vast.frameworkextensions"

extern NSString *const APSVASTPrerollUnit;
extern NSString *const APSVASTMidrollUnit;
extern NSString *const APSVASTPostrollUnit;
extern NSString *const APSVASTNonlinearAd;

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

#define kAPSMetadataCurrentAdBreakIndex @"aps_vast_adbreak_index"
#define kAPSMetadataTotalAdBreakAds @"aps_vast_adbreak_total"

/**
 *  The VMAP standard permits allowing only one ad from a certain ad source. This constant defines how the VAST builder plugin deals with situations when multiple valid ads are retrieved from a source that is disallowed to load several ads at one time.
 */
typedef NS_ENUM(NSInteger, APSResolvMultipleAdsConflictsBy) {
    /**
     *  Solve the issue by dropping all loaded ads.
     */
    APSResolvMultipleAdsConflictsByDropping,
    /**
     *  Solve the issue by only inserting the first valid ad retrieved, honoring the defined order in the VAST.
     */
    APSResolvMultipleAdsConflictsBySelectingFirst,
    /**
     *  Solve the issue by only inserting one random ad from the loaded batch.
     */
    APSResolvMultipleAdsConflictsBySelectingRandom
};

/**
 *  VAST 3.0 defines Ad Pods, with fallback mechanisms that allow loading an ad buffet of commercials to playback if the main ads fail. This value specifies how to treat backwards compatibility issues with VAST 2.0 and 1.0, by choosing what ads are promoted to the main Ad Pod if no valid Pods are detected.
 */
typedef NS_ENUM(NSInteger, APSAdPodFallback) {
    /**
     *  Load all retrieved ads if no valid Ad Pods are found.
     */
    APSAdPodFallbackSelectAll,
    /**
     *  Load only the first retrieved ad if no valid Ad Pods are found.
     */
    APSAdPodFallbackSelectFirst,
    /**
     *  Drop the whole ad request if no valid Ad Pods are found. This value will disable VAST 1.0 and 2.0 compatibility.
     */
    APSAdPodFallbackDrop
};

/**
 *  Defines how an `APSVASTAdBreak` should be placed relative to the main content units.
 */
typedef NS_ENUM(NSInteger, APSVASTConfigurationOptions) {
    /**
     *  Place the `APSMediaUnit`s corresponding to the ad break at the beginning of the main content units.
     */
    APSVASTPreContent,
    /**
     *  Place the `APSMediaUnit`s corresponding to the ad break at the end of the main content units.
     */
    APSVASTPostContent,
    /**
     *  Place the `APSMediaUnit`s corresponding to the ad break in the middle of each main content unit, at a defined offset (see the `adOffset` property of `APSVASTAdBreak`).
     */
    APSVASTMidContent,
    /**
     *  Place the `APSMediaOverlay`s corresponding to the ad break in the middle of each main content unit, ad a defined offset (see the `adOffset` property of `APSVASTAdBreak`).
     */
    APSVASTNonLinear
};

/**
 *  An `APSVASTAdBreak` object defines an ad break for which the builder plugin will try to generate `APSMediaUnit`s and insert them into the playlist.
 */
@interface APSVASTAdBreak : NSObject
/**
 *  An array of `NSString` objects indicating the VAST URLs that will be called in order to populate the ad break with ads.
 */
@property (nonatomic) NSArray *URLs;
/**
 *  The ad break type. Specifies how the rezulting `APSMediaUnit`s and `APSMediaOverlay`s need to be placed relative to the main content units. See `APSVASTConfigurationOptions` for more details about the possible values.
 */
@property (nonatomic) APSVASTConfigurationOptions type;
/**
 A string format that defines when midrolls and nonlinear ads should be inserted mid-unit for each content unit.
 
 The expected format for this property is "hh:mm:ss".
 */
@property (nonatomic) NSString *adOffset;
@end

/**
 The VAST Media Builder plugin extends an `APSMediaBuilder` object by inserting preroll, postroll, midroll and non-linear ad breaks, loaded from VAST 1.0, VAST 2.0, VAST 3.0 and VMAP 1.0 sources.
 
 Use the `[APSMediaBuilder addPlugin:]` method to attach an `APSVASTMediaBuilderPlugin` object to a media builder.

 Configuration of the plugin can be done in three ways:
 
 - programatically configure the plugin object, using available properties;
 - configure the plugin object directly, using a dictionary - see `[APSMediaBuilderPlugin configureFromDictionary:]`;
 - configure the plugin with JSON. This is done as part of the `APSMediaBuilder` object configuration from JSON or from a dictionary. If the supplied configuration dictionary or interpreted JSON dictionary contains the "ads" key, then the corresponding value dictionary for that key will be provided to the plugin for configuration.
 */
@interface APSVASTMediaBuilderPlugin : NSObject <APSMediaBuilderPlugin>

/**-----------------------------------------------------------------------------
 * @name Configuring Ad Breaks
 * -----------------------------------------------------------------------------
 */
/**
 *  The VMAP 1.0 URL that should be used to configure ad breaks.
 */
@property (nonatomic) NSURL *vmapURL;
/**
 *  The currently defined ad breaks that the plugin will try to fill.
 */
@property (nonatomic) NSArray *adBreaks;

/**-----------------------------------------------------------------------------
 * @name Configuring the Playback Controls Bar
 * -----------------------------------------------------------------------------
 */
/**
 Specifies how the controls bar will be displayed on top of video ads.
 
 See `APSMediaControlsDisplay` for more details. Defaults to `APSMediaControlsDisplayNone`.
 */
@property (nonatomic) APSMediaControlsDisplay controlsDisplayForAds;
/**
 The configuration for the controls bar overlay on top of video ads. 
 
 See [APSMediaUnit controlsParameters] for details on creating this dictionary.
 */
@property (nonatomic) NSDictionary *controlsParametersForAds;
/**
 The ad video clip scaling mode, relative to the player surface.
 
 See Apple's [documentation](https://developer.apple.com/library/ios/documentation/MediaPlayer/Reference/MPMoviePlayerController_Class/Reference/Reference.html#//apple_ref/doc/c_ref/MPMovieScalingMode) for more details on `MPMovieScalingMode`. Defaults to `MPMovieScalingModeNone`.
 */
@property (nonatomic) MPMovieScalingMode scalingModeForAds;
/**
 Defines if the pinch-to-fullscreen gesture should be activated for generated video ads.
 
 Defaults to YES;
 */
@property (nonatomic) BOOL allowPinchToFullscreenOnAds;

/**-----------------------------------------------------------------------------
 * @name VAST 3.0 Icon Support
 * -----------------------------------------------------------------------------
 */
/**
 Icons are rendered to a height that's proportional to the current player view height. This property defines the percentage of the current height to render ads to, while preserving the original aspect ration in calculating the rendered width.
 
 Defaults to 10.
 */
@property (nonatomic) CGFloat defaultIconHeightPercentage;
/**
 The fade-in animation duration for displaying icons, in seconds.
 
 Defaults to 0.5.
 */
@property (nonatomic) CGFloat iconFadeInDuration;

/**-----------------------------------------------------------------------------
 * @name Skip Button Configuration
 * -----------------------------------------------------------------------------
 */
/**
 The position of the skip ad overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomRight`.
 */
@property (nonatomic) APSMediaOverlayPosition skipButtonPosition;
/**
 The default interval of time that needs to pass before the skip overlay is activated for tapping.
 
 The default value is -1, which makes the skip button active from the first moment.
 */
@property (nonatomic) int defaultSkipOffset;
/**
 The text that should be displayed in the skip button.
 
 Defaults to "Skip".
 */
@property (nonatomic) NSString *skipButtonText;
/**
 The color of the text diplayed in the skip button. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor whiteColor]`.
 */
@property (nonatomic) NSString *skipButtonTextColor;
/**
 Defines where inside the skip overlay should the progress circle be rendered. 
 
 See `APSSkipOverlayProgressPosition` for more details. Defaults to `kAPSSkipOverlayProgressPositionRight`.
 */
@property (nonatomic) APSSkipOverlayProgressPosition skipButtonProgressPosition;
/**
 Defines the color of the progress bar indicating the elapsed time since ad has started. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *skipButtonProgressCircleColor;
/**
 Defines the color of the text in the middle of the progress circle, indicating the number of seconds left until skip activation. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *skipButtonProgressCircleTextColor;
/**
 Defines the color of the progress bar indicating the total duration of the ad. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 */
@property (nonatomic) NSString *skipButtonProgressCircleTrackColor;
/**
 The internal padding that the skip overlay should apply to its content. 
 
 Defaults to 5.
 */
@property (nonatomic) int skipButtonPadding;
/**
 The color of the border for the skip overlay. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *skipButtonBorderColor;
/**
 The corner radius of the border for the skip overlay. 
 
 Defaults to 5.
 */
@property (nonatomic) int skipButtonBorderRadius;
/**
 The background color for the skip overlay. 
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *skipButtonBackgroundColor;
/**
 The width of the skip overlay. 
 
 Defaults to @"75".
 */
@property (nonatomic) NSString *skipButtonWidth;
/**
 The height of the skip overlay. 
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *skipButtonHeight;

/**-----------------------------------------------------------------------------
 * @name Countdown to Next Unit Overlay Configuration
 * -----------------------------------------------------------------------------
 */
/**
 Indicates whether the countdown until the next media starts should be displayed during video ads. 
 
 Defaults to `YES`;
 */
@property (nonatomic) BOOL showCountdown;
/**
 The position of the countdown overlay, relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottomLeft`.
 */
@property (nonatomic) APSMediaOverlayPosition countdownPosition;
/**
 *  The text to be displayed in the countdown overlay. Use the "__remaining__" placeholder for the number of seconds.
 */
@property (nonatomic) NSString *countdownText;
/**
 The width of the countdown overlay.
 
 Defaults to @"64%".
 */
@property (nonatomic) NSString *countdownWidth;
/**
 *  The height of the countdown overlay.
 
 Defaults to @"30".
 */
@property (nonatomic) NSString *countdownHeight;
/**
 The font family to be used for the text in the countdown overlay.
 
 Defaults to @"Helvetica".
 */
@property (nonatomic) NSString *countdownFont;
/**
 The size of the font to be used for the text in the countdown overlay. 
 
 Defaults to 13.
 */
@property (nonatomic) int countdownSize;
/**
 The color of the font to be used for the text in the countdown overlay.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor whiteColor]`.
 */
@property (nonatomic) NSString *countdownColor;


/**-----------------------------------------------------------------------------
 * @name Non-linear Ads Configuration
 * -----------------------------------------------------------------------------
 */
/**
 The maximum allowed size for a non-linear ad. Non-linear ads that define sizes larger than this will be truncated.
 
 Defaults to `CGSizeMake(320, 50)`.
 */
@property (nonatomic) CGSize bannerMaxSize;
/**
 Defines if non-linear ads should be stretched to the defined `bannerMaxSize`, should they declare a size smaller than that.
 
 Defaults to `NO`;
 */
@property (nonatomic) BOOL stretchBannersToMaxSize;
/**
 Defines how a non-linear banner overlay should be placed relative to the player surface.
 
 See `APSMediaOverlayPosition` for possible values. Defaults to `kAPSMediaOverlayPositionBottom`.
 */
@property (nonatomic) APSMediaOverlayPosition bannerPosition;
/**
 Defines the fade-in animation duration for non-linear ads.
 
 Defaults to 0.5.
 */
@property (nonatomic) CGFloat bannerFadeInDuration;
/**
 Defines the default number of seconds that a non-linear ad will be kept on display. This can be overridden by VAST ad configuration.
 
 Defaults to 10.
 */
@property (nonatomic) int defaultBannerAdBreakDuration;
/**
 Defines the default number of seconds after which the non-linear ad close button becomes active.
 
 Defaults to 3.
 */
@property (nonatomic) int bannerSkipOffset;
/**
 Indicates whether a close button should be displayed on top of non-linear ads.
 
 Defaults to `YES`.
 */
@property (nonatomic) BOOL showBannerCloseButton;
/**
 *  Defines the image that should be displayed in the non-linear ads close button, instead of the default progress wheel.
 */
@property (nonatomic) UIImage *bannerCloseButtonImage;
/**
 Defines the background color for the close button displayed on top of non-linear ads.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor clearColor]`.
 */
@property (nonatomic) NSString *bannerCloseButtonBackgroundColor;
/**
 Defines the color for the X symbol in the center of the close button.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 */
@property (nonatomic) NSString *bannerCloseButtonXColor;
/**
 Indicates the lenght of a side of the non-linear ads close button square.
 
 Defaults to 20.
 */
@property (nonatomic) int bannerCloseButtonSize;
/**
 Indicates the opacity of the non-linear ads close button before it is activated for receiving taps.
 
 Defaults to 0.5.
 */
@property (nonatomic) float bannerCloseButtonInitialAlpha;
/**
 Indicates the opacity of the non-linear close button after it has been activated for receiving taps.
 
 Defaults to 0.7.
 */
@property (nonatomic) float bannerCloseButtonFinalAlpha;
/**
 The color of the circular bar that indicates the currently elapsed time until the close button can be tapped.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor darkGrayColor]`.
 */
@property (nonatomic) NSString *bannerCloseButtonProgressColor;
/**
 The color of the circular bar that indicates the total time until the close button can be tapped.
 
 Set this to a `NSString` containing the hex color reprezentation. Defaults to `[UIColor lightGrayColor]`.
 */
@property (nonatomic) NSString *bannerCloseButtonTrackColor;
/**
 *  Defines the offset that the non-linear ads close button should have from the top-right edge of the banner itself.
 */
@property (nonatomic) CGPoint bannerCloseButtonOffset;

/**-----------------------------------------------------------------------------
 * @name Other Configurations
 * -----------------------------------------------------------------------------
 */
/**
 When loading ads via VMAP and using ad break positioning via "#", this array defines the available, pre-defined positions that ads can be inserted at.
 
 Positions are defined using strings that can either specify absolute time intervals in seconds (e.g.: @"10") or percentual values, relative to the full playback time (e.g.: @"50%"). Defaults to `@[@"5", @"75%"]`.
 */
@property (nonatomic) NSArray *defaultAdBreakPositions;
/**
 The VMAP standard permits allowing only one ad from a certain ad source. This constant defines how the VAST builder plugin deals with situations when multiple valid ads are retrieved from a source that is disallowed to load several ads at one time.
 
 See `APSResolvMultipleAdsConflictsBy` for possible values. Defaults to `APSResolvMultipleAdsConflictsBySelectingFirst`.
 */
@property (nonatomic) APSResolvMultipleAdsConflictsBy multipleAdsConflictsPolicy;
/**
 VAST 3.0 defines Ad Pods, with fallback mechanisms that allow loading an ad buffet of commercials to playback if the main ads fail. This value specifies how to treat backwards compatibility issues with VAST 2.0 and 1.0, by choosing what ads are promoted to the main Ad Pod if no valid Pods are detected.
 
 See `APSAdPodFallback` for possible values. Defaults to `APSAdPodFallbackSelectAll`.
 */
@property (nonatomic) APSAdPodFallback adPodFallbackStrategy;

/**
 An array that defines the mime-types supported when choosing a media file from the VAST response.
 
 Items are ordered from most preferred to least preferred. The default value for this property is `@[@"mobile/mp4",@"video/mp4",@"mobile/m3u8",@"application/x-mpegURL",@"application/vnd.apple.mpegURL",@"vnd.apple.mpegURL",@"video/m3u8"]`
 */
@property (nonatomic) NSArray *prefferedVideoMimeTypes;

/**
 *  Defines the behavior of the player after a banner ad is tapped and the built-in web browser is dismissed.
 */
@property (nonatomic) APSWebviewDismissedAction afterBannerTapped;

/**
 *  Defines the behavior of the player after a video ad is tapped and the built-in web browser is dismissed.
 */
@property (nonatomic) APSWebviewDismissedAction afterVideoAdTapped;

@end
