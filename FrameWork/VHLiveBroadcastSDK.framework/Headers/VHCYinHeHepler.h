//
//  VHCYinHeHepler.h
//  VHCCore
//
//  Created by liukang on 2022/4/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VHCYinHeSDK <NSObject>

@required

/**
 分享API
 @param params NSDictionary类型
 {
     "channelId" : 0,
     "link" : "分享链接",
     "title" : ""
     "desc" : "描述信息"
 }
 channelId(分享渠道)主要分享渠道 1:微信好友 2:微信朋友圈
 link(分享链接)
 title(分享标题)
 desc 描述信息
 thumbimage(图片链接地址)
 @param block 分享完成后回调
 回调参数为 NSDictionary类型
 */
- (void)shareWithParams:(NSDictionary *)params completion:(void(^)(NSDictionary * result))block;

/**
 跳转银河H5页面
 @param param @{url:跳转链接, extraParam:参数}
 @param block 回调
 */
- (void)supplyYinheH5:(NSDictionary *)param completion:(void(^)(BOOL success))block;

/**
 获取用户信息 如：画中画点击 是否关闭
 param
 @param block 回调
 */
- (void)transmitParam:(NSDictionary*)param userInfo:(void(^)(NSDictionary *info))block;


@end



@interface VHCYinHeHepler : NSObject<VHCYinHeSDK>

+ (instancetype)shared;

- (void)registerYinHeSDK:(id<VHCYinHeSDK>)yinHeSDK; //初始化VHall时注入实现该协议对象


@end

NS_ASSUME_NONNULL_END
