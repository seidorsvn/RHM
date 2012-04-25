#import "sybase_sup.h"

@class SUPJsonObject;
@class SUPObjectList;
@class SUPDataType;

@class SUPParameterMetaData;

@interface SUPParameterMetaData : NSObject
{
    SUPString _name;
    SUPDataType* _dataType;
}

+ (SUPParameterMetaData*)getInstance;
- (SUPParameterMetaData*)init;
+ (SUPObjectList*)EMPTY_LIST;
@property(readwrite, copy, nonatomic) SUPString name;
@property(readwrite, retain, nonatomic) SUPDataType* dataType;
+ (SUPParameterMetaData*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPParameterMetaData*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (void)dealloc;
- (SUPParameterMetaData*)finishInit;
@end
