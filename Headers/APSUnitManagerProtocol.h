//
//  VeesoDRMInterface.h
//  APSVAST
//
//  Created by gabi on 20.08.2014.
//  Copyright (c) 2014 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRAdapter.h"
#import "APSMediaUnit.h"

/**
 *  This protocol provides an interface for external objects that implement dynamic playback operations. Use this if you need to generate media URLs using timestamps or for implementing DRM support.
 */
@protocol APSUnitManagerProtocol <NSObject, KRAdapter>

/**
 *  When an `APSMediaUnit` is loaded by the player, if it declares requiring a manager that matches the current object's [KRAdapter type], this method will be invoked.
 *
 *  This method should handle playback by calling [APSMediaPlayer setCurrentURL:] to effectively start media playback for a specific URL, or call another relevant method (like [APSMediaPlayer step]) and generate `APSMediaPlayerErrorNotification` notifications on error.
 *
 *  @param unit The currently loading unit.
 */
- (void)startForUnit:(APSMediaUnit*)unit;
/**
 *  When an `APSMediaUnit` ends playback, if it declares requiring a manager that matches the current object's [KRAdapter type], this method will be invoked. 
 */
- (void)end;

@end
