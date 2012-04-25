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
 @protocol
 @abstract    The SUPLogRecord Protocol.  This protocol is implemented by the &lt;package_name&gt;_LogRecordImpl MBO generated for each package.
 @discussion  Each SUP package has its own log record MBO.  Log record attributes can be accessed using the protocol, regardless of which package
 the log records come from.
 
 Example code:
 
 <pre>
 SAPSimpleApps2_SalesOrder* so = // sales order record that was just updated and got a replayResult from the server;
 SUPObjectList* logs = [so getLogRecords];
 for(id<SUPLogRecord> log in logs)
 {
	MBOLogError(@"entity has a log record:\n\
				code = %ld,\n\
				component = %@,\n\
				entityKey = %@,\n\
				level = %ld,\n\
				message = %@,\n\
				operation = %@,\n\
				requestId = %@,\n\
				timestamp = %@",
				[log code],
				[log component],
				[log entityKey],
				[log level],
				[log message],
				[log operation],
				[log requestId],
				[log timestamp]);
 }
 </pre>
 */
@protocol SUPLogRecord

   /*!
    @method     
    @abstract   Returns the messageId.
    @discussion The messageId is unique for each log record.
    @result The messageId.
   */
- (long)messageId;    


/*!
 @method     
 @abstract   The messageId to set.
 @discussion 
 @param messageId The messageId.
 */
- (void)setMessageId:(long)messageId;


/*!
 @method     
 @abstract   Returns the level.
 @discussion   See @link //apple_ref/occ/cl/SUPLogLevel SUPLogLevel @/link for the definitions of the different allowed log levels.
 @result The level.
 */
- (int32_t)level;

/*!
 @method     
 @abstract   The level to set.
 @discussion 
 @param level The level.
 */
 - (void)setLevel:(int32_t)level;

/*!
 @method     
 @abstract   Returns the code.
 @discussion The code numbers for log records sent by the server are based on HTTP return codes.  Examples:
 401 indicates that the client request had invalid credentials, or that authentication failed for some other reason.
 403 indicates that the client request had valid credentials, but that the user does not have permission to access the requested resource (package, MBO or operation).
 404 indicates that the client tried to access a non-existent SUP package or MBO.
 405 indicates that there is no valid license to check out for the client.
 Otherwise 500 to indicate an unexpected (unspecified) server failure.
 @result The code.
 */
 - (int)code;
/*!
 @method     
 @abstract   The code to set.
 @discussion 
 @param code The code.
 */
  - (void)setCode:(int)code;

/*!
 @method     
 @abstract   Returns the eisCode.  This is unused in the current version of SUP.
 @discussion 
 @result The code.
 */
 - (NSString*)eisCode;

/*!
 @method     
 @abstract   The eisCode to set.
 @discussion 
 @param eisCode The code.
 */
- (void)setEisCode:(NSString*)eisCode;


/*!
 @method     
 @abstract   Returns the message containing the reason or error that caused the log record to be written.
 @discussion 
 @result The message.
 */
- (NSString*)message;

/*!
 @method     
 @abstract   The message to set.
 @discussion 
 @param  message  The message.
 */
- (void)setMessage:(NSString*)message;   

/*!
 @method     
 @abstract   Returns the  component.
 @discussion If this log record refers to a particular row in an MBO table, this field contains the name of the MBO.
 @result The component.
 */
 - (NSString*)component;

/*!
 @method     
 @abstract   The component to set.
 @discussion 
 @param component The component.
 */
 - (void)setComponent:(NSString*)component;
/*!
 @method     
 @abstract   Returns the  entityKey.
 @discussion If this log record refers to a particular row in an MBO table, this field contains a string representation of the primary key for the row.
 @result The  entityKey.
 */
- (NSString*)entityKey;

/*!
 @method     
 @abstract    The entityKey to set.
 @discussion 
 @param entityKey The entityKey.
 */
- (void)setEntityKey:(NSString*)entityKey;

/*!
 @method     
 @abstract   Returns the name of the operation (e.g. create, update, or delete) that caused the log record to be written.
 @discussion 
 @result The operation.
 */
- (NSString*)operation;

/*!
 @method     The operation to set.
 @discussion 
 @param operation The operation.
 */
- (void)setOperation:(NSString*)operation;

/*!
 @method     
 @abstract   Returns the  requestId.  For server initiated log records, this is the id of the replay request that caused the log record to be written.
 @discussion 
 @result The requestId.
 */
 - (NSString*)requestId;

/*!
 @method     The requestId to set.
 @discussion 
 @param requestId The requestId.
 */
- (void)setRequestId:(NSString*)requestId;

/*!
 @method     
 @abstract   Returns the  timestamp.
 @discussion 
 @result The timestamp.
 */
- (NSDate*)timestamp;

/*!
 @method     The timestamp to set.
 @discussion 
 @param timestamp The timestamp.
 */
- (void)setTimestamp:(NSDate*)timestamp;

- (void)create;
- (void)update;
- (void)delete;
- (void)save;
- (void)submitPending;
- (void)cancelPending;

@end