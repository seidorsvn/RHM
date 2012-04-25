#import "sybase_sup.h"

@class SUPJsonObject;
@class SUPJsonReader;
@class SUPJsonValue;

@class SUPJsonMessage;

@interface SUPJsonMessage : NSObject
{
    SUPJsonObject* _headers;
    id _content;
}

+ (SUPJsonMessage*)getInstance;
- (SUPJsonMessage*)init;
@property(readwrite,retain,nonatomic) SUPJsonObject* headers;
@property(readwrite,retain,nonatomic) id content;
- (SUPJsonMessage*)parse:(SUPString)text;
- (SUPString)toString;
- (void)dealloc;

@end
