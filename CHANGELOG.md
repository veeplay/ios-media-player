### 1.8.34
Use HTTPS for tracking requests

### 1.8.33
Fix a crash caused by invalid VAST data

### 1.8.32
Fix current time not updating sometimes after seeking using the seekbar.

### 1.8.31
Expose methods to set and get the sound volume

### 1.8.30
Option to update the current time while dragging the knot from the seek bar

### 1.8.29
Workaround for a crash in MPMoviePlayerController and iOS 8.4

### 1.8.28
Use a UIViewController instead of MTZoomWindow for fullscreen support

### 1.8.27
Provide an interface to disable internal fullscreen handling

### 1.8.26
Fix a potential crash when the current unit could not be retrieved

### 1.8.25
Workaround for MPMoviePlayerController to correctly report currentPlaybackTime while seeking

### 1.8.24
Fix for MPMoviePlayerController still reporting old current time while seeking

### 1.8.23
Fix removal of units which haven't preloaded yet

### 1.8.22
Fix unwanted removal of latest item in playlist when seeking 

### 1.8.21
Fix skipping ads when seeking

### 1.8.20
Accept values with format #RRGGBB on aps_colorFromHexString

### 1.8.19
Fix skipping ads by seeking in the media file

### 1.8.18
Configure fullscreen button in ads with transparent border by default

### 1.8.17
Added fullscreen button on ads

### 1.8.16
Fixed issue with unwanted resuming of playback after coming back from background or from a modal view controller.

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