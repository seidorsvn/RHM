#import "sybase_sup.h"

@class SUPJsonObject;
@class SUPJsonWriter;
@class SUPObjectList;
@class SUPStringList;
@class SUPDataValue;

@class SUPDynamicAttributes;

@interface SUPDynamicAttributes : NSObject
{
    NSMutableDictionary* _delegate;
}

+ (SUPDynamicAttributes*)getInstance;
- (SUPDynamicAttributes*)init;
+ (SUPDynamicAttributes*)fromJsonObject:(SUPJsonObject*)jo:(SUPInt)flags;
+ (SUPJsonObject*)toJsonObject:(SUPDynamicAttributes*)da:(SUPInt)flags;
- (SUPString)toString;
//- (SUPDynamicAttributes*)finishInit;
- (void)add:(SUPString)key:(SUPDataValue*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPDataValue*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
//- (void)initFields;
//+ (void)initialize;
- (void)dealloc;

@end
