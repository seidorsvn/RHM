#import "sybase_sup.h"

@class SUPJsonArray;
@class SUPJsonBoolean;
@class SUPJsonCharToken;
@class SUPJsonException;
@class SUPJsonNumber;
@class SUPJsonObject;
@class SUPJsonString;
@class SUPJsonTokenIndex;
@class SUPObjectList;
@class SUPStringList;
@class SUPStringUtil;

@class SUPJsonReader;

@interface SUPJsonReader : NSObject
{
}

+ (SUPJsonReader*)getInstance;
- (SUPJsonReader*)init;
+ (id)read:(SUPString)text;
- (void)dealloc;

@end
