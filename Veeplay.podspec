Pod::Spec.new do |s|
  s.name             = "Veeplay"
  s.version          = "3.2.14"
  s.summary          = "Veeplay Media Player - Crossplatform media player with video ads support"
  s.homepage         = "http://veeplay.com"
  s.license          = { :type => "Commercial", :text => "Contact office@veeplay.com" }
  s.author           = { "Veeplay" => "gabi@veeplay.com" }
  s.source           = { :git => "https://github.com/veeplay/ios-media-player.git", :tag => s.version.to_s }

  s.platforms    = { :ios => "13.0", :tvos => "13.0" }
  s.requires_arc = true

  s.documentation_url = 'http://veeplay.github.io/ios-media-player'

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "Docs/*"
  s.library              = "z"
  s.ios.vendored_libraries   = "libVeeplay.a"
  s.tvos.vendored_libraries   = "libVeeplayTvOS.a"

  s.ios.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia", "AVKit", "SystemConfiguration", "SafariServices", "WebKit"
  s.tvos.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia", "AVKit", "SystemConfiguration"

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'EXCLUDED_ARCHS[sdk=appletvsimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'EXCLUDED_ARCHS[sdk=appletvsimulator*]' => 'arm64' }

  s.ios.dependency "KAProgressLabel", "~> 3.0"
  s.ios.dependency "Reachability"
  s.dependency "XCDYouTubeKit", "~> 2.5"
  s.dependency "YTVimeoExtractor", "~> 1.2"
  s.dependency "KVOController", "~> 1.2.0"
  s.dependency "PureLayout", "~> 3.1"
end
