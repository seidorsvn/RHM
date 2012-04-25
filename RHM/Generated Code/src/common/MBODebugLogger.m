/*
 Generated by Sybase Unwired Platform
 Compiler version - 2.0.1.314
*/ 


#import "MBODebugLogger.h"
#import "MBODebugSettings.h"
#import "SUPPersistenceException.h"

void MBOLogPersistenceException(NSString* format, ...)
{
    va_list ap;
    NSString        *print;
	
    va_start(ap,format);
    print=[[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    //NSLog handles synchronization issues
#ifdef PRINT_PERSISTENCE_MESSAGES
    NSLog(@"MBODebugLogger: SUPPersistenceException %@", print);
#endif
	SUPPersistenceException *e = [SUPPersistenceException withMessage:print];
	[print release];
	@throw e;
}



void MBOLogServerMessageHeader(NSString* descr, SUPJsonObject *o)
{
#ifdef PRINT_SERVER_MESSAGES
	NSLog(@"MBODebugLogger: %@\n%@",descr,[o toString]);
#endif
}


void MBOLogServerMessageContents(NSString* descr, SUPJsonObject *o)
{
#ifdef PRINT_SERVER_MESSAGE_CONTENT
	NSLog(@"MBODebugLogger: %@\n%@",descr,[o toString]);
#endif
}