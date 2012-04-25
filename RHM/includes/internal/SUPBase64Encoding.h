#import "sybase_sup.h"

@class SUPAbstractOperationException;
@class SUPBase64EncodingException;
@class SUPByteList;
@class SUPJsonObject;
@class SUPNumberUtil;
@class SUPStringList;
@class SUPStringUtil;

@class SUPBase64Encoding;

@interface SUPBase64Encoding : NSObject
{
}

+ (SUPBinary)decode:(SUPString)text;
+ (SUPString)encode:(SUPBinary)data;
+ (SUPBase64Encoding*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPBase64Encoding*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (void)dealloc;

@end
