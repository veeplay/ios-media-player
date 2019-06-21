//
//  APSSSAIAdEvent.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 18/06/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSSSAIAdEvent : NSObject

@property (nonatomic, strong, readonly) NSArray<NSString*> *beaconURLs;
@property (nonatomic, readonly) NSTimeInterval durationInSeconds;
@property (nonatomic, readonly) NSTimeInterval startTimeInSeconds;
@property (nonatomic, strong, readonly) NSString *eventType;

- (instancetype) initWithEventMap:(NSDictionary *)eventMap;

@end

NS_ASSUME_NONNULL_END
