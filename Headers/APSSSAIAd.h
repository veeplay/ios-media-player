//
//  APSSSAIAd.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 18/06/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSSSAIAdEvent.h"

@interface APSSSAIAd : NSObject

@property (nonatomic, strong, readonly) NSString *_Nonnull adId;
@property (nonatomic, readonly) NSTimeInterval durationInSeconds;
@property (nonatomic, readonly) NSTimeInterval startTimeInSeconds;
@property (nonatomic, readonly) NSTimeInterval endTimeInSeconds;
@property (nonatomic, readonly) NSDictionary<NSString*, APSSSAIAdEvent*> *_Nonnull trackingEvents;

- (instancetype _Nonnull) initWithAdMap:(NSDictionary *_Nonnull)adMap;

@end
