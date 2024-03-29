### 3.2.14
* Removed TBXML dependency

### 3.2.13
* Fix a crash when retrieving ads with mezzanines from buffets

### 3.2.12
* Alleviate a crash when retrieving ads from buffets

### 3.2.11
* Updated VAST dead end error handling

### 3.2.10
* Fix an issue regarding a missing header file on setups without Google IMA

### 3.2.9
* Ability to pause/unpause and check the current status of IMA ad breaks
* Fix an issue with fullscreen icon status when `internalFullscreenSupport` is disabled

### 3.2.8
* Handle 303 VAST Error (no ads)
* Added event for ad break load

### 3.2.4
* Fix tvOS build
* Fix build issue

### 3.2.3
* Improved viewability support

### 3.2.1
* Fix a crash when using invalid URLs in JSON configs
* Viewability improvements
* Added `pausesOnViewabilityLost` to automatically pause the video when media player goes out of the view

### 3.2.0
* Preliminary (alpha) tvOS support

### 3.1.9
* Added opt-in support for playing videos while the app is in background

### 3.1.8
* Fix an issue when `complete` tracking is not sent when calling `[APSMediaPlayer stop]` right after video ends
* Added nullability annotations
* Added multiple audio track support

### 3.1.7
Fix an issue with encoding tracking URLs

### 3.1.6
* Fix an issue when `[APSMediaPlayer stop]` is called when an item finishes playing and the "complete" tracking is not sent
* Add `debug` property on `APSMediaPlayer` to enable logging
* Fix `debug` property on `APSVASTAdBreak` not being passed to generated units

### 3.1.5
Replaced UIWebView with WKWebView
Removed YouTube and Vimeo overlays and replaced them with unit managers

### 3.1.4
Fix "complete", "close" and "closeLinear" events not being tracked

### 3.1.3
Added `adBreakRequested` and `adBreakTriggered` tracking events

### 3.1.2
Fix a crash caused by invalid VAST files

### 3.1.1
Move IMA support in a different Pod

### 3.1.0
Opt-in support for using Google IMA SDK instead of internal VAST parser

### 3.0.15
Fix a layout issue in default controls bar

### 3.0.14
Fix a condition when the video player would continue playing media units after it was stopped

### 3.0.13
Stability improvements

### 3.0.12
Use an iOS 10 compatible way to create ISO 8601 dates.

### 3.0.11
Fix a crash which occured when an invalid URL was provided as a tracking URL

### 3.0.10
Fix a bug when fullscreen overlays weren't properly removed from screen after an unit ends playing

### 3.0.9
Disabled MPMoviePlayerController-based backend on iOS 13

### 3.0.8
SSAI streams support

### 3.0.7
Fix UI calls from background threads
Support for LIMITADTRACKING, REGULATIONS and GDPRCONSENT macros

### 3.0.6
Minor bugfix regarding ad counter

### 3.0.5
Fix loading activity indicator appearing over playing video

### 3.0.4
Show loading activity indicator while VAST data is retrieved.
Support for `LIMITADTRACKING`, `REGULATIONS` and `GDPRCONSENT` VAST Macros.

### 3.0.3
Use `userAgent` property for [CLIENTUA], if available

### 3.0.2
Fix missing dependency in pod variant

### 3.0.1
Process macros in VAST URLs

### 3.0.0
VAST 4.1 and DAST support
Rewrote overlays to use Autolayout

### 2.9.10
Fix a bug when ad breaks from an old playlist would act on the current one

### 2.9.9
Fix `APSMediaPlayerEventPlaylistFinish` being called when setting up the player

### 2.9.8
Fix build dependency issue

### 2.9.7
Migrate UI to AutoLayout for iPhone X support

### 2.9.6
Preliminary VAST 4 support

### 2.9.5
Use NSURLSession instead of deprecated NSURLConnection for tracking urls

### 2.9.4
New property added on APSMediaPlayer to set the User-Agent for HTTP requests

### 2.9.3
Fix a crash which occurs when receiving invalid VAST URLs

### 2.9.2
Fix UI thread being blocked by requesting duration from AVPlayer

### 2.9.1
Fix some video not being played because of slow state changes in AVPlayer

### 2.9.0
Support for "subtitlesUrl" property in media units

### 2.8.9
Stability improvements in APSAVPlayer

### 2.8.8
Fix URL encoding issue in APSAVPlayer

### 2.8.6
Fix missing KVOController dependency in Podspec

