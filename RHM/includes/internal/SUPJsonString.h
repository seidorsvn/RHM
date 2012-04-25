#import "sybase_sup.h"

@class SUPStringList;
@class SUPStringUtil;

@class SUPJsonString;

@interface SUPJsonString : NSObject
{
    SUPString field_value;
}

+ (SUPJsonString*)getInstance;
- (SUPJsonString*)init;
- (SUPString)value;
- (void)setValue:(SUPString)_value;
@property(readwrite, copy,nonatomic) SUPString value;
- (SUPString)toString;
- (SUPJsonString*)finishInit;
- (void)dealloc;

@end
