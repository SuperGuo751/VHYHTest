//
// VHCCore.h
// 
//
//  Created by vhall on 2019/11/19.
//  Copyright © 2019 vhall. All rights reserved.
//

#import <Foundation/Foundation.h>


#define VHCGetLogin_audience    @"/api/auth/login-common" //登录



NS_ASSUME_NONNULL_BEGIN

@interface VHCCore : NSObject

/** 组件列表 */
@property (nonatomic, strong) NSMutableArray *components;
//config配置
@property (nonatomic, strong) NSDictionary *context;

///<版本，3：v3 4：v4
@property (nonatomic, assign) NSInteger platform;

/** app_id */
@property(nonatomic, copy) NSString * app_id;
/** secret_key */
@property(nonatomic, copy) NSString * secret_key;
/** app_host */
@property(nonatomic, copy) NSString * app_host;
@property(nonatomic, copy) NSString * vss_host;

/** 连续进入校验 */
@property(nonatomic, assign) BOOL entering;
/** 连续进入校验 */
@property(nonatomic, strong) NSDate *enteringDate;

//是否为直播间跳转直播间
@property(nonatomic, assign) BOOL isLiveToLive;
/**
 * @brief 单例方法。
 * @return 返回单例对象。
 */
+ (instancetype)sharedInstance;

/**
 * @brief 向Core注册模块的方法。
 * @param componentClass 组件类
 */
+ (BOOL)registerComponentClass:(Class)componentClass;

/*！
 * 用来获得当前sdk的版本号
 * return 返回sdk版本号
 */
+ (NSString *) sdkVersion;

/*！
 *  注册app
 *  @param app_id       vhall后台注册生成的app_id
 *  @param secretKey    vhall后台注册生成的secret_key
 *  @param app_host     接口app_host地址
 *  @param vss_host     接口vss_host地址
 *
 */
+ (void)registerApp_id:(NSString *)app_id secret_key:(NSString *)secret_key app_host:(NSString *)app_host vss_host:(NSString *)vss_host;

/*!
 *  是否开启日志
 *  @param open 是否开启日志，默认 false
 */
+(void)openVhallSdkDebug:(BOOL)open;



/// 打印除VHCCore和VHUICore之外其他所有组件
+ (void)printAllComponent;



/// 判断某个组件是否加载
/// @param name 组件名
+ (BOOL)isLoadedComponentName:(NSString *)name;

// 加载主框架
+ (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;


/*！
 *  登录接口
 *  @param phone  手机号；白名单模式下必传参数
 *  @param code   短信验证码；白名单模式下必传参数
 *  @param mode   登录模式； 0->自动识别模式（默认）， 1->普通游客登录， 2->白名单登录， 3->授权模式uuid登录， 4->授权模式uuid + 白名单，5->银河客户号登录绑定账号
 */
+ (void)loginWithPhone:(NSString *)phone
                  code:(NSString *)code
                  mode:(NSInteger)mode
                roomid:(NSString*)roomid
                sucess:(void(^)(void))sucessBlock
               failure:(void(^)(NSString *msg))failureBlock;

/** 进入房间
 * il_id 房间号
 * userInfo 用户信息
 * isPushAnimation 是否使用push动画
 */
+ (void)enterRoomIl_id:(NSString *)il_id
              userInfo:(NSDictionary *)userInfo
       isPushAnimation:(BOOL)isPushAnimation
                sucess:(void(^)(void))sucessBlock
               failure:(void(^)(NSString *msg))failureBlock;

/**
 关闭画中画模式
 */
- (void)closePiPView;

/**
 * 获取当前显示的控制器
 */
+ (UIViewController *)getCurrentVC;

@end

NS_ASSUME_NONNULL_END

