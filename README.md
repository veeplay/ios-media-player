## About

![Veeso](http://veeso.co/img/veeso.png)

The Veeso Media Player allows you to:

* Create playlists of synchronized videos and overlays
* Configure a playlist from an external JSON file, an equivalent NSDictionary structure or directly via code attributes
* Create custom, native overlays
* Automatically configure ad linear inserts (pre, mid and post rolls) as well as nonlinear inserts (banner overlays), VAST 1.0, 2.0, 3.0 and VMAP 1.0 compliant
* Create custom player skins, brand player with logo, insert overlay bugs, customize player controls
* Track video and overlay lifecycle events in real-time, as rendered

## Installation

There are currently two integration paths: via CocoaPods or via standard library download.

1. **Installing via CocoaPods (recommended)**
		
	- Add the following line to your podfile:
	
			pod 'VeesoPlayer'
		
	- Run `pod install` to install the player and all the dependencies. Run `pod update` to keep the library updated.
	
2. **Installing via library download**

	- Add `MediaPlayer.framework` and `AVFoundation.framework` to your project.
	
		- Select your target in the project settings screen.
		- Select the “Build Phases” tab.
		- Expand the “Link Binary With Libraries” area.
		- Click the “+” button, and add “MediaPlayer.framework” and “AVFoundation.framework” to your project.
		
	- Add the player’s static library to your project.
	
		- Drag the “libAPSMediaPlayer.a” file to your project.
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
	
		- Drag all the files in the “resources” folder into your Xcode project.
		- When prompted, make sure to check the project target that should include the resources.
		

## Getting Started

Set up an account at http://panel.veeso.co and add your application's bundle identifier under "License Management".

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

## Requirements

APSMediaPlayer relies on the following liberally-licensed pods installed as dependencies:

* KAProgressLabel - [LICENSE](https://github.com/kirualex/KAProgressLabel/blob/master/LICENSE)
* TBXML - [LICENSE](https://github.com/71squared/TBXML)
* TSMiniWebBrowser - [LICENSE](https://github.com/tonisalae/TSMiniWebBrowser/blob/master/LICENSE)


## Author

Appscend Video Solutions GmbH

## License

Commercial license. Contact <sales@veeso.co>.

