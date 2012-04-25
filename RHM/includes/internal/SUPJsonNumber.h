#import "sybase_sup.h"

@class SUPJsonNumber;

@interface SUPJsonNumber : NSObject
{
    SUPString _value;
}

+ (SUPJsonNumber*)getInstance;
- (SUPJsonNumber*)init;
@property(readwrite,copy,nonatomic) SUPString value;
- (SUPString)toString;
- (SUPJsonNumber*)finishInit;
- (void)dealloc;

@end
