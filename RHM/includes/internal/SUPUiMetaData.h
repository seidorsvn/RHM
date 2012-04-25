#import "sybase_sup.h"

@class SUPBooleanUtil;
@class SUPJsonArray;
@class SUPJsonObject;
@class SUPJsonReader;
@class SUPJsonString;
@class SUPJsonValue;
@class SUPNumberUtil;
@class SUPObjectList;

@class SUPUiMetaData;

@interface SUPUiMetaData : NSObject
{
    SUPJsonObject* _json;
}

+ (SUPUiMetaData*)getInstance;
- (SUPUiMetaData*)init;
@property(readwrite, retain, nonatomic) SUPJsonObject* json;
+ (SUPUiMetaData*)parse:(SUPString)text;
- (SUPBoolean)getBoolean:(SUPString)name;
- (SUPBoolean)getBooleanWithDefault:(SUPString)name:(SUPBoolean)defaultValue;
- (SUPDouble)getNumber:(SUPString)name;
- (SUPDouble)getNumberWithDefault:(SUPString)name:(SUPDouble)defaultValue;
- (SUPString)getString:(SUPString)name;
- (SUPString)getStringWithDefault:(SUPString)name:(SUPString)defaultValue;
+ (SUPUiMetaData*)fromJsonObject:(SUPJsonObject*)jo:(SUPInt)flags;
+ (SUPJsonObject*)toJsonObject:(SUPUiMetaData*)uimd:(SUPInt)flags;
- (SUPUiMetaData*)getObject:(SUPString)name;
- (SUPObjectList*)getArray:(SUPString)name;
- (void)dealloc;

@end
