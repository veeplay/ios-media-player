//
//  APSVASTAdController.h
//  APSVAST
//
//  Created by Appscend on 7/18/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>

#import "KRHub.h"
@class APSMediaUnit;
@class APSMediaOverlay;
@protocol APSMediaBuilderPlugin;

/**
 The `APSMediaBuilder` assists in creating playlists of fully configurable `APSMediaUnit`s, together with attached, configurable `APSMediaOverlay`s, using JSON files or using a `NSDictionary`, both following the same structure.
 
 The media builder also has class methods that assist with the generation of individual `APSMediaUnit` and `APSMediaOverlay` objects from corresponding JSON or `NSDictionary` structures.
 
 Plugins can be attached to a media builder. Each plugin can dynamically insert, edit or remove units and/or overlays from the generated playlist.
 */
@interface APSMediaBuilder : KRHub

/**-----------------------------------------------------------------------------
 * @name Unit and Overlay Factory Methods
 * -----------------------------------------------------------------------------
 */
/**
*  Factory method to generate new instance of `APSMediaUnit` via `NSDictionary` configuration.
*
*  @param unitConfigurations Dictionary unit configuration.
*
*  @return An instance of `APSMediaUnit` or nil if error.
*/
+ (APSMediaUnit *_Nullable)unitFromDictionary:(NSDictionary *_Nonnull)unitConfigurations;
/**
 *  Factory method to generate new instance of `APSMediaOverlay` via `NSDictionary` configuration.
 *
 *  @param overlayConfigurations Dictionary overlay configuration.
 *
 *  @return An instance of `APSMediaOverlay` or nil if error.
 */
+ (APSMediaOverlay *_Nullable)overlayFromDictionary:(NSDictionary *_Nonnull)overlayConfigurations;

/**-----------------------------------------------------------------------------
 * @name Media Builder Initialization
 * -----------------------------------------------------------------------------
 */
/**
 *  Initializes builder with a playlist of a single media unit.
 *
 *  @param contentUnit `APSMediaUnit` object to be played.
 *
 *  @return `APSMediaBuilder` object.
 */
- (instancetype _Nullable)initWithMediaUnit:(APSMediaUnit *_Nonnull)contentUnit;
/**
 *  Initializes builder with a playlist of media units.
 *
 *  @param contentUnits Array of `APSMediaUnit` objects to be played.
 *
 *  @return `APSMediaBuilder` object.
 */
- (instancetype _Nullable)initWithMediaUnits:(NSArray *_Nonnull)contentUnits;

/**-----------------------------------------------------------------------------
 * @name Media Builder Configuration
 * -----------------------------------------------------------------------------
 */
/**
 *  Configures the builder from a JSON structure.
 *  @warning This method may execute blocking network I/O on the calling thread.
 *
 *  @param url The URL of the JSON structure to load. This can be a remote file or a local file.
 *
 *  @return `YES` on succes.
 */
- (BOOL)configureFromURL:(NSURL *_Nonnull)url;
/**
 *  Configures the builder asynchronously from a JSON structure.
 *
 *  @param url   The URL of the JSON structure to load. This can be a remote file or a local file.
 *  @param block The block to be executed after configuration is finished.
 */
- (void)configureFromURL:(NSURL *_Nonnull)url onComplete:(void (^_Nonnull)(void))block;
/**
 *  Configures the builder from a `NSData` object.
 *  @warning UTF8 encoding is assumed.
 *
 *  @param data Configuration data - UTF8 encoded.
 *
 *  @return `YES` on succes.
 */
- (BOOL)configureFromData:(NSData *_Nonnull)data;
/**
 *  Configures the builder from a `NSDictionary` object.
 *
 *  @param configuration The configuration dictionary.
 *
 *  @return `YES` on succes.
 */
- (BOOL)configureFromDictionary:(NSDictionary *_Nonnull)configuration;
/**
 Array containing the main content `APSMediaUnit`s that will make up the playlist.
 
 In the finally rendered playlist, units from `bumperUnits` will be prefixed to the main content units, while units from `exitUnits` will be inserted after the main content units. Every array's content may be modified by attached builder plugins.
 */
@property (nonatomic) NSArray *_Nullable contentUnits;
/**
 *  Array containing `APSMediaUnit`s that will be scheduled before ones in contentUnits in the generated playlist.
 */
@property (nonatomic) NSArray *_Nullable bumperUnits;
/**
 *  Array containing `APSMediaUnit`s that will be scheduled after ones in contentUnits in the generated playlist.
 */
@property (nonatomic) NSArray *_Nullable exitUnits;

/**-----------------------------------------------------------------------------
 * @name Properties
 * -----------------------------------------------------------------------------
 */
/**
 *  The user agent that should be used when making HTTP requests.
 */
@property (nonatomic) NSString *_Nullable userAgent;
/**
 *  This property enables or disables console logging on all generated units.
 */
@property (nonatomic) BOOL debugMode;

/**-----------------------------------------------------------------------------
 * @name Generating the Final Playlist
 * -----------------------------------------------------------------------------
 */
/**
 *  Returns a generated playlist of `APSMediaUnit`s, based on builder configuration and registered plugins.
 *  @warning This method may execute blocking network I/O on the calling thread.
 *
 *  @return An array of `APSMediaUnit`s.
 */
- (NSArray *_Nonnull)mediaUnits;
/**
 *  Asynchronously generates a playlist of `APSMediaUnit`s, based on builder configuration and registered plugins.
 *
 *  @param block The block to be executed when playlist is generated.
 */
- (void)requestMediaUnitsWithCompletionBlock:(void (^_Nonnull)(NSArray *_Nonnull))block;

/**-----------------------------------------------------------------------------
 * @name Adding Plugins
 * -----------------------------------------------------------------------------
 */
/**
 *  Registers a new plugin.
 *
 *  @param plugin The new plugin object. Must implement `APSMediaBuilderPlugin`.
 */
- (void)addPlugin:(NSObject<APSMediaBuilderPlugin>*_Nonnull)plugin;

@end
