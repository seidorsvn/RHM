#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPServiceMetaData;

@class SUPServiceMap;

@interface SUPServiceMap : NSObject
{
    SUPObjectList* _classes;
    NSMutableDictionary* _delegate;
}

+ (SUPServiceMap*)getInstance;
- (SUPServiceMap*)init;
@property(readwrite, retain, nonatomic) SUPObjectList* classes;
- (void)add:(SUPString)key:(SUPServiceMetaData*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPServiceMetaData*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
- (void)dealloc;

@end
