//
//  SUPJsonLogger.h
//  Logging utilty for JSON
//
//  Created by Jane Yang on 5/29/09.
//  Copyright 2009 Sybase, Inc.. All rights reserved.
//
#ifndef _SUPJsonLogger_H_
#define _SUPJsonLogger_H_
#import "MBOLogInterface.h"
#import "SUPClientRTStringLiterals.h"


/*!
 @defined
 @abstract   log a fatal message.
 @discussion Fatal log message macro shortcuts for placing level, file and line number into log message.
 */
#define JSONLogFatal(s,...) \
[SUPJsonLogger withLevel:LOG_FATAL sourceFile:__FILE__ lineNumber:__LINE__ \
format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a error message.
 @discussion Error log message macro shortcuts for placing level, file and line number into log message.
 */
#define JSONLogError(s,...) \
[SUPJsonLogger \
withLevel:LOG_ERROR sourceFile:__FILE__ lineNumber:__LINE__ \
format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a warning message.
 @discussion Warning log message macro shortcuts for placing level, file and line number into log message.
 */
#define JSONLogWarn(s,...) \
[SUPJsonLogger \
withLevel:LOG_WARN sourceFile:__FILE__ lineNumber:__LINE__ \
format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a informational message.
 @discussion Info log message macro shortcuts for placing level, file and line number into log message.
 */
#define JSONLogInfo(s,...) \
[SUPJsonLogger \
withLevel:LOG_INFO sourceFile:__FILE__ lineNumber:__LINE__ \
format:(s),##__VA_ARGS__]
/*!
 @defined
 @abstract   log a debugging message.
 @discussion Debug log message macro shortcuts for placing level, file and line number into log message.
 Compile with "REMOVE_DEBUG_LOGGING" for release versions if we don't want the logging code for debug.
 */
#if REMOVE_DEBUG_LOGGING

#define JSONLogDebug(s,...) 

#else

#define JSONLogDebug(s,...) \
[SUPJsonLogger \
withLevel:LOG_DEBUG sourceFile:__FILE__ lineNumber:__LINE__ \
format:(s),##__VA_ARGS__]

#endif

#undef assert
/*!
 @defined
 @abstract   Log assert messages to SUPJsonLogger. This overwrites foundation assert.
 @discussion Define assert handling to output assert messages to the JSONLogging API.
 */
#define assert(e)  \
((void) ((e) ? 0 : __JSONAssert (#e)))
/*!
 @defined
 @abstract   Log assert messages to SUPJsonLogger. This is the preferred BobKit assert mechanism.
 @discussion Define assert handling to output assert messages to the JSONLogging API.
 */
#define JSONAssert(e)  \
((void) ((e) ? 0 : __JSONAssert (#e)))

#if NO_ASSERT

    #define	__JSONAssert(e)	((void)0)

#else

#define __JSONAssert(e)  \
(JSONLogError (SUPCLIENTRT_JSONASSERTIONFAIL, e, __func__), abort())

#endif

/*!
 @defined
 @abstract   log a informational message.
 @discussion Map JSONLog macro to the informational logging.
 */
#define JSONLog JSONLogInfo

@interface SUPJsonLogger : NSObject<MBOLogInterface> 
{
}
+(void)withLevel:(NSInteger)level sourceFile:(char*)sourceFile lineNumber:(int)lineNumber 
          format:(NSString*)format, ...;
+(NSInteger)level;
+(void)setLogLevel:(NSInteger)level;
+(void)setLogLeveLFromSettings;
+(const NSString*)levelString:(NSInteger)level;


@end
#endif // _SUPJsonLogger_H_
