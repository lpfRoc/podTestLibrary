//
//  Utils.m
//  FaFa
//
//  Created by mac on 12-9-29.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "YFMUtils.h"

@implementation YFMUtils

+(NSString *)getSNS02Float:(NSString *)str
{
    NSString *rst;
    if ((NSNull *)str!=[NSNull null])
    {
        rst=[NSString stringWithFormat:@"%0.2f", [str floatValue]];
    }
    else
    {
        rst=[NSString stringWithFormat:@"0"];
    }
    return rst;
}

@end


