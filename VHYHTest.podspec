# source 'https://github.com/CocoaPods/Specs.git'

Pod::Spec.new do |s|

  s.name             = "VHYHTest"
  s.module_name      = 'VHYHTest'
  s.summary          = "VHYHTest"
  s.description      = "<<-DESC DESC 测试用的sdk"

  s.version          = "0.0.4"
  s.frameworks      = 'Foundation'
  s.requires_arc    = true
  s.platform        = :ios, '9.0'
  s.license         = 'MIT'

  s.author           = { "gc" => "guochao751082551@163.com" }
  s.source           = { :git => "git@github.com:SuperGuo751/VHYHTest.git",:tag => s.version.to_s }
  s.homepage         = "https://github.com/SuperGuo751/VHYHTest"

  s.vendored_frameworks = 'FrameWork/VHLiveBroadcastSDK.framework'
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'armv7 arm64'
  }

end
