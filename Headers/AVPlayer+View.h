//
//  AVPlayer+View.h
//  VeesoPlayer
//
//  Created by Ovidiu on 26/02/15.
//  Copyright (c) 2015 Appscend. All rights reserved.
//

#import <objc/runtime.h>
#import <AVFoundation/AVFoundation.h>
#import "APSAVPlayerView.h"

@interface AVPlayer (View)

@property (nonatomic, strong) APSAVPlayerView *view;

@end
