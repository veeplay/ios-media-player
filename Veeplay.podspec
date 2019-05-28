Pod::Spec.new do |s|
  s.name             = "Veeplay"
  s.version          = "3.0.3"
  s.summary          = "Veeplay Media Player - Crossplatform media player with video ads support"
  s.homepage         = "http://veeplay.com"
  s.license          = { :type => "Commercial", :text => "Contact office@veeplay.com" }
  s.author           = { "Veeplay" => "gabi@veeplay.com" }
  s.source           = { :git => "https://github.com/veeplay/ios-media-player.git", :tag => s.version.to_s }

  s.platform     = :ios, "8.0"
  s.requires_arc = true

  s.documentation_url = 'http://veeplay.github.io/ios-media-player'

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "Docs/*"
  s.library              = "z"
  s.vendored_libraries   = "libVeeplay.a"

  s.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia", "AVKit", "SystemConfiguration"
  s.dependency "KAProgressLabel", "~> 3.0"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "KINWebBrowser", "~> 1.3"
  s.dependency "Reachability"
  s.dependency "XCDYouTubeKit", "~> 2.5"
  s.dependency "YTVimeoExtractor", "~> 1.2"
  s.dependency "KVOController", "~> 1.2.0"
  s.dependency "PureLayout", "~> 3.1"
end