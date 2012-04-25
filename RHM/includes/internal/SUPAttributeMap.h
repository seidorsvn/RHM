#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPAttributeMetaData;

@class SUPAttributeMap;

@interface SUPAttributeMap : NSObject
{
    SUPObjectList* _attributes;
    NSMutableDictionary* _delegate;
}

+ (SUPAttributeMap*)getInstance;
- (SUPAttributeMap*)init;
@property(readwrite, retain, nonatomic) SUPObjectList* attributes;
- (void)add:(SUPString)key:(SUPAttributeMetaData*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPAttributeMetaData*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
- (void)dealloc;
- (SUPAttributeMap*)finishInit;
@end
