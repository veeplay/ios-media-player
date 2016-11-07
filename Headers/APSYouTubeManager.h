//
//  APSYouTubeManager.h
//  Veeplay
//
//  Created by Ovidiu D. Nitan on 07/11/2016.
//  Copyright © 2016 Appscend. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APSUnitManagerProtocol.h"

extern NSString* const kVeeplayYouTubeManager;

/**
 The APSYouTubeManager handles playback for units with YouTube URLs. To instantiate a APSYouTubeManager manager object and register it with the player:
 
 APSYouTubeManager *ytManager = [[APSYouTubeManager alloc] init];
 [[APSMediaPlayer sharedInstance] registerUnitManager:ytManager];
 
 Then set the `managerType` property of the `APSMediaUnit` object to `@"veeplay.unit_manager.youtube"`. If doing this programatically, you can also use the `kVeeplayYouTubeManager` constant.
 */

@interface APSYouTubeManager : NSObject <APSUnitManagerProtocol>

@end
