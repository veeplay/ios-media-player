Pod::Spec.new do |s|
  s.name             = "Veeplay"
  s.version          = "3.2.4"
  s.summary          = "Veeplay Media Player - Crossplatform media player with video ads support"
  s.homepage         = "http://veeplay.com"
  s.license          = { :type => "Commercial", :text => "Contact office@veeplay.com" }
  s.author           = { "Veeplay" => "gabi@veeplay.com" }
  s.source           = { :git => "https://github.com/veeplay/ios-media-player.git", :tag => s.version.to_s }

  s.platforms    = { :ios => "10.0", :tvos => "11.0" }
  s.requires_arc = true

  s.documentation_url = 'http://veeplay.github.io/ios-media-player'

  s.ios.source_files = ['Headers/APSMediaPlayerOverlayController.h', 'Headers/APSTypes.h', 'Headers/APSEvent.h', 'Headers/APSMediaEvent.h', 'Headers/KRAdapter.h', 'Headers/APSMediaPlayerSSAIOverlayController.h', 'Headers/APSSSAIAd.h', 'Headers/APSVASTFullscreenButtonConfiguration.h', 'Headers/APSMediaUnit.h', 'Headers/APSControlPluginProtocol.h', 'Headers/APSVASTAdBreak.h', 'Headers/APSMediaPlayerImageOverlayController.h', 'Headers/APSMediaPlayerClosableOverlayController.h', 'Headers/APSMediaTrackableObject.h', 'Headers/APSVASTError.h', 'Headers/APSMediaOverlay.h', 'Headers/APSMediaPlayerControlsOverlayController.h', 'Headers/KRHub.h', 'Headers/APSAVPlayerView.h', 'Headers/APSTimedMetadata.h', 'Headers/APSYouTubeManager.h', 'Headers/APSVASTSkipOverlayController.h', 'Headers/APSMediaPlayerButtonOverlayController.h', 'Headers/APSUnitManagerProtocol.h', 'Headers/APSVASTSkipButtonConfiguration.h', 'Headers/APSAVPlayer.h', 'Headers/APSVASTFullscreenOverlayController.h', 'Headers/APSMediaPlayerHTMLOverlayController.h', 'Headers/APSMediaBuilderPlugin.h', 'Headers/APSMediaPlayer.h', 'Headers/APSMediaPlayerProtocol.h', 'Headers/APSVimeoManager.h', 'Headers/APSMediaPlayerTextOverlayController.h', 'Headers/APSMediaPlayerSubtitlesOverlayController.h', 'Headers/APSSSAIAdEvent.h', 'Headers/APSPiPPlayer.h', 'Headers/APSMediaBuilder.h', 'Headers/APSVASTBannerConfiguration.h', 'Headers/APSVASTCountdownConfiguration.h', 'Headers/APSVASTRegulationInformation.h', 'Headers/APSVASTMediaBuilderPlugin.h', 'Headers/APSAVPlayerViewController.h', 'Headers/AVPlayer+View.h', 'Headers/APSSSAIClient.h', 'Headers/APSMPMoviePlayer.h']
  s.tvos.source_files    = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.preserve_paths       = "Docs/*"
  s.library              = "z"
  s.ios.vendored_libraries   = "libVeeplay.a"
  s.tvos.vendored_libraries   = "libVeeplayTvOS.a"

  s.ios.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia", "AVKit", "SystemConfiguration", "SafariServices", "WebKit"
  s.tvos.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia", "AVKit", "SystemConfiguration"

  s.ios.dependency "KAProgressLabel", "~> 3.0"
  s.ios.dependency "Reachability"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "XCDYouTubeKit", "~> 2.5"
  s.dependency "YTVimeoExtractor", "~> 1.2"
  s.dependency "KVOController", "~> 1.2.0"
  s.dependency "PureLayout", "~> 3.1"
end





