/*
 
 Copyright (c) Sybase, Inc. 2010  All rights reserved.                                   
 
 In addition to the license terms set out in the Sybase License Agreement for 
 the Sybase Unwired Platform ("Program"), the following additional or different 
 rights and accompanying obligations and restrictions shall apply to the source 
 code in this file ("Code").  Sybase grants you a limited, non-exclusive, 
 non-transferable, revocable license to use, reproduce, and modify the Code 
 solely for purposes of (i) maintaining the Code as reference material to better
 understand the operation of the Program, and (ii) development and testing of 
 applications created in connection with your licensed use of the Program.  
 The Code may not be transferred, sold, assigned, sublicensed or otherwise 
 conveyed (whether by operation of law or otherwise) to another party without 
 Sybase's prior written consent.  The following provisions shall apply to any 
 modifications you make to the Code: (i) Sybase will not provide any maintenance
 or support for modified Code or problems that result from use of modified Code;
 (ii) Sybase expressly disclaims any warranties and conditions, express or 
 implied, relating to modified Code or any problems that result from use of the 
 modified Code; (iii) SYBASE SHALL NOT BE LIABLE FOR ANY LOSS OR DAMAGE RELATING
 TO MODIFICATIONS MADE TO THE CODE OR FOR ANY DAMAGES RESULTING FROM USE OF THE 
 MODIFIED CODE, INCLUDING, WITHOUT LIMITATION, ANY INACCURACY OF DATA, LOSS OF 
 PROFITS OR DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, EVEN
 IF SYBASE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; (iv) you agree 
 to indemnify, hold harmless, and defend Sybase from and against any claims or 
 lawsuits, including attorney's fees, that arise from or are related to the 
 modified Code or from use of the modified Code. 
 
*/



#ifndef _MBOLOGGER_H_
#define _MBOLOGGER_H_

