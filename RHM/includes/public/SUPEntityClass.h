#import "sybase_sup.h"

@class SUPObjectList;
@class SUPAbstractEntity;
@class SUPAttributeMetaData;
@class SUPBooleanValue;
@class SUPEntityMetaData;
@class SUPClassMetaData;
@class SUPOperationMetaData;
@class SUPQuery;

#import "SUPObjectManager.h"


/*!
 @class				SUPEntityClass
 @abstract			A wrapper for the ObjectManager reflection interface that allows convenient access to static (table-level) and instance (row-level) entity attributes and operations.
*/
@interface SUPEntityClass : NSObject<SUPObjectManager>
{
    SUPEntityMetaData* _classMetaData;
    id<SUPObjectManager> _objectManager;
}

/*!
 @method     getInstance
 @abstract   Creates a new autoreleased instance of the class.
*/
+ (SUPEntityClass*)getInstance;
/*!
 @method     newInstance
 @abstract   Creates a new autoreleased instance of the class.
 @discussion This method is deprecated. use getInstance.
 */
+ (SUPEntityClass*)newInstance DEPRECATED_ATTRIBUTE;

/*!
 @method     init
 @abstract   The init method for this class
 */
- (SUPEntityClass*)init;

/*!
 @property classMetaData
 @abstract The SUPEntityMetaData for the entity accessed by this SUPEntityClass.
 */
@property(readwrite, retain, nonatomic) SUPEntityMetaData* classMetaData;

/*!
 @property objectManager
 @abstract The object manager used by this SUPEntityClass.
 */
@property(readwrite, retain, nonatomic) id<SUPObjectManager> objectManager;

/*!
 @method getInstance
 @abstract Returns a new SUPEntityClass instance with metadata and object manager set to the passed in parameters.
 @param md The SUPEntityMetaData for the entity.
 @param om The object manager.
 */
+ (SUPEntityClass*)getInstance:(SUPEntityMetaData*)md:(id<SUPObjectManager>)om;
/*!
 @method newObject
 @abstract Returns a new entity instance for the entity accessed by this SUPEntityClass.
 */
- (id)newObject;
/*!
 @method newObject
 @abstract Creates a new instance of the class whose metadata is passed in.
 @param theClass The class metadata.
 */
- (id)newObject:(SUPClassMetaData*)theClass;
/*!
 @method getValue
 @abstract Returns an entity attribute, given the entity, and the metadata for the attribute.
 @discussion   Provided for compatibility with the SUPObjectManager protocol -- normally users should use the provided "newObject" method with no parameters.
 @param entity The entity
 @param attribute The metadata for the attribute being accessed
 */
- (id)getValue:(id)entity:(SUPAttributeMetaData*)attribute;
/*!
 @method setValue
 @abstract Sets an entity attribute, given the entity, and the attribute metadata.
 @param entity The entity
 @param attribute The metadata for the attribute being set
 */
- (void)setValue:(id)entity:(SUPAttributeMetaData*)attribute:(id)value;
/*!
 @method invoke
 @abstract Invokes an entity operation, given the entity, the operation metadata, and an SUPObjectList of parameters for the operation.
 @param entity The entity
 @param operation The metadata for the operation being invoked
 @param parameters An SUPObjectList of parameters required by the operation
 */
- (id)invoke:(id)entity:(SUPOperationMetaData*)operation:(SUPObjectList*)parameters;
/*!
 @method isNew
 @abstract Returns the value of the boolean property isNew for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isNew:(id)entity;
/*!
 @method isDirty
 @abstract Returns the value of the boolean property isDirty for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isDirty:(id)entity;
/*!
 @method isPending
 @abstract Returns the value of the boolean property isPending for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isPending:(id)entity;
/*!
 @method isCreated
 @abstract Returns the value of the boolean property isCreated for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isCreated:(id)entity;
/*!
 @method isUpdated
 @abstract Returns the value of the boolean property isUpdated for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isUpdated:(id)entity;
/*!
 @method isDeleted
 @abstract Returns the value of the boolean property isDeleted for the entity passed in.
 @param entity The entity
 */
- (SUPBoolean)isDeleted:(id)entity;
/*!
 @method find
 @abstract Executes the static entity method "find", for the primary key passed in, and returns an entity object if a row with this primary key is found in the entity database table, or null if not found.
 @param key The primary key
 */
- (id)find:(id)key;
/*!
 @method findWithQuery
 @abstract Returns an SUPObjectList of entity rows matching the passed in SUPQuery.
 @param query the SUPQuery
 */
- (SUPObjectList*)findWithQuery:(SUPQuery*)query;
/*!
 @method save
 @abstract Executes the save operation on the passed in entity row to save it in the database.
 @param entity The entity
 */
- (void)save:(id)entity;
/*!
 @method create
 @abstract Executes the create operation on the passed in entity row to create it in the database.
 @param entity The entity
 */
- (void)create:(id)entity;
/*!
 @method update
 @abstract Executes the update operation on the passed in entity row to change it in the database.
 @param entity The entity
 */
- (void)update:(id)entity;
/*!
 @method delete
 @abstract Executes the delete operation on the passed in entity row to delete it from the database.
 @param entity The entity
 */
- (void)delete:(id)entity;
/*!
 @method refresh
 @abstract Executes the refresh operation on the passed in entity row to refresh its contents from the database.
 @param entity The entity
 */
- (void)refresh:(id)entity;
/*!
 @method cancelPending
 @abstract Executes the cancelPending operation on the passed in entity row to remove any client side changes that have not been sent to the server.
 @param entity The entity
 */
- (void)cancelPending:(id)entity;
/*!
 @method submitPending
 @abstract Executes the submitPending operation on the passed in entity to submit any client side changes to the server.
 @param entity The entity
 */
- (void)submitPending:(id)entity;
/*!
 @method cancelPendingOperations
 @abstract Executes the cancelPendingOperations operation on the entity accessed by this SUPEntityClass - cancels any pending client side changes not sent to the server.
 @param entity The entity
 */
- (void)cancelPendingOperations;
/*!
 @method submitPendingOperations
 @abstract Executes the submitPendingOperations operation on the passed in entity - submits to the server any client side changes for any rows in this entity table.
 @param entity The entity
 */
- (void)submitPendingOperations;
/*!
 @method dealloc
 @abstract The dealloc method for the SUPEntityClass class
 */
- (void)dealloc;

@end
