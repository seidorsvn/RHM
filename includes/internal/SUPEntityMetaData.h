#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPAttributeMetaData;
@class SUPDataType;
@class SUPOperationMetaData;
@class SUPParameterMetaData;

#import "SUPClassMetaData.h"

@class SUPEntityMetaData;

@interface SUPEntityMetaData : SUPClassMetaData
{
    SUPString _table;
    SUPDataType* _keyType;
	BOOL _isClientOnly;
}

+ (SUPEntityMetaData*)getInstance;
- (SUPEntityMetaData*)init;
@property(readwrite, assign, nonatomic) BOOL isClientOnly;
@property(readwrite, copy, nonatomic) SUPString table;
@property(readwrite, retain, nonatomic) SUPDataType* keyType;
- (SUPBoolean)isEntity;
- (SUPEntityMetaData*)finishInit;
- (void)dealloc;

@end
