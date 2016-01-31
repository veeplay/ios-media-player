Pod::Spec.new do |s|
  s.name             = "Veeplay"
  s.version          = "2.1"
  s.summary          = "Veeplay Media Player"
  s.homepage         = "http://veeplay.com"
  s.license          = 'Commercial'
  s.author           = { "Veeplay" => "gabi@veeplay.com" }
  s.source           = { :git => "https://github.com/veeplay/ios-media-player.git", :tag => s.version.to_s }

  s.platform     = :ios, "6.0"
  s.requires_arc = true

  s.documentation_url = 'http://veeplay.github.io/ios-docs'

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "Docs/*"
  s.library              = "z"
  s.vendored_libraries   = "libVeeplay.a"

  s.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia"
  s.dependency "KAProgressLabel", "~> 3.0"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "TSMiniWebBrowser"
end