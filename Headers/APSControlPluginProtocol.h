//
//  APSMediaPlayerControlPluginProtocol.h
//  Veeplay
//
//  Created by gabi on 27.01.2016.
//  Copyright © 2016 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRAdapter.h"
#import "APSMediaPlayerControlsOverlayController.h"

@protocol APSControlPluginProtocol <NSObject, KRAdapter>

- (void)willLoad;
- (void)didLoad;
- (NSUInteger)constant;
- (NSString*)stringConstant;
- (CGFloat)width;
- (UIButton*)buttonForOverlayController:(APSMediaPlayerControlsOverlayController *)overlayController;

@end
