//
//  APSVASTAdController.h
//  APSVAST
//
//  Created by Appscend on 7/18/13.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayer.h>
#import "APSMediaOverlay.h"
#import "APSMediaUnit.h"
#import "KRHub.h"
#import "APSMediaBuilderPlugin.h"

@interface APSMediaBuilder : KRHub
@property (nonatomic) NSString *userAgent;

@property (nonatomic) NSArray *contentUnits;
@property (nonatomic) NSArray *bumperUnits;
@property (nonatomic) NSArray *openerUnits;
@property (nonatomic) NSArray *closerUnits;

@property (nonatomic) BOOL debugMode;

+ (APSMediaUnit*)unitFromDictionary:(NSDictionary*)unitConfigurations;
+ (APSMediaOverlay*)overlayFromDictionary:(NSDictionary*)overlayConfigurations;
+ (NSMutableDictionary*)controlsParametersFromDictionary:(NSDictionary*)controls;

+ (APSMediaOverlayPosition)positionFromString:(NSString*)position;
+ (MPMovieScalingMode)scalingModeFromString:(NSString*)string;

- (BOOL)configureFromURL:(NSURL*)url;
- (void)configureFromURL:(NSURL*)url onComplete:(void (^)())block;
- (BOOL)configureFromData:(NSData*)data;
- (BOOL)configureFromDictionary:(NSDictionary*)configuration;

- (void)addPlugin:(NSObject<APSMediaBuilderPlugin>*)plugin;

- (APSMediaBuilder*)initWithMediaUnit:(APSMediaUnit*)contentUnit;
- (APSMediaBuilder*)initWithMediaUnits:(NSArray*)contentUnits;
- (NSArray*)mediaUnits;
- (void)requestMediaUnitsWithCompletionBlock:(void (^)(NSArray*))block;

@end
