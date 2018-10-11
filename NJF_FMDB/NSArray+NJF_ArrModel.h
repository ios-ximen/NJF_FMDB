//
//  NSArray+NJF_ArrModel.h
//  NJF_FMDB
//
//  Created by niujf on 2018/10/11.
//  Copyright © 2018年 jinfeng niu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (NJF_ArrModel)
/**
 存储数组.
 @name 唯一标识名称.
 **/
- (BOOL)njf_saveArrWithName:(NSString * const _Nonnull)name;

@end

NS_ASSUME_NONNULL_END
