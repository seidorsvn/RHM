#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPClassMetaData;

@class SUPClassMap;

@interface SUPClassMap : NSObject
{
    SUPObjectList* _classes;
    NSMutableDictionary* _delegate;
}

+ (SUPClassMap*)getInstance;
- (SUPClassMap*)init;
@property(readwrite, retain, nonatomic) SUPObjectList* classes;
//- (SUPClassMap*)finishInit;
- (void)add:(SUPString)key:(SUPClassMetaData*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPClassMetaData*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
//- (void)initFields;
//+ (void)initialize;
- (void)dealloc;

@end
