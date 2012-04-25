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

@class SUPObjectList;
@class SUPStringList;
@class SUPStringUtil;
@class SUPAttributeMetaData;
@class SUPDataType;
@class SUPDataValue;
@class SUPDataValueList;
@class SUPDatabaseMetaData;
@class SUPEntityMetaData;
@class SUPPersistenceException;
@class SUPQuery;
@class SUPSelectItem;
@class SUPStatementBuilder;

@protocol SUPResultSetWrapper;
@protocol SUPStatementWrapper;

#import "SUPArrayList.h"

@class SUPQueryResultSet;


/*!
 @class SUPQueryResultSet
 @abstract   An SUPQueryResultSet object represents the result set from a dynamic query.
 @discussion  This type of object is returned by a package's database class method executeQuery:, and by MBO named query methods that return
 result sets instead of MBO lists.  An SUPQueryResultSet contains attributes representing the names and types of the columns selected in the query
 that produced the result set.
 
 Example code showing a query that executes and returns a result set, and then code to go through the result set and print the rows returned.
 
 <pre>
 SUPQuery *query = [SUPQuery getInstance];
 [query select:@"c.fname,c.lname,s.order_date,s.region"];        
 [query  from:@"Customer":@"c"];
 [query  join:@"SalesOrder":@"s":@"s.cust_id":@"c.id"];
 query.testCriteria = [SUPAttributeTest match:@"c.lname":@"Devlin"];
 SUPQueryResultSet* resultSet = [SampleApp_SampleAppDB executeQuery:query];
 if(resultSet == nil)
 {
 MBOLog(@"executeQuery Failed !!");
 return;
 }
 for(SUPDataValueList* result in resultSet)
 {
 MBOLog(@"Firstname,lastname,order date,region = %@ %@ %@ %@",
 [SUPDataValue  getNullableString:[result item:0]],
 [SUPDataValue getNullableString:[result item:1]],
 [[SUPDataValue getNullableDate:[result item:2]] description],
 [SUPDataValue getNullableString:[result item:3]]);
 }
</pre> 
 
 See also:
 @link //apple_ref/occ/cl/SUPQueryResultSet SUPQueryResultSet @/link
 @link //apple_ref/occ/cl/SUPDataValue SUPDataValue @/link 
 @link //apple_ref/occ/cl/SUPDataValueList SUPDataValueList @/link

 */

@interface SUPQueryResultSet : SUPArrayList
{
    SUPStringList* _columnNames;
    SUPObjectList* _columnTypes;
}

/*!
 @property     
 @abstract   Returns the columnnames.
 @discussion 
*/
@property(readwrite, retain, nonatomic) SUPStringList* columnNames;

/*!
 @property 
 @abstract  Returns the columnTypes.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPObjectList* columnTypes;

/*!
 @method     
 @abstract  Executes the query.
 @param statement The statement.
 @param database The SUPDatabaseMetaData.
 @param query The query.
 @discussion 
 */

- (void)execute:(id<SUPStatementWrapper>)statement:(SUPDatabaseMetaData*)database:(SUPQuery*)query;

/*!
 @method     
 @abstract   Returns a new instance of SUPQueryResultSet.
 @result The SUPQueryResultSet.
 @discussion 
 */

+ (SUPQueryResultSet*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPQueryResultSet.
 @result The SUPQueryResultSet.
 @discussion This method is deprecated. use getInstance.
 */

+ (SUPQueryResultSet*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPQueryResultSet*)init;

/*!
 @method     
 @abstract   Returns a new instance of SUPQueryResultSet initialized to "capacity".
 @param cpacity The capacity.
 @result The SUPQueryResultSet.
 @discussion 
 */

- (SUPQueryResultSet*)initWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Returns a new instance of SUPQueryResultSet initialized to "capacity".
 @param cpacity The capacity.
 @result The SUPQueryResultSet.
 @discussion 
 */
+ (SUPQueryResultSet*)listWithCapacity:(SUPInt)capacity;

/*!
 @method     
 @abstract   Add an item to the SUPQueryResultSet.
 @param item The item to add.
 @discussion 
 */
- (void)add:(SUPDataValueList*)item;

/*!
 @method     
 @abstract   Returnns item at "index".
 @param index The index.
 @result The SUPDataValueList.
 @discussion 
 */
- (SUPDataValueList*)item:(SUPInt)index;

/*!
 @method     
 @abstract   Clears the SUPQueryResultSet.
 @discussion 
 */
- (void)clear;
- (void)dealloc;

//This method is provided for internal use by Object API code, not intended for public use.
- (void)populate:(id<SUPResultSetWrapper>)rs;

@end
