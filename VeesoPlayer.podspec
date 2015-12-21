Pod::Spec.new do |s|
  s.name             = "VeesoPlayer"
  s.version          = "2.0.28"
  s.summary          = "Veeso Media Player"
  s.homepage         = "http://veeso.co"
  s.license          = 'Commercial'
  s.author           = { "Veeso" => "gabi@veeso.co" }
  s.source           = { :git => "https://github.com/veeso/ios-media-player.git", :tag => s.version.to_s }

  s.platform     = :ios, "6.0"
  s.requires_arc = true

  s.documentation_url = 'http://veeso.github.io/ios-docs'

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "Docs/*"
  s.library              = "VeesoPlayer", "z"
  s.vendored_libraries   = "libVeesoPlayer.a"

  s.frameworks = "AVFoundation", "MediaPlayer", "CoreMedia"
  s.dependency "KAProgressLabel", "~> 1.2"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "TSMiniWebBrowser"
  s.dependency "google-cast-sdk"
end
