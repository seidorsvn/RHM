#import "sybase_sup.h"

@class SUPJsonWriter;

@interface SUPJsonWriter : NSObject
{
}

+ (SUPJsonWriter*)getInstance;
- (SUPJsonWriter*)init;
+ (SUPString)write:(id)x;
- (void)dealloc;

@end
