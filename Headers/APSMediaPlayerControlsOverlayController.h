//
//  APSMediaPlayerControlsOverlayController.h
//  APSMediaPlayer
//
//  Created by gabi on 02.08.2013.
//  Copyright (c) 2013 Appscend. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APSMediaPlayerOverlayController.h"

extern NSString* const APSControlsOverlay;
#define kAPSControlsBarColor @"barColor"
#define kAPSControlsBarAlpha @"barAlpha"
#define kAPSControlsComponents @"components"
#define kAPSControlsPlayedTrackColor @"playedTrackColor"
#define kAPSControlsBufferedTrackColor @"bufferedTrackColor"
#define kAPSControlsEmptyTrackColor @"emptyTrackColor"
#define kAPSControlsAdMarkColor @"adMarkColor"
#define kAPSControlsPlayImage @"playImage"
#define kAPSControlsPauseImage @"pauseImage"
#define kAPSControlsFullscreenImage @"fullscreenImage"
#define kAPSControlsLeaveFullscreenImage @"leaveFullscreenImage"
#define kAPSControlsPreviousImage @"backImage"
#define kAPSControlsNextImage @"forwardImage"
#define kAPSControlsVisibileOnlyInFullscreen @"visibleInFullscreenOnly"
#define kAPSControlsAutohideDuration @"autohideDuration"
#define kAPSControlsLiveText @"liveText"
#define kAPSControlsPlaybackTimeText @"playbackTimeText"
#define kAPSControlsChromecastDisconnectedImage @"chromecastDisconnectedImage"
#define kAPSControlsChromecastConnectedImage @"chromecastConnectedImage"
#define kAPSControlsUpdateCurrentTimeWhileSeeking @"updateTimeWhileSeeking"

extern NSString* const APSMoviePlayerCommandHideControls;
extern NSString* const APSMoviePlayerCommandShowControls;

/**
 *  Controls bar components.
 */
typedef NS_OPTIONS(NSUInteger, APSControlsOverlayComponents) {
    /**
     *  The current playback time counter.
     */
    APSCurrentTimeControl                   = 1 << 0,
    /**
     *  The seek bar (time slider) control.
     */
    APSTimeSliderControl                    = 1 << 1,
    /**
     *  The total playback time display.
     */
    APSTotalTimeControl                     = 1 << 2,
    /**
     *  The AirPlay video control. This control only appears when an AirPlay ready device is detected in the current network.
     */
    APSAirPlayControl                       = 1 << 3,
    /**
     *  The Chromecast video control. This control only appears when a Chromecast ready device is detected in the current network.
     */
    APSChromecastControl                    = 1 << 4,
    /**
     *  The fullscreen toggle control.
     */
    APSFullScreenControl                    = 1 << 5,
    /**
     *  The seek bar (time slider) control, with mid-seek thumbnail support.
     */
    APSThumbnailTimeSliderControl           = 1 << 6,
    /**
     *  Control allowing the user to return to previous unit in the playlist.
     */
    APSPreviousControl                      = 1 << 7,
    /**
     *  Control allowing the user to proceed to the next unit in the playlist.
     */
    APSNextControl                          = 1 << 8,
    /**
     *  The play/stop control.
     */
    APSPlaybackControl                      = 1 << 9,
    /**
     *  The ad marks
     */
    APSAdMarksControl                       = 1 << 10
     
};

@interface APSMediaPlayerControlsOverlayController : APSMediaPlayerOverlayController
@end
