### 1.8.2
This release adds support for defining custom overlay controllers, as well as several new features.
* Mid-rolls and banner ads scheduled for fixed time intervals are now inserted dinamically within a live stream.
* Developers can create custom overlay controllers, by inheriting from `APSMediaPlayerOverlayController`, implementing the `type` and `load` methods (at least), and registering the controller class with the player, using `[[APSMediaPlayer sharedInstance] registerClass:[CLASSNAME class] inGroup:kAPSMediaPlayerOverlayControllersGroup type:@"TYPE"];`
* Units and overlays now expose a mutable dictionary for metadata storage. Overlay controllers can use metadata information to implement custom functionality.
* You can now configure the action the player should take with banner ads and video ads, after they are tapped and after the web browser they display is later closed by the user (close the banner/skip the ad or continue to display the ad for the rest of the normal lifespan).
* The player can now be configured to stop functioning on devices that are detected as jailbroken.
* The list of accepted video ad mime types, as well as the order of preference for them is now configurable.
* The player now supports "youtu.be" short links for Youtube content.
* Live streaming detection added, configurable text for the total duration and current playback time components of the controls bar.

### 1.8.1
 * Release 1.8.1
 * Fixed overlay configuration issue