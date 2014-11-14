//
//  APSMediaEvent.h
//  APSVAST
//
//  Created by gabi on 01.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Describes the current lifecycle state of a APSMediaEvent.
 */
typedef NS_ENUM(NSInteger, APSMediaEventState) {
    /**
     *  The event has not yet been loaded.
     */
    APSMediaEventStateUnloaded,
    /**
     *  The event is currently preloading.
     */
    APSMediaEventStatePreloading,
    /**
     *  The event has succesfully preloaded and is ready to be triggered.
     */
    APSMediaEventStatePreloaded,
    /**
     *  The event failed to preload and should not be triggered.
     */
    APSMediaEventStateFailed,
    /**
     *  The event is triggered.
     */
    APSMediaEventStateTriggered,
    /**
     *  The event finished.
     */
    APSMediaEventStateFinished
};

/**
 *  The `APSMediaEventProtocol` protocol describes methods that objects extending the associated `APSMediaEvent` class must or can implement.
 */
@protocol APSMediaEventProtocol <NSObject>

/**
 *  This code will be executed once the event is triggered by the player.
 */
- (void)onTrigger;

@optional
/**
 *  This method will be invoked on a different thread by the player, before the event start point, as set by the [APSMediaEvent preTriggerInterval] property.
 */
- (void)onPreload;

/**
 *  This method will be invoked by the player periodically, giving the event the opportunity to respond to updated playback information.
 */
- (void)onUpdate;

/**
 *  This method will be invoked by the player once the event has reached the end point and will be deallocated.
 */
- (void)onUnload;

@end

/**
 *  The `APSMediaEvent` class describes a container that developers can use to instruct the player to run specific blocks of code at specific moments of time. Objects extending this class and implementing the corresponding `APSMediaEventProtocol` protocol can be added to the player's main queue and can also be attached to a specific `APSMediaUnit` object, for runtime triggering.
 */
@interface APSMediaEvent : NSObject <APSMediaEventProtocol>
/**-----------------------------------------------------------------------------
 * @name Configuring the Event Interval
 * -----------------------------------------------------------------------------
 */
/**
 *  Sets the starting time point of the event.
 *
 *  @param startPoint A string format describing the time point when the player needs to trigger the event. Possible values are seconds (e.g.: @"60") or a percentage relative to the total duration of the parent clip (e.g.: @"50%").
 */
- (void)setStartPoint:(NSString*)startPoint;

/**
 *  Sets the ending time point of the event.
 *
 *  @param endPoint A string format describing the time point when the player needs to unload the event. Possible values are seconds (e.g.: @"60") or a percentage relative to the total duration of the parent clip (e.g.: @"50%").
 */
- (void)setEndPoint:(NSString*)endPoint;

/**
 *  The time interval (in seconds) when the player needs to trigger the event.
 *
 *  @return The initial time interval.
 *  @warning If percentual values were set via `setStartPoint`, this value will change immediately after the current clip's duration is available.
 */
- (NSTimeInterval)startPoint;

/**
 *  The playback time (in seconds) when the player needs to unload the event. Defaults to -1 for events that should unload right after triggering.
 *
 *  @return The final time interval.
 *  @warning If percentual values were set via `setStartPoint`, this value will change immediately after the current clip's duration is available.
 */
- (NSTimeInterval)endPoint;

/**
 *  If this parameter is greater than 0, then the event will be retriggered by the media player after the specific time interval (in seconds).
 */
@property (nonatomic) NSTimeInterval repeatAfter;

/**
 *  Shifts air-time for an event by a defined amount of time.
 *
 *  @param duration Shift duration in seconds.
 */
- (void)incrementStartAndEndPointsWithInterval:(NSTimeInterval)duration;

/**
 *  Translates percentual values set via `setStartPoint` and `setEndPoint` to actual time intervals in seconds, relative to a specified total duration.
 *
 *  @param duration The total duration.
 */
- (void)adjustRelativeToDuration:(NSTimeInterval)duration;

/**-----------------------------------------------------------------------------
 * @name Asynchroneous Pre-Trigger
 * -----------------------------------------------------------------------------
 */
/**
 *  Call this to trigger the event.
 */
- (void)trigger;
/**
 *  Call this to preload the event.
 */
- (void)preload;

/**-----------------------------------------------------------------------------
 * @name Asynchroneous Event Preloading
 * -----------------------------------------------------------------------------
 */
/**
 *  Defines the number of seconds before the scheduled start point when the event should receive the [APSMediaEventProtocol preload] message (if the method is implemented).
 */
@property (nonatomic) NSTimeInterval preloadInterval;

/**
 *  Defines the maximum number of seconds the event is allowed to live once it has been pretriggered, without setting the loaded property to `YES`.
 */
@property (nonatomic) NSTimeInterval timeout;

/**
 *  The current lifecycle state of the event.
 */
@property APSMediaEventState state;

/**
 *  Set by the player to the current playback time in seconds, after the current event begins preloading. Defaults to -1 if the event did not start preloading.
 */
@property NSTimeInterval preloadPoint;

@property BOOL dynamicPosition;

@end