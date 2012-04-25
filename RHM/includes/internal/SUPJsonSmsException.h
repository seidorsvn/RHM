#import "sybase_sup.h"

@class SUPJsonSmsException;

@interface SUPJsonSmsException : NSException
{
    NSException* _cause;
    SUPString _message;
}

+ (SUPJsonSmsException*)getInstance;
- (SUPJsonSmsException*)init;
@property(readwrite, retain,nonatomic) NSException* cause;
@property(readwrite, copy,nonatomic) SUPString message;
- (void)dealloc;
- (NSString*)name;
- (NSString*)reason;
- (NSString*)description;

@end
