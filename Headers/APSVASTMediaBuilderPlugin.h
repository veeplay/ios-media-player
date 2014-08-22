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
#import "APSVASTSkipButtonConfiguration.h"
#import "APSVASTCountdownConfiguration.h"
#import "APSVASTBannerConfiguration.h"
@class APSVASTAdBreak;

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
 The VAST Media Builder plugin extends an `APSMediaBuilder` object by inserting preroll, postroll, midroll and non-linear ad breaks, loaded from VAST 1.0, VAST 2.0, VAST 3.0 and VMAP 1.0 sources.
 
 Use the `[APSMediaBuilder addPlugin:]` method to attach an `APSVASTMediaBuilderPlugin` object to a media builder.

 Configuration of the plugin can be done in three ways:
 
 - programatically configure the plugin object, using available properties;
 - configure the plugin object directly, using a dictionary - see `[APSMediaBuilderPlugin configureFromDictionary:]`;
 - configure the plugin with JSON. This is done as part of the `APSMediaBuilder` object configuration from JSON or from a dictionary. If the supplied configuration dictionary or interpreted JSON dictionary contains the "ads" key, then the corresponding value dictionary for that key will be provided to the plugin for configuration.
 */
@interface APSVASTMediaBuilderPlugin : NSObject <APSMediaBuilderPlugin>

- (NSArray*)adBreaksForVMAP;
/**-----------------------------------------------------------------------------
 * @name Configuring Ad Breaks
 * -----------------------------------------------------------------------------
 */
/**
 *  The VMAP 1.0 URL that should be used to configure ad breaks.
 */
@property (nonatomic) NSURL *vmapURL;

@property (nonatomic) APSVASTAdBreak *vmapAdBreakTemplate;
/**
 *  The currently defined ad breaks that the plugin will try to fill.
 */
@property (nonatomic) NSArray *adBreaks;


/**-----------------------------------------------------------------------------
 * @name Other Configurations
 * -----------------------------------------------------------------------------
 */
/**
 When loading ads via VMAP and using ad break positioning via "#", this array defines the available, pre-defined positions that ads can be inserted at.
 
 Positions are defined using strings that can either specify absolute time intervals in seconds (e.g.: @"10") or percentual values, relative to the full playback time (e.g.: @"50%"). Defaults to `@[@"5", @"75%"]`.
 */
@property (nonatomic) NSArray *defaultAdBreakPositions;

@end
