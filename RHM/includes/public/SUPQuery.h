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
#import "SUPEntityFilter.h"

@class SUPObjectList;
@class SUPStringList;
@class SUPStringUtil;
@class SUPAttributeSort;
@class SUPEntityAlias;
@class SUPJoinCondition;
@class SUPJoinCriteria;
@class SUPSelectItem;
@class SUPSortCriteria;
@class SUPTestCriteria;

@class SUPQuery;


/*!
 @class SUPQuery
 @abstract   Programmatic interface to SUPQuery objects.  An SUPQuery is an object representation of a dynamic query.
 @discussion In contrast to named queries with fixed SQL, a dynamic query allows the caller to choose the MBO table to query,
 the columns selected, test criteria, and sort order.  To support this, MBOs must be generated with metadata or with the 
 "Allow dynamic queries" option selected.  MBOs that support dynamic queries will have a method +(SUPObjectList*)findWithQuery:
 that returns a list of MBO objects for the query.  The database class for a package has the method 
 +(SUPQueryResultSet*)executeQuery: , that returns a result set that includes only data for the particular columns selected.
 When the executeQuery method is used, the SUPQuery class supports joins between MBOs.
 
 Example code:
 
 <pre>
 SUPQuery *query = [SUPQuery getInstance];
 [query select:@"c.fname,c.lname,s.order_date,s.region"];        
 [query  from:@"Customer":@"c"];
 [query  join:@"SalesOrder":@"s":@"s.cust_id":@"c.id"];
 query.testCriteria = [SUPAttributeTest match:@"c.lname":@"Devlin"];
 SUPQueryResultSet* resultSet = [SampleApp_SampleAppDB executeQuery:query];
 </pre>
 
 See also: @link //apple_ref/occ/cl/SUPQueryResultSet SUPQueryResultSet @/link
 */
@interface SUPQuery : NSObject
{
    SUPObjectList* _selectItems;
    SUPEntityAlias* _entityAlias;
    SUPJoinCriteria* _joinCriteria;
    SUPTestCriteria* _testCriteria;
    SUPSortCriteria* _sortCriteria;
    SUPObjectList* _groupItems;
    SUPInt _skip;
    SUPInt _take;
    SUPEntityFilterType _entityFilter;
}


/*!
    @method     
    @abstract   Returns a new instance of SUPOuery.
    @result The SUPQuery.
    @discussion 
*/
+ (SUPQuery*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPOuery.
 @result The SUPQuery.
 @discussion This method is deprecated. use getInstance.
 */
+ (SUPQuery*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPQuery*)init;


/*!
 @property     
 @abstract   The selectItems.
 @result The selectItems.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPObjectList* selectItems;

/*!
 @property     
 @abstract   The entityAlias.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPEntityAlias* entityAlias;

/*!
 @property     
 @abstract   The joinCriteria.
 @discussion 
*/
@property(readwrite, retain, nonatomic) SUPJoinCriteria* joinCriteria;

/*!
 @property     
 @abstract   The testCriteria.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPTestCriteria* testCriteria;

/*!
 @property     
 @abstract   The sortCriteria.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPSortCriteria* sortCriteria;

/*!
 @property     
 @abstract   The groupItems.
 @discussion 
 */
@property(assign, nonatomic) SUPObjectList* groupItems;

/*!
 @property     
 @abstract   The skip value.
 @discussion 
*/
@property(readwrite, assign, nonatomic) SUPInt skip;

/*!
 @property     
 @abstract   The take value.
 @discussion 
 */
@property(readwrite, assign, nonatomic) SUPInt take;

/*!
 @property     
 @abstract   The entityFilter value.
 @discussion 
 */
@property(readwrite, assign, nonatomic) SUPEntityFilterType entityFilter;

/*!
 @method     
 @abstract   Returns the SUPQuery with the select condition set to "items".
 @param items An SUPString that defines the "select" requirement for this query.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)select:(SUPString)items;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "from" condition defined by "entity" and "alias".
 @param entity The entity.
 @param alias The alias.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)from:(SUPString)entity:(SUPString)alias;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "join" condition defined by "entity", "entityAlias", "leftItem" and "rightItem".
 @param entity The entity.
 @param entityAlias The alias.
 @param leftItem The leftItem for the join.
 @param rightItem The rightItem for the join.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)join:(SUPString)entity:(SUPString)entityAlias:(SUPString)leftItem:(SUPString)rightItem;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "where" condition defined by "test".
 @param test The SUPTestCriteria.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)where:(SUPTestCriteria*)test;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "groupBy" condition defined by "items".
 @param items The items used to group the results of the query.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)groupBy:(SUPString)items;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "orderBy" condition defined by "attribute" and "sortOrder".
 @param attribute The attribute with which to order.
 @param sortOrder The order with which to sort.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)orderBy:(SUPString)attribute:(SUPInt)sortOrder;

/*!
 @method     
 @abstract  Returns an SUPQuery with the "thenBy" condition defined by "attribute" and "sortOrder".
 @param attribute The attribute with which to order.
 @param sortOrder The order with which to sort.
 @result The SUPQuery.
 @discussion 
 */
- (SUPQuery*)thenBy:(SUPString)attribute:(SUPInt)sortOrder;
- (void)dealloc;

@end