### 2.8.5
Fix crashes caused by objects being deallocated while still having observers attached to them
Fix small issue with AVPlayer backend

### 2.8.4
Fix overlapping media issue

### 2.8.3
Stability improvements

### 2.8.2
New unit manager for Vimeo videos

### 2.8.1
Fix fullscreen window size in landscape mode

### 2.8.0
New unit manager for YouTube videos

### 2.7.0
Subtitles fixes
Fix an issue with seekbar layout when changing orientation

### 2.6.9
SRT subtitles support

### 2.6.8
Send a 'NSNotification' if retrieving VAST data fails

### 2.6.7
Added Reachability as a Cocoapods dependency

### 2.6.6
Fixed issue with seekbar having wrong width after view frame change

### 2.6.5
Added 'allowedAppInterfaceOrientation' property to allow overriding orientations defined in the .plist configurations / on the root view controller (in case the app manages view rotation independently). Use this if having issues with fullscreen functionality

### 2.6.4
* Expanded fullscreen orientation support
* Fixed issue with media unit timeout not triggering an error

### 2.6.3
* Added 'fullscreenOrientationBehaviour' property to allow setting a single permitted interface orientation for fullscreen playback
* Added 'APSMediaPlayerEventPlaylistFinish' event on playlist end

### 2.6.2
Fixed issue with invalid media playback errors not being triggered on AVPlayer backend

### 2.6.1
Fixed issue with AVPlayerItem generating a KVO crash on deallocation due to invalid media

### 2.5
Added support for spaces in media unit URLs

### 2.4
Stopping playback and emmiting an error notification when there is no connectivity to media host

### 2.3
Fixed compile warnings generated by module usage

### 2.2
PiP support

### 2.1
Cleanup release. Main changes:
* Now officially called `Veeplay` - deprecated the `VeesoPlayer` pod
* Separated VeeplayChromecast into separate plugin
* Replaced all MPMoviePlayer constants with own ones
* Updated thumbnail retrieval methods
* Switched doc generator to classic appledoc

### 2.0.29
Fix wrong behaviour when seeking back and using `APSHandleSeekEventPlayLastBreak`

### 2.0.28
Improved Voiceover support

### 2.0.27
Allow using of external media backends

### 2.0.26.4
Optimize AVPlayer-based backend initialization

### 2.0.26.3
Workaround for MPMoviePlayerController not sending MPMoviePlayerLoadStateDidChangeNotification sometimes

### 2.0.26.2
Fix a linker issue

### 2.0.26.1
Fix a random issue when UI was not properly updated when unit's initialPlayBackTime was greater than 0

### 2.0.26
Added accessibility labels and hints

### 2.0.25
Disable fullscreen on rotate if the application already supports that orientation

### 2.0.24.1
Further fullscreen related improvements

### 2.0.24
Rotate video when in fullscreen and landscape orientation is not supported

### 2.0.23.2
Another fix for currentPlaybackTime nor properly updated after seeking

### 2.0.23.1
Ignore Prerolls and midrolls until unit.initialPlaybackTime, if specified

### 2.0.23
Fix returning currentPlaybackTime while MPMoviePlayerController is seeking

### 2.0.22
Include ad ID in tracking notification

### 2.0.21
New leaveFullscreenOnStop property to configure the fullscreen behaviour on stop

### 2.0.20
Do not exit from fullscreen when stopping the player

### 2.0.19
Allow custom Application ID for Chromecast

### 2.0.18
Use HTTPS for tracking requests

### 2.0.17
Fix a crash caused by invalid VAST data

### 2.0.16
Fix current time not updating sometimes after seeking using the seekbar.

### 2.0.15
Expose methods to set and get the sound volume

### 2.0.14
Option to update the current time while dragging the knot from the seek bar

### 2.0.13
Fix current time not updating after seek

### 2.0.12
Workaround for a crash in MPMoviePlayerController and iOS 8.4

### 2.0.11
Use a UIViewController instead of MTZoomWindow for fullscreen support

### 2.0.10
Provide an interface to disable internal fullscreen handling

### 2.0.9
Fix removal of units which haven't preloaded yet

### 2.0.8
Fix unwanted removal of latest item in playlist when seeking

### 2.0.7
Fix crash caused by not properly removing KVO observers

### 2.0.6
Fix skipping ads when seeking

### 2.0.5
Chromecast support

### 2.0.4
Accept values with format #RRGGBB on aps_colorFromHexString

