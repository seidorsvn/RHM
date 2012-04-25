#import "RHM_Comercial_LoggerImpl.h"
#import "RHM_Comercial_LogRecordImpl.h"
#import "RHM_Comercial_KeyGenerator.h"
#import "MBODebugSettings.h"

@implementation RHM_Comercial_LoggerImpl

- (id<SUPLogRecord>)createRealLogRecord
{
	RHM_Comercial_LogRecordImpl *log = [RHM_Comercial_LogRecordImpl getInstance];
	log.messageId = [RHM_Comercial_KeyGenerator generateId];
	log.requestId = [NSString stringWithFormat:@"%ld",log.messageId];
	log.timestamp = [NSDate dateWithTimeIntervalSinceNow:0];
	log.code = CLIENT_DATABASE_CREATED_LOGRECORD_CODE;
	log.component = @"RHM_ComercialDB";
	return log;
}


@end