Pod::Spec.new do |s|
  s.name             = "APSMediaPlayer"
  s.version          = "1.7.5"
  s.summary          = "Appscend Media Player"
  s.homepage         = "http://appscend.com"
  s.license          = 'Commercial'
  s.author           = { "Gabi Dobocan" => "gabi@appscend.com" }
  s.source           = { :git => "cocoapods.appscend.net:appscendvideoplayer.git", :tag => s.version.to_s }

  s.platform     = :ios, "5.0"
  s.requires_arc = true

  s.source_files         = "Headers/*.h"
  s.resources            = "Assets/*.bundle"
  s.public_header_files  = "Headers/*.h"
  s.preserve_paths       = "libAPSMediaPlayer.a", "Docs/*"
  s.library              = "APSMediaPlayer"
  s.xcconfig             =  { "LIBRARY_SEARCH_PATHS" => '"$(PODS_ROOT)/APSMediaPlayer"' }

  s.frameworks = "AVFoundation", "MediaPlayer"
  s.dependency "KAProgressLabel", "~> 1.2"
  s.dependency "TBXML", "~> 1.5"
  s.dependency "TSMiniWebBrowser"
end
