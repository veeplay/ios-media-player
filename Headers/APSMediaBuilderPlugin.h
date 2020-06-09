//
//  APSFrameworkExtension.h
//  APSVAST
//
//  Created by gabi on 01.11.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol KRAdapter;
@class APSMediaBuilder;

/**
 *  Defines methods that need to be implemented by any object that want to register as an `APSMediaBuilder` plugin.
 */
@protocol APSMediaBuilderPlugin <KRAdapter>
@required
/**-----------------------------------------------------------------------------
 * @name Plugin Execution
 * -----------------------------------------------------------------------------
 */
/**
 *  This method will be called at the beginning of the `mediaUnits` method of the `APSMediaBuilder` object that registered the plugin.
 *
 *  @param builder A reference to the calling `APSMediaBuilder` object.
 */
- (void)startForBuilder:(APSMediaBuilder*_Nonnull)builder;
/**-----------------------------------------------------------------------------
 * @name Plugin Dictionary Configuration
 * -----------------------------------------------------------------------------
 */
/**
 *  The string key that will be used in the root of JSON and dictionary builder configurations to hold all the specific configuration details for the plugin.
 *
 *  @return String key.
 */
- (NSString *_Nonnull)dictionaryConfigurationKey;
/**
 *  This method is called by the `APSMediaBuilder` object, in the process of its configuration. The method is only called if in the root of the configuring JSON or `NSDictionary` there is a key equal to the string defined by the plugin using the `dictionaryConfigurationKey` method.
 *
 *  @param configuration A `NSDictionary` object containing the specific plugin configuration data.
 */
- (void)configureFromDictionary:(NSDictionary *_Nonnull)configuration;

@end
