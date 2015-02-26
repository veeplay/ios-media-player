### 1.8.15
Exposed AirPlay control properties (allowsAirPlay and airPlayVideoActive).

### 1.8.14
Added metadata support to ad breaks.

### 1.8.13
Fixed issue with multiple impressions and pause events being sent when clicking on ads.
Fixed issue playing midrolls at a certain time interval inside a live stream.
Fixed issue with resuming playback after tapping on video ads in certain configurations.

### 1.8.12
Fixed issue with event tracking.

### 1.8.11
Fixed issue with the creation of exit units via JSON/Dictionary configuration.

### 1.8.10
Fixed issue with adding quote-encoding to URLs read via VAST.

### 1.8.9
Added parameter that allows using the advertising identifier in ad requests.

### 1.8.8
Veeso now supports mid-content ads (banners or midroll videos) that can be automatically scheduled to fit the main video duration, according to configurable parameters. For more details, see the `midcontentAdMinimumInitialOffset`, `midcontentAdMinimumFinalOffset` and `midcontentAdMinimumSpacing` parameters of `APSMediaUnit`.

### 1.8.7
This release fixes the following issues:

* A pause VAST event being sent between ads
* VAST Fallback not working

Also, a new unit configuration is available that allows choosing how many ads should be rendered when seeking in a video.

### 1.8.6
* The player frame should be set using the `setFrame` method, now available
* Fullscreen-related issues have been fixed, with iOS 8 support
* Tapping on ads now preserves the fullscreen status
* Fixed issue with MRAID expandables while in fullscreen mode

### 1.8.5
* This release fixes a series of issues that some media files with progressive download display in certain playback scenarios, including:
  * Setting an initial playback time
  * Resuming from a midroll block
  * Resuming from a web browser window
* Fixed bug with displaying midrolls on DRM units

### 1.8.4
* This release brings support for unit managers. Unit managers are external objects that implement dynamic playback operations. Use them if you need to generate media URLs using timestamps or for implementing DRM support. See APSUnitManagerProtocol for more details.

### 1.8.3
* This release brings support for creating events that get triggered dynamically during playback, with async preload support. See `APSMediaEvent` documentation for detailed information.
* Ad breaks are now individually configurable via JSON/NSDictionary.
* Fixed issue with stalled media that would not automatically resume playback.
* Fixed bug related to controls visibility

### 1.8.2
This release adds support for defining custom overlay controllers, as well as several new features.

* Mid-rolls and banner ads scheduled for fixed time intervals are now inserted dynamically within a live stream.
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