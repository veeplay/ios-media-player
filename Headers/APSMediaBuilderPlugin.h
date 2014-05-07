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

@protocol APSMediaBuilderPlugin <KRAdapter>
@required
- (void)startForBuilder:(APSMediaBuilder*)builder;
- (void)configureFromDictionary:(NSDictionary*)configuration;
- (NSString*)dictionaryConfigurationKey;
@end
