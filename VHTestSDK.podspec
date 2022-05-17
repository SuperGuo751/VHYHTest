#
#  Be sure to run `pod spec lint VHTestSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

source 'https://github.com/CocoaPods/Specs.git'

Pod::Spec.new do |spec|

  s.name             = "VHYHTest"
  s.module_name      = 'VHYHTest'
  s.summary          = "VHYHTest"
  s.description      = "<<-DESC DESC 测试用的sdk"

  s.version          = "0.0.2"
  s.frameworks      = 'Foundation'
  s.requires_arc    = true
  s.platform        = :ios, '9.0'
  s.license         = 'MIT'

  s.author           = { "gc" => "guochao751082551@163.com" }
  s.source           = { :git => "git@github.com:SuperGuo751/VHYHTest.git",:tag => s.version.to_s }
  s.homepage         = "https://gitee.com/kangler/vhtest-sdk.git"

  s.vendored_frameworks = 'FrameWork/VHLiveBroadcastSDK.framework'
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'armv7 arm64'
  }

end
