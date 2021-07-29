//
//  FullscreenTransitioner.h
//  VeesoDemo
//
//  Created by Ovidiu on 04/06/15.
//  Copyright (c) 2015 Veeso. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FullscreenTransitioner : NSObject <UIViewControllerAnimatedTransitioning>

@property (nonatomic) BOOL presenting;

- (id) init:(BOOL)isPresenting;

@end
