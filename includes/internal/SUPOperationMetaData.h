#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringUtil;
@class SUPDataType;
@class SUPNoSuchParameterException;
@class SUPParameterMetaData;

@class SUPOperationMetaData;

@interface SUPOperationMetaData : NSObject
{
    SUPInt _id;
    SUPString _name;
    SUPObjectList* _parameters;
    SUPDataType* _returnType;
    SUPBoolean _isCreate;
    SUPBoolean _isUpdate;
    SUPBoolean _isDelete;
    SUPBoolean _isReplay;
    SUPBoolean _isStatic;
}

+ (SUPOperationMetaData*)getInstance;
- (SUPOperationMetaData*)init;
+ (SUPObjectList*)EMPTY_LIST;

@property(readwrite, assign) SUPInt id;
@property(readwrite, copy) SUPString name;
@property(readwrite, retain) SUPObjectList* parameters;
@property(readwrite, retain) SUPDataType* returnType;
@property(readwrite, assign) SUPBoolean isCreate;
@property(readwrite, assign) SUPBoolean isUpdate;
@property(readwrite, assign) SUPBoolean isDelete;
@property(readwrite, assign) SUPBoolean isReplay;
@property(readwrite, assign) SUPBoolean isStatic;

- (SUPParameterMetaData*)getParameter:(SUPString)name;
- (SUPOperationMetaData*)finishInit;
- (void)dealloc;

@end
