//
//  NJF_DB.h
//  NJF_FMDB
//
//  Created by jinfeng niu on 2018/10/10.
//  Copyright © 2018年 jinfeng niu. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "NJF_DBConfig.h"

@interface NJF_DB : NSObject

//信号量
@property (nonatomic, strong) dispatch_semaphore_t _Nullable semaphore;
/**
 自定义数据库名称
 */
@property (nonatomic, copy, nonnull) NSString *sqliteName;
/**
 获取单利函数
 */
+ (nonnull instancetype)shareManager;

/**
 关闭数据库
 */
- (void)njf_closeDB;

/**
 删除数据库
 */
- (void)njf_deleteSqlite:(NSString *_Nonnull)sqliteName
            complete:(njf_complete_B)complete;
/**************************数组操作*********************/
/**
  直接存储数组
 */
- (void)njf_saveArray:(NSArray *_Nonnull)array
             name:(NSString *_Nonnull)name
         complete:(njf_complete_B)complete;

/**
 读取数组
 */
- (void)njf_querryArrayWithName:(NSString *_Nonnull)name
                   complete:(njf_complete_A)complete;

/**
 更新数组元素
 */
- (void)njf_updateobjWithName:(NSString *_Nonnull)name
                      obj:(id _Nonnull)obj
                    index:(NSInteger)index
                 complete:(njf_complete_B)complete;

/**
 删除数组某个位置上的元素
 */
- (void)njf_deleteObjWithName:(NSString *_Nonnull)name
                    index:(NSInteger)index
                 complete:(njf_complete_B)complete;

/**
 查询数组某个位置上的元素
 */
- (void)njf_querryWithName:(NSString *_Nonnull)name
                 index:(NSInteger)index
                 value:(void(^)(id value))value;

/**
  删除表中的所有数据
 */
- (void)njf_dropSafeTable:(NSString *_Nonnull)name
             complete:(njf_complete_B)complete;

/**************************字典操作*********************/
/**
 直接存储字典
 */
- (void)njf_saveDict:(NSDictionary *_Nonnull)dict
            name:(NSString *_Nonnull)name
        complete:(njf_complete_B)complete;

/**
遍历字典
 */
- (void)njf_enumerateKeysAndObjectsName:(NSString *_Nonnull)name
                                  block:(void(^ _Nonnull)(NSString *_Nonnull key, NSString *_Nonnull value, BOOL *stop))block
                               complete:(njf_complete_B)complete;

/**
 添加字典元素
 */
- (void)njf_setValueWithName:(NSString *_Nonnull)name value:(id _Nonnull)value
                         key:(NSString *_Nonnull)key
                    complete:(njf_complete_B)complete;

/**
 根据key更新字典元素
 */
- (void)njf_updateValueWithName:(NSString *_Nonnull)name value:(id _Nonnull)value
                            key:(NSString *_Nonnull)key
                       complete:(njf_complete_B)complete;

/**
 根据key获取value
 */
- (void)njf_valueForKeyWithName:(NSString *const _Nonnull)name
                           key:(NSString *_Nonnull)key
                  valueBlock:(void (^ _Nonnull)(id _Nonnull value))block;

/**
 根据key删除字典元素
 */
- (void)njf_deleteValueForKeyWithName:(NSString *const _Nonnull)name
                                  key:(NSString *_Nonnull)key
                             complete:(njf_complete_B)complete;
/**
 清除字典数据
 */
- (void)njf_clearDictWithName:(NSString *const _Nonnull)name
                     complete:(njf_complete_B)complete;

/**************************对象操作*********************/
/**
 保存一个对象
 @param name 表名
 @param obj 要保存的对象
 @param complete 回调
 */
- (void)njf_saveObjWithName:(NSString *const _Nonnull)name
                    obj:(id _Nonnull)obj
                   complete:(njf_complete_B)complete;

/**
 直接传入条件sql语句查询.
 @name 表名称.
 @conditions 条件语句.例如:@"where NJF_name = '标哥' or NJF_name = '小马哥' and NJF_age = 26 order by NJF_age desc limit 6" 即查询BG_name等于标哥或小马哥和NJF_age等于26的数据通过NJF_age降序输出,只查询前面6条.
 更多条件语法,请查询sql的基本使用语句.
 */
- (void)njf_querryWithName:(NSString *const _Nonnull)name
                     conditions:(NSString *_Nullable)conditions
                  complete:(njf_complete_A)complete;

/**
 直接传入条件sql语句删除.
 */
- (void)njf_deleteWithName:(NSString *_Nonnull)name
            conditions:(NSString *_Nullable)conditions
              complete:(njf_complete_B)complete;


/**
 批量插入或更新
 @param name name
 @param arr 批量插入更新的数组
 param obj 保存的类的对象
 @param complete complete
 */
- (void)njf_saveOrUpdateWithName:(NSString *_Nonnull)name
                             arr:(NSArray *_Nonnull)arr
                      ignoreKeys:(NSArray *_Nullable)ignoreKeys
                        complete:(njf_complete_B)complete;

/**
 直接传入条件sql语句更新.
 */
- (void)njf_updateWithName:(NSString *_Nonnull)name
                       obj:(id _Nonnull)obj
                 valueDict:(NSDictionary *_Nullable)valueDict
                conditions:(NSString *_Nonnull)conditions
                  complete:(njf_complete_B)complete;

/**
 直接执行sql语句.
 @tablename 要操作的表名.
 @cla 要操作的类.
 */
- (id _Nullable)njf_executeSql:(NSString* const _Nonnull)sql
                     tablename:(NSString* _Nonnull)tablename
                         class:(__unsafe_unretained _Nonnull Class)cla;

/**
 根据条件查询对象.
 @tablename 要操作的表名称.
 @cla 代表对应的类.
 @where 条件参数.
 @complete 回调的block.
 */
- (void)njf_queryObjectWithTableName:(NSString* _Nonnull)name class:(__unsafe_unretained _Nonnull Class)cla where:(NSString* _Nullable)where complete:(njf_complete_A)complete;

/**
 查询该表中有多少条数据
 @name 表名称.
 @where 条件数组,形式 @[@"key",@"=",@"value",@"key",@">=",@"value"],为nil时返回全部数据的条数.
 */
- (NSInteger)njf_countTableWithName:(NSString *_Nullable)name
                          where:(NSString *_Nullable)conditions;

/**
 刷新数据库，即将旧数据库的数据复制到新建的数据库,这是为了去掉没用的字段.
 @name 表名称.
 @keys 新表的数组字段.
 */
- (void)njf_refreshTableWithName:(NSString *_Nullable)name
                             cla:(__unsafe_unretained _Nonnull Class)cla
                            keys:(NSArray<NSString *> *const _Nonnull)keys
                        complete:(njf_complete_I)complete;
@end
