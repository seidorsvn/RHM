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

//Author: @author janeyang 

#ifndef _MBOLOGINTERFACE_H_
#define _MBOLOGINTERFACE_H_

#import <Foundation/Foundation.h>

// Log levels:
// DEBUG > INFO > WARN > ERROR > FATAL > OFF
/*!
 @defined
 @abstract   No logging.
 @discussion Set for no logging in the system.
*/
#define LOG_OFF		0

/*!
 @defined
 @abstract   Fatal logging.
 @discussion Set for Fatal logging only.
*/
#define LOG_FATAL	1

/*!
 @defined
 @abstract   Error logging.
 @discussion Set for Error or Fatal logging in the system.
*/
#define LOG_ERROR	2

/*!
 @defined
 @abstract   Warning logging.
 @discussion Set for Warning, Error or Fatal logging in the system.
 */
#define LOG_WARN	3

/*!
 @defined
 @abstract   Informational logging.
 @discussion Set for info, warning, error or fatal logging in the system.
 */
#define LOG_INFO	4

/*!
 @defined
 @abstract   Debug logging.
 @discussion Set for All logging in the system.
 */
#define LOG_DEBUG	5



/*!
 @protocol MBOLogInterface
 @abstract Generic logging API interface
 */ 

@protocol MBOLogInterface
/*!
 @method     
 @abstract   log the message.
 @discussion This method is not intended to be called directly but instead use the macros: 
 MBOLogFatal, MBOLogError, MBOLogWarn, MBOLogInfo and MBOLog since these
 will insert the filename and line number automatically.
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


#endif // _MBOLOGINTERFACE_H_
