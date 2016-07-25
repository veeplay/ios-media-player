
## About

[<img src="http://veeplay.com/wp-content/themes/veeplay/images/logo_veeplay_small.png">](http://veeplay.com)

The Veeplay Media Player allows you to:

* Create playlists of synchronized videos and overlays
* Configure a playlist from an external JSON file, an equivalent NSDictionary structure or directly via code attributes
* Create custom, native overlays
* Automatically configure ad linear inserts (pre, mid and post rolls) as well as nonlinear inserts (banner overlays), VAST 1.0, 2.0, 3.0 and VMAP 1.0 compliant
* Create custom player skins, brand player with logo, insert overlay bugs, customize player controls
* Track video and overlay lifecycle events in real-time, as rendered

## Demo

Install [cocoapods](http://guides.cocoapods.org/using/getting-started.html#getting-started), and then run

    pod try Veeplay

## Installation

There are currently two integration paths: via CocoaPods or via standard library download.

1. **Installing via CocoaPods (recommended)**
        
    - Add the following line to your podfile:
    
            pod 'Veeplay'
        
    - Run `pod install` to install the player and all the dependencies. Run `pod update` to keep the library updated.
    
2. **Installing via library download**

    - Add `MediaPlayer.framework`, `AVFoundation.framework`, `CoreMedia.framework`, `SystemConfiguration.framework` and `libz.dylib` to your project.
    
        - Select your target in the project settings screen.
        - Select the “Build Phases” tab.
        - Expand the “Link Binary With Libraries” area.
        - Click the “+” button, and add `MediaPlayer.framework`, `AVFoundation.framework`, `CoreMedia.framework`, `SystemConfiguration.framework` and `libz.dylib` to your project.
        
    - Add the player’s static library to your project.
    
        - Drag the “libVeeplay.a” file to your project.
        - When prompted, make sure to check the project target that should link against the static library.
        - Select your target in the project settings screen.
        - Select the “Build Settings” tab.
        - Search for “Other Linker Flags” and make sure that the “-ObjC” flag is present. If it is not, add it.
        - Search for “iOS Deployment Target” and make sure to set the value to iOS 5 and up (iOS < 5 is not supported).
        
    - Add the player’s header files to your project.
    
        - Drag all the header files in the “headers” folder into your Xcode project OR
        
        - Select your target in the project settings screen.
        - Select the “Build Settings” tab.
        - Search for “Header Search Paths” and make sure that all the header files are in a location that Xcode knows about.
        
    - Add the player’s resource files to your project.
    
        - Drag all the files in the "Assets" folder into your Xcode project.
        - When prompted, make sure to check the project target that should include the resources.
        

## Getting Started

Set up an account at http://panel.veeplay.com and add your application's bundle identifier under "License Management".

Import the Player’s header file, as well as the VAST/VMAP or other plugins:

    #import "APSMediaPlayer.h" 
    #import "APSVASTMediaBuilderPlugin.h"

Create a new APSMediaBuilder instance and add plugins as required APSMediaUnit : 

    APSMediaBuilder *builder = [[APSMediaBuilder alloc] init]; 
    [builder addPlugin:[[APSVASTMediaBuilderPlugin alloc] init]]; 

Optionally, APSMediaUnit set the debugMode flag to YES to enable console logging: 

    builder.debugMode = YES;
 
Add the media player to a view: 

    [APSMediaPlayer sharedInstance].view.frame = CGRectMake(5, 5, 310, 450); 
    [self.view addSubview:[APSMediaPlayer sharedInstance].view];
 
The next step is to create a playlist of `APSMediaUnit`s to feed to the player for playback. This is what the `builder` object does; it acts like a configurable `APSMediaUnit` and `APSMediaOverlay` factory. Configuration can be done by specifying a URL to a JSON configuration file or by providing a similar configuration structure in a `NSDictionary` container.

Since remote configuration is a process involving network requests, the builder exposes an asynchroneous configuration method:

    [builder configureFromURL:[NSURL URLWithString:@"http://example.com/player.json"] onComplete:^ {
        // TODO: Request and play media units here
    }];
    
The builder is configured at this point and is able to generate an array of media units ready for playback. When requesting unit generation however, plugins like `APSVASTMediaBuilderPlugin` require making additional network requests in order to work. So, again, there is an asynchroneous unit retrieval method:

    [builder configureFromURL:[NSURL URLWithString:@"http://example.com/player.json"] onComplete:^ {
        [builder requestMediaUnitsWithCompletionBlock:^(NSArray *units) {
            [[APSMediaPlayer sharedInstance] playMediaUnits:units];
        }];
    }];

In the final execution block we instruct the player to start playback using the final generated array of media units, configured remotely via JSON input.

## Configuring from JSON

See [this guide](http://veeplay.github.io/json-docs/) for documentation on all available configuration options and examples.

## Creating custom overlay controllers

APSMediaPlayer allows developers to create their own, JSON or dictionary configurable overlays. To create a custom overlay:

* Create a new class that inherits from APSMediaPlayerOverlayController, which is a `UIViewController` subclass itself.
* Implement [KRAdapter type] to return a unique string that identifies the overlay. This is also used in the configuration dictionary.
* Implement [APSMediaPlayerOverlayControllerProtocol load] to execute the custom overlay creation code. This method is invoked by the player, when first diplaying the overlay controller object. You can access configuration parameters as defined in the JSON or NSDictionary configuration using `self.overlay.parameters`. You can also access information about the currently running unit, using `self.overlay.parentUnit`.
* Implement any other protocol-defined method as needed, see `APSMediaPlayerOverlayControllerProtocol` for a complete list.
* Register the newly created class with the player: 

        [[APSMediaPlayer sharedInstance] registerClass:[CLASSNAME class] inGroup:kAPSMediaPlayerOverlayControllersGroup type:@"TYPE"];

## Using Chromecast

To connect and send playback to the [Google Chromecast](https://www.google.com/chromecast), you need to install the Veeplay Chromecast plugin. See full documentation [here](http://veeplay.github.io/ios-chromecast-plugin/).

To install:

* Add the following line to your Podfile:

        pod "VeeplayChromecast"

* Alternatively, if installing without CocoaPods, get the latest static library, header files and assets [from the repository](https://github.com/veeplay/ios-chromecast-plugin). Also, install the latest version of the [Google Cast iOS Sender API library](https://developers.google.com/cast/docs/ios_sender).
* Import the VeeplayChromecastManager header file:

        #import "VeeplayChromecastManager.h"

To start the plugin, set your Chromecast application id on the shared instance of `APSChromeCastManager`:

        [APSChromecastManager sharedInstance].chromecastAppId = @"appid"

You can display the Chromecast playback control in the control bar by adding `chromecast` into the components array, under the `controls` section in your JSON configuration file:

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
                        "chromecast"
                    ]
                }
            ]
        }

Also, you can configure this programatically by adding kAPSChromecastControl to the `controlsParameters` property on `APSMediaUnit`:

        unit.controlsParameters = @{kAPSControlsComponents: @(APSPlaybackControl|APSCurrentTimeControl|APSTimeSliderControl|APSTotalTimeControl|kAPSChromecastControl|APSFullScreenControl)};

## Using Marlin DRM

APSMediaPlayer provides support for [Marlin DRM](http://www.marlin-community.com/), using the SDKs provided by [ExpressPlay](http://expressplay.com). See full documentation [here](http://veeplay.github.io/ios-marlin-drm/).

To install:

* Install the ExpressPlay SDK.
* Add the following line to your Podfile:
        
        pod "VeeplayMarlinManager"
    
* If installing without CocoaPods, get the latest static library and header files [from the repository](https://github.com/veeplay/ios-marlin-drm).
* Import the VeeplayMarlinManager header file:
 
        #import "VeeplayMarlinManager.h"

* Instantiate a Marlin manager object and register it with the player:
        
        VeeplayMarlinManager *marlinManager = [[VeeplayMarlinManager alloc] init];
        [[APSMediaPlayer sharedInstance] registerUnitManager:marlinManager];
    
* Set the `managerType` property of the `APSMediaUnit` object to `@"marlin"`.
* Optionally, to have the player download and add a broadband license to the local store, you can set the `kAPSMetadataDrmUrl` key in the `metadata` dictionary of an item to the string URL to the license file. To configure from JSON, set the `drm_encoding_url` metadata key.

## Enabling Picture in Picture support

To enable Picture in Picture support please make sure you configured your project as described in [Apple's documentation](https://developer.apple.com/library/ios/documentation/WindowsViews/Conceptual/AdoptingMultitaskingOniPad/QuickStartForPictureInPicture.html) then:

* Import PiP backend's header file:

        #import <APSPiPPlayer.h>
        
* Set the backend player's class to `APSPipPlayer`:

        [[APSMediaPlayer sharedInstance] setBackendPlayerClass:[APSPiPPlayer class]];
        
* (Optional) Display the Picture in Picture control in the control bar by adding `APSPiPControl` to the `controlsParameters` property on `APSMediaUnit`:

        unit.controlsParameters = @{kAPSControlsComponents: @(APSPlaybackControl|APSCurrentTimeControl|APSTimeSliderControl|APSTotalTimeControl|kAPSChromecastControl|APSPiPControl)};
        
    * Alternatively you can display the Picture in Picture playback control in the control bar by adding `pictureInPicture` into the components array, under the `controls` section in your JSON configuration file:


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
                        "pictureInPicture"
                    ]
                }
            ]
        }

