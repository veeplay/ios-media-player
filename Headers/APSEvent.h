//
//  APSEvent.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 21/06/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSEvent : NSObject

@property (nonatomic, strong) NSString *_Nonnull name;
@property (nonatomic, strong) NSString *_Nonnull type;
@property (nonatomic, strong) id _Nullable object;
@property (nonatomic, strong) NSDictionary *_Nullable metadata;
@property (nonatomic, strong) NSArray<NSURL*> *_Nullable trackingURLs;
@property (nonatomic) BOOL shouldEmitEvent;
@property (nonatomic) BOOL synchronized;

/*
 *  Event objects are used internally to send event across the player. Use `APSEvent` objects with `-trackEvent:` method in APSMediaPlayer
 *
 *  @param name The specific event subtype name. May be nil for simple events.
 *  @param type The tracked event type. See "Available Tracking Events".
 *  @param object The `APSMediaUnit` or `APSMediaOverlay` instance that generated the notification. Can be nil for non-unit related events.
 *  @param trackingURLs An array of `NSURL` objects representing addresses that should be pinged.
 *  @param metadata Additional key-value pairs to send via the notification's userInfo to subscribers.
 *  @param emitEvent If the event should be further propagated internally
 *  @param sync If the event should be sync or async dispatched
 */
+ (instancetype)eventWithName:(nullable NSString *)name
                         type:(NSString *)type
                       object:(nullable id)object
                 trackingURLs:(nullable NSArray*)trackingURLs
                     metadata:(NSDictionary*)metadata
                    emitEvent:(BOOL)shouldEmitEvent
                         sync:(BOOL)sync;

+ (instancetype)eventWithName:(nullable NSString *)name type:(NSString *)type object:(nullable id)object;
+ (instancetype)eventWithName:(nullable NSString *)name type:(NSString *)type object:(nullable id)object metadata:(NSDictionary *)metadata;
+ (instancetype)eventWithName:(nullable NSString *)name type:(NSString *)type object:(nullable id)object trackingURLs:(NSArray*)trackingURLs metadata:(NSDictionary *)metadata;
+ (instancetype)eventWithName:(nullable NSString *)name type:(NSString *)type object:(nullable id)object trackingURLs:(NSArray*)trackingURLs metadata:(NSDictionary *)metadata emitEvent:(BOOL)shouldEmitEvent;
+ (instancetype)eventWithName:(nullable NSString *)name type:(NSString *)type object:(nullable id)object trackingURLs:(NSArray*)trackingURLs metadata:(NSDictionary*)metadata sync:(BOOL)sync;

- (NSArray *)objectTrackingURLs;

@end

NS_ASSUME_NONNULL_END
