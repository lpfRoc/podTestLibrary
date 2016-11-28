//
//  Utils.h
//  FaFa
//
//  Created by mac on 12-9-29.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

#define HEXCOLOR_ALPHA(c) [UIColor colorWithRed:((c>>24)&0xFF)/255.0 green:((c>>16)&0xFF)/255.0 blue:((c>>8)&0xFF)/255.0 alpha:((c)&0xFF)/255.0];
#define WE_TEAM_ACCOUNT @"wefafa@fafatime.com"

@interface YFMUtils : NSObject

+(int)indexOfArray:(Byte *)arr Length:(int)length StartPos:(int)startpos SplitChar:(Byte)splitchar;
+ (int) GetAvailTCPListenPort;
+(void) createDirectory:(NSString *)dirname;
+ (NSData*)writeImage:(UIImage*)image toFileAtPath:(NSString*)aPath;
+ (UIImage *)snapshot:(UIView *)view;
//等比缩放
+ (UIImage *)scaleImage:(UIImage *)image toScale:(float)scaleSize;
//自定长宽
+ (UIImage *)reSizeImage:(UIImage *)image toSize:(CGSize)reSize;
+(UIImage*)getSubImage:(UIImage *)image mCGRect:(CGRect)mCGRect centerBool:(BOOL)centerBool;
+(UIImage *)rotateImage:(UIImage *)aImage dir:(int)orient;
+(void)imageViewDrawLine:(UIImageView *)imageView fromPoint:(CGPoint)startpoint toPoint:(CGPoint)endpoint lineWidth:(CGFloat)lineWidth lineColor:(UIColor *)lineColor;

+ (NSDate *)stringToDate:(NSString *)dateString;
+ (NSString *)dateToString:(NSDate *)currentdate Format:(NSString *)formatStr;
+ (NSString *)getGMTDateString:(NSNumber *)dateNumber Format:(NSString *)formatStr;

+(UIColor *)getcolor:(NSString *)sharp_colorstr alpha:(CGFloat)alpha;
+(UIColor *)HexColor:(int)hexValue Alpha:(float)alpha;
+(NSArray* )rgbFromHexColor:(int)hexValue Alpha:(float)alpha;
+ (NSString*) hexStringFromData : (NSData*) data;
+ (NSNumber*) numericFromHexString : (NSString *) hexstring;
+(void)alertMessage:(NSString *)msg;
+(NSString *)filterHTMLString:(NSString *)htmlstring;

//打开或关闭扬声器
+(void)AudioSpeakerOn:(bool)isOn;

+(NSString *)genGUID;
+(NSString *)getSNSInteger:(NSString *)str;
+(NSString *)getSNSString:(NSString *)str;
+(NSString *)getSNSFloat:(NSString *)str;
+(NSString *)getSNSMoney:(NSString *)str;
+(NSString *)getSNSRMBMoney:(NSString *)str;
+(NSString *)getSNSRMBMoneyWithoutMark:(NSString *)str;//不带¥
+(NSString *)getSNSDouble:(NSString *)str;
+(NSString *)getSNS02Float:(NSString *)str;

+(NSDate *)getDateTimeInterval_MS:(NSString *)str;

//判断是否为整形
+ (BOOL)isPureInt:(NSString*)string;
//判断是否为浮点形：
+ (BOOL)isPureFloat:(NSString*)string;

+ (UIImage*) convertImageToGreyScale:(UIImage*) image;

+ (void)logDictionary:(NSDictionary *)dic;

+(NSString *)getDateTime;

+(void)copyResourceFile:(NSString *)sourceFileName toFile:(NSString *)toFile;

typedef enum{
    IOS_DEVICE_TYPE_IPHONE,
    IOS_DEVICE_TYPE_IPOD,
    IOS_DEVICE_TYPE_IPAD,
    IOS_DEVICE_TYPE_SIMULATOR,
    IOS_DEVICE_TYPE_UNKNOWN
}IOS_DEVICE_TYPE;

