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

/*!
 @protocol
 @abstract    SUPReplayLogRecord protocol.
 @discussion  
 */

@protocol SUPReplayLogRecord
/*!
    @method     
    @abstract   Retrieve message id of the replay log record.
    @discussion 
    @result return message id.
*/

- (SUPLong)messageId;
/*!
    @method     
    @abstract   Set new message id with given value.
    @discussion 
    @param _value_1 - new message id.
*/

- (void)setMessageId:(SUPLong)_value_1;
/*!
    @method     
    @abstract   Retrieve timestamp of the replay log record.
    @discussion 
    @result return timestamp.
*/
- (SUPDateTime)timestamp;
/*!
    @method     
    @abstract   Set new timestamp with given value.
    @discussion 
    @param _value_1 - new timestamp.
*/
- (void)setTimestamp:(SUPDateTime)_value_1;
/*!
    @method     
    @abstract   retrieve log level of the replay log record.
    @discussion 
    @result return log level.
*/

- (SUPString)level;
/*!
    @method     
    @abstract   Set new log level with given value.
    @discussion 
    @param _value_1 - new log level.
*/

- (void)setLevel:(SUPString)_value_1;
/*!
    @method     
    @abstract   Retrieve message of the replay log record.
    @discussion 
    @result return message.
*/
- (SUPString)message;
/*!
    @method     
    @abstract   Set new message with given value.
    @discussion 
    @param _value_1 - new message.
*/
- (void)setMessage:(SUPString)_value_1;
/*!
    @method     
    @abstract   Retrieve component attribute of the replay log record.
    @discussion 
    @result return component.
*/

- (SUPString)component;
/*!
    @method     
    @abstract   Set new component with given value.
    @discussion 
    @param _value_1 - new component.
*/
- (void)setComponent:(SUPString)_value_1;
/*!
    @method     
    @abstract   Retrieve entityKey attribute of the replay log record.
    @discussion 
    @result return entityKey.
*/

- (SUPString)entityKey;
/*!
    @method     
    @abstract   Set new entityKey with given value.
    @discussion 
    @param _value_1 - new entityKey.
*/
- (void)setEntityKey:(SUPString)_value_1;
/*!
    @method     
    @abstract   Retrieve operation attribute of the replay log record.
    @discussion 
    @result return operation.
*/
- (SUPString)operation;
/*!
    @method     
    @abstract   Set new operation with given value.
    @discussion 
    @param _value_1 - new operation.
*/
- (void)setOperation:(SUPString)_value_1;
/*!
    @method     
    @abstract   Retrieve requestgId attribute of the replay log record.
    @discussion 
    @result return requestId.
*/
- (SUPLong)requestId;
/*!
    @method     
    @abstract   Set new requestId with given value.
    @discussion 
    @param _value_1 - new requestId.
*/
- (void)setRequestId:(SUPLong)_value_1;
/*!
    @method     
    @abstract   Create operation of replay log record
    @discussion 
*/

- (void)create;
/*!
    @method     
    @abstract   Update operation of replay log record
    @discussion 
*/
- (void)update;
/*!
    @method     
    @abstract   Delete operation of replay log record
    @discussion 
*/
- (void)delete;

@end
