//
//  APSMediaTrackableObject.h
//  APSMediaPlayer
//
//  Created by gabi on 03.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Defines the properties that an object needs to implement to become trackable by the player.
 */
@protocol APSMediaTrackableObject <NSObject>
/**
 *  This dictionary defines all URLs that need to be notified of specific events from the object's lifecycle. The keys are event constants, as defined in `APSMediaPlayer`, and the values are `NSArrays` containing `NSURL` objects.
 */
@property (nonatomic) NSMutableDictionary *trackingURLs;
@end