### 2.0.3
Fix an issue when going fullscreen while in landscape orientation

### 2.0.2
Fix orientation issues after a video was fullscreen

### 2.0.1
Asynchronously check if an asset is playable

### 2.0.0
Support for multiple backends (AVPlayer and MPMovieController)
Gapless playback between ads and content


### 3.2.4
* Fix tvOS build
* Fix build issue

### 3.2.3
* Improved viewability support

### 3.2.1
* Fix a crash when using invalid URLs in JSON configs
* Viewability improvements
* Added `pausesOnViewabilityLost` to automatically pause the video when media player goes out of the view

### 3.2.0
* Preliminary (alpha) tvOS support

### 3.1.9
* Added opt-in support for playing videos while the app is in background

### 3.1.8
* Fix an issue when `complete` tracking is not sent when calling `[APSMediaPlayer stop]` right after video ends
* Added nullability annotations
* Added multiple audio track support

### 3.1.7
Fix an issue with encoding tracking URLs

### 3.1.6
* Fix an issue when `[APSMediaPlayer stop]` is called when an item finishes playing and the "complete" tracking is not sent
* Add `debug` property on `APSMediaPlayer` to enable logging
* Fix `debug` property on `APSVASTAdBreak` not being passed to generated units

### 3.1.5
Replaced UIWebView with WKWebView
Removed YouTube and Vimeo overlays and replaced them with unit managers

### 3.1.4
Fix "complete", "close" and "closeLinear" events not being tracked

### 3.1.3
Added `adBreakRequested` and `adBreakTriggered` tracking events

### 3.1.2
Fix a crash caused by invalid VAST files

### 3.1.1
Move IMA support in a different Pod

### 3.1.0
Opt-in support for using Google IMA SDK instead of internal VAST parser

### 3.0.15
Fix a layout issue in default controls bar

### 3.0.14
Fix a condition when the video player would continue playing media units after it was stopped

### 3.0.13
Stability improvements

### 3.0.12
Use an iOS 10 compatible way to create ISO 8601 dates.

### 3.0.11
Fix a crash which occured when an invalid URL was provided as a tracking URL

### 3.0.10
Fix a bug when fullscreen overlays weren't properly removed from screen after an unit ends playing

### 3.0.9
Disabled MPMoviePlayerController-based backend on iOS 13

### 3.0.8
SSAI streams support

### 3.0.7
Fix UI calls from background threads
Support for LIMITADTRACKING, REGULATIONS and GDPRCONSENT macros

### 3.0.6
Minor bugfix regarding ad counter

### 3.0.5
Fix loading activity indicator appearing over playing video

### 3.0.4
Show loading activity indicator while VAST data is retrieved.
Support for `LIMITADTRACKING`, `REGULATIONS` and `GDPRCONSENT` VAST Macros.

### 3.0.3
Use `userAgent` property for [CLIENTUA], if available

### 3.0.2
Fix missing dependency in pod variant

### 3.0.1
Process macros in VAST URLs

### 3.0.0
VAST 4.1 and DAST support
Rewrote overlays to use Autolayout

### 2.9.10
Fix a bug when ad breaks from an old playlist would act on the current one

### 2.9.9
Fix `APSMediaPlayerEventPlaylistFinish` being called when setting up the player

### 2.9.8
Fix build dependency issue

### 2.9.7
Migrate UI to AutoLayout for iPhone X support

### 2.9.6
Preliminary VAST 4 support

### 2.9.5
Use NSURLSession instead of deprecated NSURLConnection for tracking urls

### 2.9.4
New property added on APSMediaPlayer to set the User-Agent for HTTP requests

### 2.9.3
Fix a crash which occurs when receiving invalid VAST URLs

### 2.9.2
Fix UI thread being blocked by requesting duration from AVPlayer

### 2.9.1
Fix some video not being played because of slow state changes in AVPlayer

### 2.9.0
Support for "subtitlesUrl" property in media units

### 2.8.9
Stability improvements in APSAVPlayer

### 2.8.8
Fix URL encoding issue in APSAVPlayer

### 2.8.6
Fix missing KVOController dependency in Podspec

### 2.8.5
Fix crashes caused by objects being deallocated while still having observers attached to them
Fix small issue with AVPlayer backend

### 2.8.4
Fix overlapping media issue

### 2.8.3
Stability improvements

### 2.8.2
New unit manager for Vimeo videos

### 2.8.1
Fix fullscreen window size in landscape mode

