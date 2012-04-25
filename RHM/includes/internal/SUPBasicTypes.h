#import "sybase_sup.h"

#import "SUPStringUtil.h"
#import "SUPDataType.h"
#import "SUPObjectList.h"
#import "SUPStringList.h"

#import "SUPBasicTypes.h"

@interface SUPBasicTypes : NSObject
{
    @protected
    NSMutableDictionary* _delegate;
}

+ (SUPBasicTypes*)instance;
+ (id)allocWithZone:(NSZone *)zone;
- (id)copyWithZone:(NSZone *)zone;
- (id)retain;
- (unsigned)retainCount;
- (void)release;
- (id)autorelease;
- (SUPBasicTypes*)init;
+ (SUPDataType*)t_void;
+ (void)setT_void:(SUPDataType*)value;
+ (SUPDataType*)n_void;
+ (void)setN_void:(SUPDataType*)value;
+ (SUPDataType*)t_object;
+ (void)setT_object:(SUPDataType*)value;
+ (SUPDataType*)n_object;
+ (void)setN_object:(SUPDataType*)value;
+ (SUPDataType*)t_boolean;
+ (void)setT_boolean:(SUPDataType*)value;
+ (SUPDataType*)n_boolean;
+ (void)setN_boolean:(SUPDataType*)value;
+ (SUPDataType*)t_string;
+ (void)setT_string:(SUPDataType*)value;
+ (SUPDataType*)n_string;
+ (void)setN_string:(SUPDataType*)value;
+ (SUPDataType*)t_binary;
+ (void)setT_binary:(SUPDataType*)value;
+ (SUPDataType*)n_binary;
+ (void)setN_binary:(SUPDataType*)value;
+ (SUPDataType*)t_char;
+ (void)setT_char:(SUPDataType*)value;
+ (SUPDataType*)n_char;
+ (void)setN_char:(SUPDataType*)value;
+ (SUPDataType*)t_byte;
+ (void)setT_byte:(SUPDataType*)value;
+ (SUPDataType*)n_byte;
+ (void)setN_byte:(SUPDataType*)value;
+ (SUPDataType*)t_short;
+ (void)setT_short:(SUPDataType*)value;
+ (SUPDataType*)n_short;
+ (void)setN_short:(SUPDataType*)value;
+ (SUPDataType*)t_int;
+ (void)setT_int:(SUPDataType*)value;
+ (SUPDataType*)n_int;
+ (void)setN_int:(SUPDataType*)value;
+ (SUPDataType*)t_long;
+ (void)setT_long:(SUPDataType*)value;
+ (SUPDataType*)n_long;
+ (void)setN_long:(SUPDataType*)value;
+ (SUPDataType*)t_integer;
+ (void)setT_integer:(SUPDataType*)value;
+ (SUPDataType*)n_integer;
+ (void)setN_integer:(SUPDataType*)value;
+ (SUPDataType*)t_decimal;
+ (void)setT_decimal:(SUPDataType*)value;
+ (SUPDataType*)n_decimal;
+ (void)setN_decimal:(SUPDataType*)value;
+ (SUPDataType*)t_float;
+ (void)setT_float:(SUPDataType*)value;
+ (SUPDataType*)n_float;
+ (void)setN_float:(SUPDataType*)value;
+ (SUPDataType*)t_double;
+ (void)setT_double:(SUPDataType*)value;
+ (SUPDataType*)n_double;
+ (void)setN_double:(SUPDataType*)value;
+ (SUPDataType*)t_date;
+ (void)setT_date:(SUPDataType*)value;
+ (SUPDataType*)n_date;
+ (void)setN_date:(SUPDataType*)value;
+ (SUPDataType*)t_time;
+ (void)setT_time:(SUPDataType*)value;
+ (SUPDataType*)n_time;
+ (void)setN_time:(SUPDataType*)value;
+ (SUPDataType*)t_dateTime;
+ (void)setT_dateTime:(SUPDataType*)value;
+ (SUPDataType*)n_dateTime;
+ (void)setN_dateTime:(SUPDataType*)value;
- (SUPBasicTypes*)finishInit;
- (void)add:(SUPString)key:(SUPDataType*)value;
- (void)remove:(SUPString)key;
- (void)clear;
- (SUPBoolean)containsKey:(SUPString)key;
- (SUPDataType*)item:(SUPString)key;
- (SUPStringList*)keys;
- (SUPObjectList*)values;
- (SUPInt)size;
- (NSMutableDictionary*)internalMap;
- (void)initFields;
- (void)dealloc;


@end
