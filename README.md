# APSMediaPlayer

The Appscend Media Player allows you to:
* Create playlists of synchronized videos and overlays
* Configure a playlist from an external JSON file, an equivalent NSDictionary structure or directly via code attributes
* Create custom, native overlays
* Automatically configure ad linear inserts (pre, mid and post rolls) as well as nonlinear inserts (banner overlays), VAST 1.0, 2.0, 3.0 and VMAP 1.0 compliant
* Create custom player skins, brand player with logo, insert overlay bugs, customize player controls
* Track video and overlay lifecycle events in real-time, as rendered

## Usage

Import the Player’s header file, as well as the VAST/VMAP or other plugins:

`#import "APSMediaPlayer.h" 
#import "APSVASTMediaBuilderPlugin.h"`

Create a new APSMediaBuilder instance, add plugins and configure from remote JSON: 

`APSMediaBuilder *builder = [[APSMediaBuilder alloc] init]; 
[builder addPlugin:[[APSVASTMediaBuilderPlugin alloc] init]]; 
[builder configureFromURL:[NSURL 
URLWithString:@"http://domain.com/player.json"]];`
 
Optionally, set the debugMode flag to YES to enable console logging: 
`builder.debugMode = YES;`
 
Add the media player to a view: 
`[APSMediaPlayer sharedInstance].view.frame = CGRectMake(5, 5, 310, 
450); 
[self.view addSubview:[APSMediaPlayer sharedInstance].view];`
 
Play content as configured: 
`[[APSMediaPlayer sharedInstance] playMediaUnits:[builder mediaUnits]];`

Note that calling mediaUnits should be done on a non-UI thread. 


## Requirements

APSMediaPlayer relies on the following liberally-licensed pods installed as dependencies:
* KAProgressLabel (https://github.com/kirualex/KAProgressLabel/blob/master/LICENSE)
* TBXML (https://github.com/71squared/TBXML)
* TSMiniWebBrowser (https://github.com/tonisalae/TSMiniWebBrowser/blob/master/LICENSE)

## Installation



## Author

Appscend Video Solutions GmbH

## License

Commercial license. Contact sales@appscend.com.