### 2.8.0
New unit manager for YouTube videos

### 2.7.0
Subtitles fixes
Fix an issue with seekbar layout when changing orientation

### 2.6.9
SRT subtitles support

### 2.6.8
Send a 'NSNotification' if retrieving VAST data fails

### 2.6.7
Added Reachability as a Cocoapods dependency

### 2.6.6
Fixed issue with seekbar having wrong width after view frame change

### 2.6.5
Added 'allowedAppInterfaceOrientation' property to allow overriding orientations defined in the .plist configurations / on the root view controller (in case the app manages view rotation independently). Use this if having issues with fullscreen functionality

### 2.6.4
* Expanded fullscreen orientation support
* Fixed issue with media unit timeout not triggering an error

### 2.6.3
* Added 'fullscreenOrientationBehaviour' property to allow setting a single permitted interface orientation for fullscreen playback
* Added 'APSMediaPlayerEventPlaylistFinish' event on playlist end

### 2.6.2
Fixed issue with invalid media playback errors not being triggered on AVPlayer backend

### 2.6.1
Fixed issue with AVPlayerItem generating a KVO crash on deallocation due to invalid media

### 2.5
Added support for spaces in media unit URLs

### 2.4
Stopping playback and emmiting an error notification when there is no connectivity to media host

### 2.3
Fixed compile warnings generated by module usage

### 2.2
PiP support

### 2.1
Cleanup release. Main changes:
* Now officially called `Veeplay` - deprecated the `VeesoPlayer` pod
* Separated VeeplayChromecast into separate plugin
* Replaced all MPMoviePlayer constants with own ones
* Updated thumbnail retrieval methods
* Switched doc generator to classic appledoc

### 2.0.29
Fix wrong behaviour when seeking back and using `APSHandleSeekEventPlayLastBreak`

### 2.0.28
Improved Voiceover support

### 2.0.27
Allow using of external media backends

### 2.0.26.4
Optimize AVPlayer-based backend initialization

### 2.0.26.3
Workaround for MPMoviePlayerController not sending MPMoviePlayerLoadStateDidChangeNotification sometimes

### 2.0.26.2
Fix a linker issue

### 2.0.26.1
Fix a random issue when UI was not properly updated when unit's initialPlayBackTime was greater than 0

### 2.0.26
Added accessibility labels and hints

### 2.0.25
Disable fullscreen on rotate if the application already supports that orientation

### 2.0.24.1
Further fullscreen related improvements

### 2.0.24
Rotate video when in fullscreen and landscape orientation is not supported

### 2.0.23.2
Another fix for currentPlaybackTime nor properly updated after seeking

### 2.0.23.1
Ignore Prerolls and midrolls until unit.initialPlaybackTime, if specified

### 2.0.23
Fix returning currentPlaybackTime while MPMoviePlayerController is seeking

### 2.0.22
Include ad ID in tracking notification

### 2.0.21
New leaveFullscreenOnStop property to configure the fullscreen behaviour on stop

### 2.0.20
Do not exit from fullscreen when stopping the player

### 2.0.19
Allow custom Application ID for Chromecast

### 2.0.18
Use HTTPS for tracking requests

### 2.0.17
Fix a crash caused by invalid VAST data

### 2.0.16
Fix current time not updating sometimes after seeking using the seekbar.

### 2.0.15
Expose methods to set and get the sound volume

### 2.0.14
Option to update the current time while dragging the knot from the seek bar

### 2.0.13
Fix current time not updating after seek

### 2.0.12
Workaround for a crash in MPMoviePlayerController and iOS 8.4

### 2.0.11
Use a UIViewController instead of MTZoomWindow for fullscreen support

### 2.0.10
Provide an interface to disable internal fullscreen handling

### 2.0.9
Fix removal of units which haven't preloaded yet

### 2.0.8
Fix unwanted removal of latest item in playlist when seeking

### 2.0.7
Fix crash caused by not properly removing KVO observers

### 2.0.6
Fix skipping ads when seeking

### 2.0.5
Chromecast support

### 2.0.4
Accept values with format #RRGGBB on aps_colorFromHexString

### 2.0.3
Fix an issue when going fullscreen while in landscape orientation

### 2.0.2
Fix orientation issues after a video was fullscreen

### 2.0.1
Asynchronously check if an asset is playable

### 2.0.0
Support for multiple backends (AVPlayer and MPMovieController)
Gapless playback between ads and content
