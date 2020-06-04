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

/**
 *  The `APSControlPluginProtocol` allows the definition of 3rd party buttons that need to be displayed in the Veeplay control bar. This protocol extends the `KRAdapter` protocol, so objects should also implement a `type` method, returning a unique string to register under.
 
   To use:
 
   - Create a new class that implements this protocol
   - Register it with the player shared instance:
 
           [[APSMediaPlayer sharedInstance] registerAdapter:[<YOURCLASS> new] inGroup:kAPSMediaPlayerControlPluginsGroup];
 
   - Use the `constant` to programatically add to the control components of a `APSMediaUnit`:
 
           unit.controlsParameters = @{kAPSControlsComponents: @(APSPlaybackControl|APSTotalTimeControl|<YOURCONSTANT>|APSFullScreenControl)};
 
   - Alternatively, use the `stringConstant` in your JSON configuration:
 
                   {
                         "content": [
                             "url": "http://......",
                             "autoplay": true,
                             "controls": {
                                 "components": [
                                     "playback",
                                     "totalTime",
                                     "slider",
                                     "currentTime",
                                     "<YOURSTRINGCONSTANT>"
                                 ]
                             }
                         ]
                     }
 */
@protocol APSControlPluginProtocol <NSObject, KRAdapter>

- (void)willLoad;
- (void)didLoad;
- (NSUInteger)constant;
- (NSString*_Nonnull)stringConstant;
- (CGFloat)width;
- (UIButton*_Nullable)buttonForOverlayController:(APSMediaPlayerControlsOverlayController *_Nonnull)overlayController;

@end
