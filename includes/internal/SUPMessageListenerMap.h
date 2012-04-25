#import "sybase_sup.h"

@class SUPObjectList;
@class SUPStringList;

@protocol SUPMessageListener;

@class SUPMessageListenerMap;

@interface SUPMessageListenerMap : NSObject
{
    NSMutableDictionary* _delegate;
}

+ (SUPMessageListenerMap*)getInstance;
- (SUPMessageListenerMap*)init;
- (void)add:(SUPString)key:(id<SUPMessageListener>)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (id<SUPMessageListener>)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (NSMutableDictionary*)internalMap;
- (void)dealloc;

@end
