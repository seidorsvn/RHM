/*
 
 Copyright (c) Sybase, Inc. 2010   All rights reserved.                                   
 
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



#import "sybase_sup.h"
#import "SUPLogger.h"
#import "SUPLogRecord.h"

/*!
 @class SUPAbstractLogger
 @abstract   This is the superclass for the  &lt;package name&gt;_Logger class generated for an SUP package.  
 @discussion This class should not be called directly.  It is implemented by the &lt;package name&gt;_Logger class generated for an SUP package.
 
 Every SUP package has a &lt;package name&gt;_Logger class that may be accessed by the database class getLogger method.
 
 Example code:
 
 <pre>
 id<SUPLogger> logger = [SampleApp_SampleAppDB getLogger];
 [logger warn:@"create warn message from DB logger"];
 </pre>
 
 */
@interface SUPAbstractLogger : NSObject<SUPLogger>
{
@private
    int32_t _logLevel;
}

/*!
 @method   logLevel
 @abstract   Get the current log level
*/
- (int32_t)logLevel;
/*!
 @method   setLogLevel
 @abstract   Set the current log level
 @param      level The new log level
*/
- (void)setLogLevel:(int32_t)level;
@property(readwrite,assign, nonatomic) int32_t logLevel;

/*!
    @method   createLogRecord
    @abstract   Create a new log record
    @param      level The log level of the new log record
	@param		message The log message of the new log record
    @result     The new log record object
*/
- (id<SUPLogRecord>)createLogRecord:(int32_t)level withMessage:(NSString*)message;
/*!
 @method   fatal
 @abstract   Create a new log record with level "fatal"
 @param		message The log message of the new log record
 */
- (void)fatal:(NSString*)message;
/*!
 @method   error
 @abstract   Create a new log record with level "error"
 @param		message The log message of the new log record
 */
- (void)error:(NSString*)message;
/*!
 @method   warn
 @abstract   Create a new log record with level "warn"
 @param		message The log message of the new log record
 */
- (void)warn:(NSString*)message;
/*!
 @method   info
 @abstract   Create a new log record with level "info"
 @param		message The log message of the new log record
 */
- (void)info:(NSString*)message;
/*!
 @method   debug
 @abstract   Create a new log record with level "debug"
 @param		message The log message of the new log record
 */
- (void)debug:(NSString*)message;
/*!
 @method   trace
 @abstract   Create a new log record with level "trace"
 @param		message The log message of the new log record
 */
- (void)trace:(NSString*)message;

@end

