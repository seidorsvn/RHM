#import "sybase_sup.h"

@class SUPStringUtil;
@class SUPJsonBoolean;

@interface SUPJsonBoolean : NSObject
{
    SUPBoolean _value;
}

+ (SUPJsonBoolean*)getInstance;
- (SUPJsonBoolean*)init;
@property(assign,nonatomic) SUPBoolean value;
- (SUPString)toString;
- (SUPJsonBoolean*)finishInit;
- (void)dealloc;

@end
