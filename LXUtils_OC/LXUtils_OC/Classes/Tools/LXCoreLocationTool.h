//
//  LXCoreLocationTool.h
//  lXUtils_OC
//
//  Created by Xiao.Li on 2017/12/25.
//  Copyright © 2017年 LXUtils. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "UserAddressModel.h"

/**
 *  使用注意:
 *  1.要在使用中创建一个全局变量，不然会销毁导致获取不到位置
 *  info.plist 中添加一项
 *  NSLocationAlwaysUsageDescription ： 请求授权
 *
 *          CLPlacemark
 *
 *  location            地理位置
 *  region              区域
 *  addressDictionary   详细的地址信息
 *  name                地址名称
 *  locality            城市名称
 */
typedef void (^locationOption)(CLLocation *location);

@interface LXCoreLocationTool : NSObject

@property (nonatomic, copy) locationOption option;

/**
 *  获取用户所在位置
 *
 *  @param option CLLocation
 */
- (void)getLocation:(locationOption) option;

/**
 *  地理编码
 */
- (void) geocodeAddressString:(NSString *) addressString userAddress:(void (^)(CLPlacemark *placemark)) placemark;

/**
 *  反地理编码
 */
-(void) reverseGeocodeLocation:(CLLocation *)location userAddress:(void (^)(UserAddressModel *userAddress)) userAddress;

@end
