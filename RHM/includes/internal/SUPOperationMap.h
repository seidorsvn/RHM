#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPOperationMetaData;

@class SUPOperationMap;

@interface SUPOperationMap : NSObject
{
    SUPObjectList* _operations;
    NSMutableDictionary* _delegate;
}

+ (SUPOperationMap*)getInstance;
- (SUPOperationMap*)init;
@property(readwrite, retain, nonatomic) SUPObjectList* operations;
- (void)add:(SUPString)key:(SUPOperationMetaData*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPOperationMetaData*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
- (void)dealloc;
- (SUPOperationMap*)finishInit;
@end
