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

#import <Foundation/Foundation.h>

/*!
    @class
    @abstract    Represents the allowed SUP log levels.
    @discussion  An int value of: 1, 2, 3, 4, 5, or 6. Corresponds to trace, debug, info, warn, error, and fatal, respectively.
*/

@interface SUPLogLevel : NSObject
{
}

/*!
 @enum 
 @abstract Possible SUPLogLevel values
 @discussion 
 */
typedef enum
{
	SUPLogLevel_TRACE = 1,
	SUPLogLevel_DEBUG = 2,
	SUPLogLevel_INFO = 3,
	SUPLogLevel_WARN = 4,
	SUPLogLevel_ERROR = 5,
	SUPLogLevel_FATAL = 6
} SUPLogLevelIntType;

#define SUPLogLevel_TRACE_STRING @"trace"
#define SUPLogLevel_DEBUG_STRING @"debug"
#define SUPLogLevel_INFO_STRING @"info"
#define SUPLogLevel_WARN_STRING @"warn"
#define SUPLogLevel_ERROR_STRING @"error"
#define SUPLogLevel_FATAL_STRING @"fatal"

/*!
    @method     
    @abstract   Returns the log level for TRACE.
    @result An int describing the log level.
    @discussion 
*/
+ (int)TRACE;

/*!
 @method     
 @abstract   Returns the log level for DEBUG.
 @result An int describing the log level.
 @discussion 
 */
+ (int)Debug;

/*!
 @method     
 @abstract   Returns the log level for INFO.
 @result An int describing the log level.
 @discussion 
 */
+ (int)INFO;

/*!
 @method     
 @abstract   Returns the log level for WARN.
 @result An int describing the log level.
 @discussion 
 */
+ (int)WARN;

/*!
 @method     
 @abstract   Returns the log level for ERROR.
 @result An int describing the log level.
 @discussion 
 */
+ (int)ERROR;

/*!
 @method     
 @abstract   Returns the log level for FATAL.
 @result An int describing the log level.
 @discussion 
 */
+ (int)FATAL;

/*!
 @method     
 @abstract   Returns the log level from the given string.
 @param level The string describing the log level.
 @result An int describing the log level.
 @discussion 
 */
+ (int)fromString:(NSString*)level;
+ (NSString*)toString:(int)level;

/*!
 @method     
 @abstract   Compares the log levels and returns 0 if equal, 1 if level1 > level2 and -1 if level2 >level1.
 @param level1 A log level.
 @param level2 A log level.
 @result An int describing the log level.
 @discussion 
 */
+ (int)compareLevels:(int)level1 withLevel:(int)level2;

@end
