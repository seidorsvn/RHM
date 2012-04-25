#import "sybase_sup.h"

@class SUPJsonObject;

@class SUPBase64EncodingException;

@interface SUPBase64EncodingException : NSException
{
}

+ (SUPBase64EncodingException*)getInstance;
- (SUPBase64EncodingException*)init;
- (SUPBase64EncodingException*)finishInit;
+ (SUPBase64EncodingException*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPBase64EncodingException*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (void)dealloc;
- (NSString*)name;
- (NSString*)description;

@end
