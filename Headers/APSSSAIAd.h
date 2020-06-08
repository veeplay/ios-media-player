//
//  APSSSAIAd.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 18/06/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSSSAIAdEvent.h"

NS_ASSUME_NONNULL_BEGIN

@interface APSSSAIAd : NSObject

@property (nonatomic, strong, readonly) NSString *adId;
@property (nonatomic, readonly) NSTimeInterval durationInSeconds;
@property (nonatomic, readonly) NSTimeInterval startTimeInSeconds;
@property (nonatomic, readonly) NSTimeInterval endTimeInSeconds;
@property (nonatomic, readonly) NSDictionary<NSString*, APSSSAIAdEvent*> *trackingEvents;

- (instancetype) initWithAdMap:(NSDictionary *)adMap;

@end

NS_ASSUME_NONNULL_END
