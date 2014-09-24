Pod::Spec.new do |s|
  s.name             = "VeesoPlayer"
  s.version          = "1.8.6"
  s.summary          = "Veeso Media Player"
  s.homepage         = "http://veeso.co"
  s.license          = 'Commercial'
  s.author           = { "Veeso" => "gabi@veeso.co" }
  s.source           = { :git => "https://github.com/veeso/ios-media-player.git", :tag => s.version.to_s }

  s.platform     = :ios, "5.0"
  s.requires_arc = true

  s.documentation_url = 'http://veeso.github.io/ios-docs'

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "libVeesoPlayer.a", "Docs/*"
  s.library              = "VeesoPlayer", "z"
  s.xcconfig             =  { "LIBRARY_SEARCH_PATHS" => '"$(PODS_ROOT)/VeesoPlayer"' }

  s.frameworks = "AVFoundation", "MediaPlayer"
  s.dependency "KAProgressLabel", "~> 1.2"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "TSMiniWebBrowser"
end