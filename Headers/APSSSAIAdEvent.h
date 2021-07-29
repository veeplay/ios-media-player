//
//  APSSSAIAdEvent.h
//  Veeplay
//
//  Created by Ovidiu Nitan on 18/06/2019.
//  Copyright © 2019 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APSSSAIAdEvent : NSObject

@property (nonatomic, strong, readonly) NSArray<NSString*> *_Nullable beaconURLs;
@property (nonatomic, readonly) NSTimeInterval durationInSeconds;
@property (nonatomic, readonly) NSTimeInterval startTimeInSeconds;
@property (nonatomic, strong, readonly) NSString *_Nullable eventType;

- (instancetype _Nonnull) initWithEventMap:(NSDictionary *_Nonnull)eventMap;

@end
