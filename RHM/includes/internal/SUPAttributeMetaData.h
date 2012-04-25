#import "sybase_sup.h"

@class SUPObjectList;
@class SUPDataType;

@class SUPAttributeMetaData;

@interface SUPAttributeMetaData : NSObject
{
    SUPInt _id;
    SUPString _name;
    SUPDataType* _dataType;
    SUPInt _maxLength;
    SUPInt _precision;
    SUPInt _scale;
    SUPNullableString _column;
    SUPBoolean _isKey;
    SUPBoolean _isDynamic;
    SUPBoolean _isReplay;
    SUPBoolean _isStatic;
}

+ (SUPAttributeMetaData*)getInstance;
- (SUPAttributeMetaData*)init;
+ (SUPObjectList*)EMPTY_LIST;
@property(readwrite, assign, nonatomic) SUPInt id;
@property(readwrite, copy, nonatomic, nonatomic) SUPString name;
@property(readwrite, retain, nonatomic) SUPDataType* dataType;
@property(readwrite, assign, nonatomic) SUPInt maxLength;
@property(readwrite, assign, nonatomic) SUPInt precision;
@property(readwrite, assign, nonatomic) SUPInt scale;
@property(readwrite, retain, nonatomic) SUPNullableString column;
@property(readwrite, assign, nonatomic) SUPBoolean isKey;
@property(readwrite, assign, nonatomic) SUPBoolean isDynamic;
@property(readwrite, assign, nonatomic) SUPBoolean isReplay;
@property(readwrite, assign, nonatomic) SUPBoolean isStatic;
- (SUPBoolean)isPersistent;
- (SUPAttributeMetaData*)finishInit;
- (void)initFields;
- (void)dealloc;

@end
