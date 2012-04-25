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

@class SUPLocalTransaction;

@protocol SUPStatementWrapper;

/*!
 @protocol
 @abstract    The SUPConnectionWrapper protocol provides a common interface for database connections.  The clientrt library for iPhone provides 
              an internal implementation of this protocol that wraps a SQLite3 database connection.
 @discussion  
 */
@protocol SUPConnectionWrapper
/*!
    @method     
    @abstract   close operation of the connection wrapper.
    @discussion 
*/

- (void)close;
/*!
    @method     
    @abstract   Prepare SQL statement for the next database operation (non-cached).
    @discussion 
    @param _sql_1 - SQL statement
    @result Reference to object instance following SUPStatementWrapper protocol
*/

- (id<SUPStatementWrapper>)dynamicStatement:(SUPString)_sql_1;

/*!
    @method     
    @abstract   Prepare SQL statement for the next database operation (cache for reuse).
    @discussion 
    @param _sql_1 - SQL statement
    @result Reference to object instance following SUPStatementWrapper protocol
*/
- (id<SUPStatementWrapper>)prepareStatement:(SUPString)_sql_1;

/*!
    @method     
    @abstract   Prepare SQL statement for a query.
    @discussion 
    @param _sql_1 - SQL statement
    @result Reference to object instance following SUPStatementWrapper protocol
*/
- (id<SUPStatementWrapper>)prepareQuery:(SUPString)_sql_1 withSkip:(int32_t)skip withTake:(int32_t)take isDynamic:(BOOL)dynamic;

/*!
    @method     
    @abstract   Start database transaction
    @discussion 
    @result Reference to object instance of SUPLocalTransaction
*/

- (SUPLocalTransaction*)beginTransaction;
/*!
    @method     
    @abstract   Get database connection
    @discussion 
    @result Handler of database connection
*/

- (id)getConnection;
/*!
    @method     
    @abstract   Returns a boolean  indicating whether the database operation is in transaction
    @discussion
    @result YES - the transaction is not completed
            NO - no active transaction is progress
*/

- (SUPBoolean)inTransaction;
/*!
    @method     
    @abstract   Releases connection wrapper to the connection wrapper pool.
    @discussion 
*/

- (void)releaseToPool;
/*!
    @method     
    @abstract   Sets the active connection wrapper to be the first in array of connection wrapper pool
    @discussion 
*/

- (void)setCurrent;
- (void)stopSynchronizationDelete;
- (void)startSynchronizationDelete;

@end