#import "MBOLogInterface.h"
/*!
    @defined
    @abstract   log a fatal message.
    @discussion Fatal log message macro shortcuts for placing level, file and line number into log message.
*/
#define MBOLogFatal(s,...) \
			[MBOLogger withLevel:LOG_FATAL sourceFile:__FILE__ lineNumber:__LINE__ \
			format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a error message.
 @discussion Error log message macro shortcuts for placing level, file and line number into log message.
 */
#define MBOLogError(s,...) \
			[MBOLogger withLevel:LOG_ERROR sourceFile:__FILE__ lineNumber:__LINE__ \
			format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a warning message.
 @discussion Warning log message macro shortcuts for placing level, file and line number into log message.
 */
#define MBOLogWarn(s,...) \
			[MBOLogger withLevel:LOG_WARN sourceFile:__FILE__ lineNumber:__LINE__ \
			format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a informational message.
 @discussion Info log message macro shortcuts for placing level, file and line number into log message.
 */
#define MBOLogInfo(s,...) \
			[MBOLogger withLevel:LOG_INFO sourceFile:__FILE__ lineNumber:__LINE__ \
			format:(s),##__VA_ARGS__]

/*!
 @defined
 @abstract   log a debugging message.
 @discussion Debug log message macro shortcuts for placing level, file and line number into log message.
				Compile with "REMOVE_DEBUG_LOGGING" for release versions if we don't want the logging code for debug.
 */
#if REMOVE_DEBUG_LOGGING

	#define MBOLogDebug(s,...) 

#else

	#define MBOLogDebug(s,...) \
				[MBOLogger withLevel:LOG_DEBUG sourceFile:__FILE__ lineNumber:__LINE__ \
				format:(s),##__VA_ARGS__]

#endif

#undef assert
/*!
 @defined
 @abstract   Log assert messages to MBOLogger. This overwrites foundation assert.
 @discussion Define assert handling to output assert messages to the MBOLogging API.
 */
#define assert(e)  \
        ((void) ((e) ? 0 : __MBOAssert (#e)))
/*!
 @defined
 @abstract   Log assert messages to MBOLogger. This is the preferred assert mechanism.
 @discussion Define assert handling to output assert messages to the MBOLogging API.
 
 Example output:
 <pre>
 2009-04-09 09:37:56.071 UICatalog[1268:20b] [ERROR] [MBOButton.m:20] 
       Assertion failed: (foo != nil), method: -[MBOButton initWithFrame:]
 </pre>
 */
#define MBOAssert(e)  \
        ((void) ((e) ? 0 : __MBOAssert (#e)))

#if NO_ASSERT

    #define	__MBOAssert(e)	((void)0)

#else



    #define __MBOAssert(e)  \
            (MBOLogError (@"Assertion failed: (%s), method: %s", e, __func__), abort())

#endif

/*!
 @defined
 @abstract   log a informational message.
 @discussion Map MBOLog macro to the informational logging.
 */
#define MBOLog MBOLogInfo


/*!
 @class MBOLogger
 @abstract Generic logging API
 @discussion Logging class to add log levels to message reported to the console. 
 
 Example: <pre>
 NSInteger level = [MBOLogger level];
 MBOLog(\@"general info message");
 MBOLogError(\@"aack, we got an error");
 [MBOLogger setLogLevel:LOG_DEBUG];
 MBOLogDebug(\@"log some debug");
 </pre>
 
 @seealso //apple_ref/c/macro/MBOAssert MBOAssert
 @seealso //apple_ref/c/macro/MBOLogFatal MBOLogFatal
 @seealso //apple_ref/c/macro/MBOLogError MBOLogError
 @seealso //apple_ref/c/macro/MBOLogWarn MBOLogWarn
 @seealso //apple_ref/c/macro/MBOLogInfo MBOLogInfo
 @seealso //apple_ref/c/macro/MBOLogInfo MBOLogDebug
 @seealso //apple_ref/c/macro/MBOLog MBOLog

 
 */ 
// Logging object for MBO framework.
@interface MBOLogger : NSObject 
{
}

/*!
 @method     
 @abstract   log the message to the console.
 @discussion This method is not intended to be called directly but instead use the macros
 @link //apple_ref/c/macro/MBOLogFatal MBOLogFatal @/link,
 @link //apple_ref/c/macro/MBOLogError MBOLogError @/link,
 @link //apple_ref/c/macro/MBOLogWarn MBOLogWarn @/link,
 @link //apple_ref/c/macro/MBOLogInfo MBOLogInfo @/link,
 @link //apple_ref/c/macro/MBOLogInfo MBOLogDebug @/link, and
 @link //apple_ref/c/macro/MBOLog MBOLog @/link.
These will insert the filename and line number automatically.
 @param level log with this provided.
 @param sourceFile the source file of the log message.
 @param lineNumber line number in the file of this log message.
 @param format the formated string with arguments.
*/
+(void)withLevel:(NSInteger)level sourceFile:(char*)sourceFile lineNumber:(int)lineNumber 
		format:(NSString*)format, ...;

/*!
    @function
    @abstract   return current log level.
    @discussion Get the current global log level set for this application.
    @result     integer representing the log level.
*/
+(NSInteger)level;

/*!
 @method     
 @abstract   Set log level.
 @discussion Set log level for the application.
 @param level set the log level for all logging.
*/
+(void)setLogLevel:(NSInteger)level;

/*!
 @method 
 @abstract  Set the log level from the settings properties.
 @discussion Set log level for the application by reading the settings for this
  application. It will look for the keys associated with the plist example.
  i.e. "loggingKey". Here is example Root.plist addition to produce this settings for logging:
 <pre>
    <key>PreferenceSpecifiers</key>
	<array>
		 <dict>
			 <key>Type</key>
			 <string>PSGroupSpecifier</string>
			 <key>Title</key>
			 <string>Logging</string>
		 </dict>
		 <dict>
			 <key>DefaultValue</key>
			 <integer>2</integer>
			 <key>Key</key>
			 <string>loggingKey</string>
			 <key>Title</key>
			 <string>Level</string>
			 <key>Titles</key>
			 <array>
				 <string>None</string>
				 <string>Fatal</string>
				 <string>Error</string>
				 <string>Warning</string>
				 <string>Information</string>
				 <string>Debug</string>
			 </array>
			 <key>Type</key>
			 <string>PSMultiValueSpecifier</string>
			 <key>Values</key>
			 <array>
				 <integer>0</integer>
				 <integer>1</integer>
				 <integer>2</integer>
				 <integer>3</integer>
				 <integer>4</integer>
				 <integer>5</integer>
			 </array>
		 </dict>
	</array>
 </pre>
 */
+(void)setLogLeveLFromSettings;

/*!
 @function 
 @abstract get a string representation for the level.
 @discussion Get a string that represents the log level set in the application.
 @param level pass the log level to get the String name for.
 @result NSString value for the level.
*/
+(const NSString*)levelString:(NSInteger)level;


@end


#endif // _MBOLOGGER_H_