### Example Unit Configurations

* Configuring a unit progamatically:

        APSMediaUnit *unit = [[APSMediaUnit alloc] init];
        unit.url = [NSURL URLWithString:@"http://url.to/your-protected-media"];
        unit.managerType = kVeeplayMarlinDRMEncoding;
        unit.metadata = [NSMutableDictionary dictionaryWithDictionary: @{ kAPSMetadataDrmUrl: @"http://url.to/marlin-broadband-key" }];
        
* Configuring a unit from JSON:

        {
                "url": "http://url.to/your-protected-media",
                "manager": "marlin",
                "metadata": {
                        "drm_encoding_url": "http://url.to/marlin-broadband-key"
                }
        }

## Class Reference

See the full class reference [here](http://veeplay.github.io/ios-media-player/).

## Code Samples

See a showcase project featuring code samples for various playback scenarios [here](https://github.com/veeplay/ios-media-player/tree/master/Example).

If you have CocoaPods installed, you can instantly see a demo of the Veeplay player by typing `pod try Veeplay` in your Terminal.

## Requirements

APSMediaPlayer relies on the following liberally-licensed pods installed as dependencies:

* KAProgressLabel - [LICENSE](https://github.com/kirualex/KAProgressLabel/blob/master/LICENSE)
* TBXML - [LICENSE](https://github.com/71squared/TBXML)
* TSMiniWebBrowser - [LICENSE](https://github.com/tonisalae/TSMiniWebBrowser/blob/master/LICENSE)


## Author

Appscend Video Solutions GmbH

## License

Commercial license. Contact <sales@veeplay.com>.