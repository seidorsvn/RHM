#import "sybase_sup.h"

@class SUPStringList;
@class SUPJsonRpcException;

@interface SUPJsonRpcException : NSException
{
    NSException* _cause;
    SUPString _message;
    SUPInt _errorCode;
    SUPString _errorMessage;
    id _errorContent;
}

+ (SUPJsonRpcException*)getInstance;
- (SUPJsonRpcException*)init;
@property(readwrite, retain,nonatomic) NSException* cause;
@property(readwrite, copy,nonatomic) SUPString message;
@property(readwrite,assign,nonatomic) SUPInt errorCode;
@property(readwrite, copy,nonatomic) SUPString errorMessage;
@property(readwrite, retain,nonatomic) id errorContent;
- (SUPBoolean)isError;
- (void)dealloc;
- (NSString*)name;
- (NSString*)reason;
- (NSString*)description;

@end
