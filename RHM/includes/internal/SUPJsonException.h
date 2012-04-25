#import "sybase_sup.h"

@class SUPJsonException;

@interface SUPJsonException : NSException
{
    SUPString _message;
}

+ (SUPJsonException*)getInstance;
- (SUPJsonException*)init;
@property(readwrite,copy,nonatomic) SUPString message;
- (SUPJsonException*)finishInit;
- (void)dealloc;
- (NSString*)name;
- (NSString*)reason;
- (NSString*)description;

@end
