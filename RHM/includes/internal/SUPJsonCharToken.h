#import "sybase_sup.h"

@class SUPStringUtil;
@class SUPJsonCharToken;

@interface SUPJsonCharToken : NSObject
{
    SUPChar _value;
}

+ (SUPJsonCharToken*)getInstance;
- (SUPJsonCharToken*)init;
@property(assign,nonatomic) SUPChar value;
- (SUPString)toString;
- (SUPJsonCharToken*)finishInit;
- (void)dealloc;

@end
