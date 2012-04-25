
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

#import "SUPEntityAlias.h"

@class SUPJoinCondition;


/*!
 @class SUPJoinCondition
 @abstract   An SUPJoinCondition represents a join in an @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link.  
 @discussion The @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link will always have an @link //apple_ref/occ/cl/SUPEntityAlias SUPEntityAlias @/link,
 representing the first MBO table being queried.  The SUPJoinCondition is a subclass of @link //apple_ref/occ/cl/SUPEntityAlias SUPEntityAlias @/link that represents an additional
 MBO being queried.  The leftItem and rightItem attributes define the columns from the two MBOs whose values must be equal to satisfy
 the join.
 
 Example code showing an SUPQuery with a join:
 
 <pre>
 SUPQuery *query2 = [SUPQuery getInstance];
 [query2 select:@"c.fname,c.lname,s.order_date,s.region"];        
 [query2 from:@"Customer":@"c"];
 // 
 // Convenience method for adding a join to the query
 //
 //[query2 join:@"Sales_order":@"s":@"s.cust_id":@"c.id"];
 //
 // Detailed construction of the join criteria
 SUPJoinCriteria *joinCriteria = [SUPJoinCriteria getInstance];
 SUPJoinCondition* joinCondition = [SUPJoinCondition getInstance];
 joinCondition.alias = @"s";
 joinCondition.entity = @"Sales_order";
 joinCondition.leftItem = @"s.cust_id";
 joinCondition.rightItem = @"c.id";
 joinCondition.joinType = [SUPJoinCondition INNER_JOIN];
 [joinCriteria add:joinCondition];
 query2.joinCriteria = joinCriteria;
</pre>
 
 */
@interface SUPJoinCondition : SUPEntityAlias
{
    SUPInt _joinType;
    SUPString _leftItem;
    SUPString _rightItem;
}

/*!
 @enum     
 @abstract   Possible SUPJoinCondition values.
 @discussion 
 */
typedef enum
{
	SUPJoinCondition_INNER_JOIN = 1,
	SUPJoinCondition_FULL_OUTER_JOIN = 2,
	SUPJoinCondition_LEFT_OUTER_JOIN = 3,
	SUPJoinCondition_RIGHT_OUTER_JOIN = 4
} SUPJoinConditionType;

/*!
 @method     
 @abstract   Returns a new instance of SUPJoinCondition object.
 @result The SUPJoinCondition object.
 @discussion 
 */
+ (SUPJoinCondition*)getInstance;
/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPJoinCondition object.
 @result The SUPJoinCondition object.
 @discussion This method is deprecated. use getInstance.
 */
+ (SUPJoinCondition*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPJoinCondition*)init;
+ (SUPInt)INNER_JOIN;
+ (SUPInt)FULL_OUTER_JOIN;
+ (SUPInt)LEFT_OUTER_JOIN;
+ (SUPInt)RIGHT_OUTER_JOIN;


/*!
 @property     
 @abstract   The join type.
 @discussion 
 */
@property(readwrite,assign, nonatomic) SUPInt joinType;


/*!
 @property     
 @abstract   The left item.
 @discussion 
 */
@property(readwrite,copy, nonatomic) SUPString leftItem;

/*!
 @property     
 @abstract   The right item.
 @discussion 
 */
@property(readwrite,copy, nonatomic) SUPString rightItem;

- (void)dealloc;

@end