+ (IOS_DEVICE_TYPE)getDeviceVersion:(NSMutableString *)versionString;

+ (void)convertVideoToLowQuailtyWithInputURL:(NSURL*)inputURL
                                   outputURL:(NSURL*)outputURL
                                  onComplete:(void (^)(void))onComplete
                                      onExit:(void (^)(void))onExit;

+(UIImage *) getSnsImageAsyn:(NSString *)fileID downloadLock:(NSCondition*)downloadLock ImageCallback:(void (^)(UIImage * image,NSObject *recv_img_id))imageBlock ErrorCallback:(void (^)(void))errorBlock;
+(UIImage *) getImageAsyn:(NSString *)fileID path:(NSString*)path downloadLock:(NSCondition*)downloadLock ImageCallback:(void (^)(UIImage * image,NSObject *recv_img_id))imageBlock ErrorCallback:(void (^)(void))errorBlock;

+(NSString *)convertImageUrl:(NSString *)urlStr WithFixedWidth:(CGFloat)width height:(CGFloat)height;

typedef enum
{
    FORMAT_DATE_TYPE_YMDHN_CHN, //yyyy年m月d日 hh:ss
    FORMAT_DATE_TYPE_MDHN_CHN,  //m月d日 hh:ss
    FORMAT_DATE_TYPE_DURATION,  //时长,超过24小时，显示日期
    FORMAT_DATE_TYPE_DURATION_CHN,  //时长:n分钟，n小时
    FORMAT_DATE_TYPE_DURATION_ALL
}FORMAT_DATE_TYPE;

typedef enum
{
    DATE_DIFF_TYPE_DAY,
    DATE_DIFF_TYPE_HOUR,
    DATE_DIFF_TYPE_MINITE
}DATE_DIFF_TYPE;

+(NSString *)FormatDateTime:(NSDate *)datetime FormatType:(FORMAT_DATE_TYPE)format;
+(NSString *)FormatShortDateTime:(NSDate *)datetime lastDate:(NSDate*)lastDate;
+(NSDate *)dateadd:(NSDate*)date addType:(DATE_DIFF_TYPE)addtype diff:(int)diff;

+(void)resizeLabel:(UILabel *)label defaultHeight:(float)defaultHeight defaultWidth:(float)defaultWidth;
+(CGSize)getFontSize:(UIFont*)font;

+(CGRect)getRect:(NSString *)str;

+(BOOL)isLastVersion:(NSDictionary *)projectPlist versionString:(NSMutableString *)versionString;
+(Boolean) isEmptyOrNull:(NSString *) str;//判断是否全是空格
+(NSString *)filterJSONString:(NSString *)jsonstr;
+(NSString *)dictionaryConvertedToStringWithdic:(NSDictionary *)dic;
+(NSString *)getdate:(NSString *)datestr;
+(NSString *)getYearDaydate:(NSString *)datestr;
//+(BOOL)reachRequestStatus;
+(UIImage *)blurryImage:(UIImage *)image withBlurLevel:(CGFloat)blur;
//图片旋转
+(UIImage *)image:(UIImage *)image rotation:(UIImageOrientation)orientation;

+ (NSString*)dictionaryToJson:(NSDictionary *)dic;

+(UIImage*) OriginImage:(UIImage *)image scaleToSize:(CGSize)size;
+(NSString *)getLastDayTimeWithDateString:(NSString *)dateStr;
+(CGSize) getStrLenByFontStyle:(NSString*) str fontStyle:(UIFont*) fontStyle;
+(CGSize) getStrLenByFontStyle:(NSString*) str fontStyle:(UIFont*) fontStyle textWidth:(float) textWidth;
+(CGSize)getStrLenByFontStyleLine:(NSString*) str fontStyle:(UIFont*)font;

+(NSString *)getAppInfo;
/**
 * @brief 清空缓存
 */
+ (void)clearCacheData;
@end
