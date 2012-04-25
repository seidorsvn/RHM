#import "sybase_sup.h"

#import "SUPClassMetaData.h"

@class SUPServiceMetaData;

@interface SUPServiceMetaData : SUPClassMetaData
{
    SUPBoolean _rpc;
    SUPBoolean _sms;
}

+ (SUPServiceMetaData*)getInstance;
- (SUPServiceMetaData*)init;
@property(assign) SUPBoolean rpc;
@property(assign) SUPBoolean sms;
- (SUPBoolean)isService;
/*
- (SUPServiceMetaData*)finishInit;
- (void)initFields;
+ (void)initialize;
 */
- (void)dealloc;

@end
