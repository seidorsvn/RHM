#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPEntityMetaData;

@class SUPEntityMap;

@interface SUPEntityMap : NSObject
{
    SUPObjectList* _classes;
    NSMutableDictionary* _delegate;
}

+ (SUPEntityMap*)getInstance;
- (SUPEntityMap*)init;
@property(readwrite, retain, nonatomic) SUPObjectList* classes;
- (SUPEntityMap*)finishInit;
- (void)add:(SUPString)key:(SUPEntityMetaData*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPEntityMetaData*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
//- (void)initFields;
//+ (void)initialize;
- (void)dealloc;

@end
