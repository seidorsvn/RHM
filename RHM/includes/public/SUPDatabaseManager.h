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

@class SUPStringList;
@class SUPConnectionProfile;

@protocol SUPConnectionWrapper;

/*!
 @protocol
 @abstract   The SUPDatabaseManager protocol provides a common interface for managing a database.  The clientrt library for iPhone provides 
             an internal implementation of this protocol that manages a SQLite3 database.
 @discussion  
 */

@protocol SUPDatabaseManager
/*!
    @method     
    @abstract   Check if the database with the given database attribute in connection profile exists or not.
    @discussion 
    @result YES - The database file exists.
            NO - The database file doesn't exist.
*/

- (SUPBoolean)databaseExists:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Create database schema with given connection profile attribute, and given list of sql statments.
    @discussion 
    @param _profile_1 - Connection profile containing database attribute
    @param  _statements_2 - List of sql statements to be executed
*/

- (void)createDatabase:(SUPConnectionProfile*)_profile_1:(SUPStringList*)_statements_2;
/*!
    @method     
    @abstract   Delete the database with the name contained in connection profile.
    @discussion
    @param _profile_1 - Connection profile containing database attribute.
*/

- (void)deleteDatabase:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Remove current connection wrapper from the connection wrapper pool.
    @discussion 
    @param _profile_1 - Connection profile containing database attribute.
*/

- (void)clearConnection:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Close database connection and release it from connection wrapper pool.
    @discussion 
    @param _profile_1 - Connection profile containing database attribute.
*/

- (void)closeConnection:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Get database connection with given connection profile.
    @discussion 
    @param _profile_1 - Connection profile containing database attribute.
    @result Reference of object instance following SUPConnectionWrapper.
*/

- (id<SUPConnectionWrapper>)getConnection:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Synchronize operation with given connection profile and given publication.
    @discussion 
    @param _profile_1 - Connection profile .
    @param _publications_2 Given publication.
*/

- (void)synchronize:(SUPConnectionProfile*)_profile_1:(SUPString)_publications_2;
/*!
    @method     
    @abstract   Start receiving or sending message from/to transportation layer.
    @discussion 
    @param _profile_1 - Connection profile containing connection attribute.
       
*/
- (void)startBackgroundSynchronization:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Stop receiving or sending message from/to transportation layer
    @discussion 
    @param _profile_1 - Connection profile containing connection attribute.
       
*/
- (void)stopBackgroundSynchronization:(SUPConnectionProfile*)_profile_1;
/*!
    @method     
    @abstract   Change encncryption key for the given database.
    @discussion 
    @param newKey - New database encryptionkey
    @param profile - Connection profile containg current database attributes.
*/

- (void)changeEncryptionKey:(SUPString)newKey withProfile:(SUPConnectionProfile *)profile;
@end
