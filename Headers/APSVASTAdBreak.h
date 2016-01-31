//
//  APSVASTAdBreak.h
//  APSVAST
//
//  Created by gabi on 02.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSMediaEvent.h"
#import "APSMediaTrackableObject.h"
#import "APSVASTSkipButtonConfiguration.h"
#import "APSVASTFullscreenButtonConfiguration.h"
#import "APSVASTCountdownConfiguration.h"
#import "APSVASTBannerConfiguration.h"
#import "APSMediaUnit.h"

/**
 *  Defines how an `APSVASTAdBreak` should be placed relative to the main content units.
 */
typedef NS_ENUM(NSInteger, APSVASTAdBreakType) {
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
 *  An `APSVASTAdBreak` object defines an ad break for which the builder plugin will try to generate `APSMediaUnit`s and insert them into the playlist.
 */
@interface APSVASTAdBreak : APSMediaEvent <NSCopying, APSMediaTrackableObject>
/**-----------------------------------------------------------------------------
 * @name Main Configuration
 * -----------------------------------------------------------------------------
 */
/**
 *  An array of `NSString` objects indicating the VAST URLs that will be called in order to populate the ad break with ads.
 */
@property (nonatomic) NSArray *sources;
/**
 *  The ad break type. Specifies how the rezulting `APSMediaUnit`s and `APSMediaOverlay`s need to be placed relative to the main content units. See `APSVASTConfigurationOptions` for more details about the possible values.
 */
@property (nonatomic) APSVASTAdBreakType type;
/**
 A string format that defines when midrolls and nonlinear ads should be inserted mid-unit for each content unit.
 
 The expected format for this property is: "seconds" or "percentage%".
 */
@property (nonatomic) NSString *adOffset;
/**
 *  Defines the time interval in seconds after which the ad break will be repeated.
 */
@property (nonatomic) NSTimeInterval repeatAfter;
/**
 *  The user agent that should be used when making HTTP requests.
 */
@property (nonatomic) NSString *userAgent;
/**
 *  Configure an AdBreak from a dictionary structure.
 *
 *  @param configuration Configuration dictionary.
 */
- (void)configureFromDictionary:(NSDictionary *)configuration;
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
 *  Holds the configuration object for the skip button that appears on top of video ads.
 */
@property (nonatomic) APSVASTSkipButtonConfiguration *skipButtonConfiguration;

/**-----------------------------------------------------------------------------
* @name Fullscreen Button Configuration
* -----------------------------------------------------------------------------
*/
/**
 *  Holds the configuration object for the fullscreen button that appears on top of video ads.
 */
@property (nonatomic) APSVASTFullscreenButtonConfiguration *fullscreenButtonConfiguration;

/**-----------------------------------------------------------------------------
 * @name Countdown to Next Unit Overlay Configuration
 * -----------------------------------------------------------------------------
 */
/**
 *  Holds the configuration object for the countdown overlay that appears on top of video ads.
 */
@property (nonatomic) APSVASTCountdownConfiguration *countdownConfiguration;


/**-----------------------------------------------------------------------------
 * @name Non-linear Ads Configuration
 * -----------------------------------------------------------------------------
 */

@property (nonatomic) APSVASTBannerConfiguration *bannerConfiguration;

/**-----------------------------------------------------------------------------
 * @name Ad Retrieval Settings
 * -----------------------------------------------------------------------------
 */
/**
 *  Defines whether the break should allow more than one ad to be played, even if more ads are retrieved.
 */
@property (nonatomic) BOOL allowMultipleAds;
/**
 *  Defines whether VAST Wrappers should be followed for the given URL sources.
 */
@property (nonatomic) BOOL followWrappers;
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
 
 Items are ordered from most preferred to least preferred. The default value for this property is `@[@"mobile/m3u8",@"application/x-mpegURL",@"application/vnd.apple.mpegURL",@"vnd.apple.mpegURL",@"video/m3u8",@"mobile/mp4",@"video/mp4"]`
 */
@property (nonatomic) NSArray *prefferedVideoMimeTypes;

/**-----------------------------------------------------------------------------
 * @name Other Configurations
 * -----------------------------------------------------------------------------
 */
/**
 The ad video clip scaling mode, relative to the player surface.
 
 Defaults to `APSMovieScalingModeAspectFit`.
 */
@property (nonatomic) APSMovieScalingMode scalingMode;

/**
 Defines if the pinch-to-fullscreen gesture should be activated for generated video ads.
 
 Defaults to YES;
 */
@property (nonatomic) BOOL allowPinchToFullscreen;

/**
 *  Defines the behavior of the player after a banner ad is tapped and the built-in web browser is dismissed.
 */
@property (nonatomic) APSWebviewDismissedAction afterBannerTapped;

/**
 *  Defines the behavior of the player after a video ad is tapped and the built-in web browser is dismissed.
 */
@property (nonatomic) APSWebviewDismissedAction afterVideoAdTapped;

/**
 *  Defines if the break should log debug information to the console.
 */
@property (nonatomic) BOOL debug;

@property (nonatomic) NSMutableDictionary *metadata;

@end
