#import "sybase_sup.h"

/*!
 @class
 @abstract    Represents the allowed SUP entity filter values.  Used to filter dynamic queries to only return objects in particular states.
 @discussion  An int value of: 0, 1, 2, 4, 8, 16, 32, 64, 128, or 0xFFFF. Corresponds to NONE, PENDING, NOT_PENDING, CREATED, NOT_CREATED, UPDATED, NOT_UPDATED, DELETED, NOT_DELETED, ALL.
 */
@interface SUPEntityFilter : NSObject
{
}

/*!
 @enum
 @abstract Possible SUPEntityFilter values.
 @discussion
 */
typedef enum
{
    SUPEntityFilter_ALL = 217483647,
    SUPEntityFilter_NONE = 0,
    SUPEntityFilter_PENDING = 1,
    SUPEntityFilter_NOT_PENDING = 2,
    SUPEntityFilter_CREATED = 4,
    SUPEntityFilter_NOT_CREATED = 8,
    SUPEntityFilter_UPDATED = 16,
    SUPEntityFilter_NOT_UPDATED = 32,
    SUPEntityFilter_DELETED = 64,
    SUPEntityFilter_NOT_DELETED = 128    
} SUPEntityFilterType;

/*!
 @enum
 @abstract Possible SUPEntityFilter values (deprecated 1.5.3 definitions).
 @discussion
 */
typedef enum
{
    SUPEntityFilterALL = 217483647,
    SUPEntityFilterNONE = 0,
    SUPEntityFilterPENDING = 1,
    SUPEntityFilterNOT_PENDING = 2,
    SUPEntityFilterCREATED = 4,
    SUPEntityFilterNOT_CREATED = 8,
    SUPEntityFilterUPDATED = 16,
    SUPEntityFilterNOT_UPDATED = 32,
    SUPEntityFilterDELETED = 64,
    SUPEntityFilterNOT_DELETED = 128    
} SUPEntityFilterTypeDeprecated;

/*!
 @method     
 @abstract   Returns the entity filter value for ALL.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)ALL;
/*!
 @method     
 @abstract   Returns the entity filter value for NONE.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)NONE;
/*!
 @method     
 @abstract   Returns the entity filter value for PENDING.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)PENDING;
/*!
 @method     
 @abstract   Returns the entity filter value for NOT_PENDING.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)NOT_PENDING;
/*!
 @method     
 @abstract   Returns the entity filter value for CREATED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)CREATED;
/*!
 @method     
 @abstract   Returns the entity filter value for NOT_CREATED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)NOT_CREATED;
/*!
 @method     
 @abstract   Returns the entity filter value for UPDATED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)UPDATED;
/*!
 @method     
 @abstract   Returns the entity filter value for NOT_UPDATED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)NOT_UPDATED;
/*!
 @method     
 @abstract   Returns the entity filter value for DELETED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)DELETED;
/*!
 @method     
 @abstract   Returns the entity filter value for NOT_DELETED.
 @result An int describing the entity filter value.
 @discussion 
 */
+ (SUPInt)NOT_DELETED;

@end
