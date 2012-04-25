#import "sybase_sup.h"

@class SUPObjectList;
@class SUPAttributeMetaData;
@class SUPBooleanValue;
@class SUPClassMetaData;
@class SUPConnectionProfile;
@class SUPDatabaseMetaData;
@class SUPEntityClass;
@class SUPEntityMetaData;
@class SUPLocalTransaction;
@class SUPOperationMetaData;
@class SUPQuery;
@class SUPQueryResultSet;


@protocol SUPCallbackHandler;

#import "SUPObjectManager.h"


/*!
 @class		SUPDatabaseClass
 @abstract  A wrapper for the ObjectManager reflection interface that allows convenient access to database-level operations.
*/
@interface SUPDatabaseClass : NSObject<SUPObjectManager>
{
    SUPDatabaseMetaData* _classMetaData;
    id<SUPObjectManager> _objectManager;
}

/*!
 @method     getInstance
 @abstract   Creates a new autoreleased instance of the class.
 */
+ (SUPDatabaseClass*)getInstance;

/*!
 @method     newInstance
 @abstract   Creates a new autoreleased instance of the class.
 @discussion This method is deprecated. use get Instance instead.
 */
+ (SUPDatabaseClass*)newInstance DEPRECATED_ATTRIBUTE;
/*!
 @method     init
 @abstract   The init method for this class
 */
- (SUPDatabaseClass*)init;

/*!
 @property classMetaData
 @abstract The SUPDatabaseMetaData for the entity accessed by this SUPEntityClass.
 */
@property(readwrite, retain, nonatomic) SUPDatabaseMetaData* classMetaData;

/*!
 @property objectManager
 @abstract The object manager used by this SUPDatabaseClass.
 */
@property(readwrite, retain, nonatomic) id<SUPObjectManager> objectManager;

/*!
 @method getInstance
 @abstract Returns a new SUPDatabaseClass instance with metadata and object manager set to the passed in parameters.
 @param md The SUPDatabaseMetaData for the database.
 @param om The object manager.
 */
+ (SUPDatabaseClass*)getInstance:(SUPDatabaseMetaData*)md:(id<SUPObjectManager>)om;
/*!
 @method getClass
 @abstract Returns the metadata for a class, given the class name.
 @param className The class name
 */
- (SUPClassMetaData*)getClass:(SUPString)className;
/*!
 @method getEntity
 @abstract Returns the metadata for an entity, given the entity name.
 @param entityName The entity name
 */
- (SUPEntityClass*)getEntity:(SUPString)entityName;
/*!
 @method newObject
 @abstract Creates a new instance of the class whose metadata is passed in.
 @param theClass The class metadata.
 */
- (id)newObject:(SUPClassMetaData*)theClass;
/*!
 @method getValue
 @abstract Gets an attribute from a class instance.
 @param theObject The class instance
 @param attribute The metadata for the attribute being accessed
 */
- (id)getValue:(id)theObject:(SUPAttributeMetaData*)attribute;
/*!
 @method setValue
 @abstract Sets an attribute from a class instance.
 @param theObject The class instance
 @param attribute The metadata for the attribute being accessed
 */
- (void)setValue:(id)theObject:(SUPAttributeMetaData*)attribute:(id)value;
/*!
 @method invoke
 @abstract Invokes an operation on a class instance.
 @param theObject The class instance
 @param operation The metadata for the operation being invoked
 @param parameters An SUPObjectList of required parameters for the operation
 */
- (id)invoke:(id)theObject:(SUPOperationMetaData*)operation:(SUPObjectList*)parameters;
/*!
 @method getConnectionProfile
 @abstract Gets the connection profile for the database accessed by this SUPDatabaseClass instance.
 */
- (SUPConnectionProfile*)getConnectionProfile;
/*!
 @method getSynchronizationProfile
 @abstract Gets the synchronization profile for the database accessed by this SUPDatabaseClass instance.
 */
- (SUPConnectionProfile*)getSynchronizationProfile;
/*!
 @method beginTransaction
 @abstract Calls beginTransaction to return a transaction object for the database accessed by this SUPDatabaseClass instance.
 */
- (SUPLocalTransaction*)beginTransaction;
/*!
 @method databaseExists
 @abstract For the database accessed by this SUPDatabaseClass instance, returns YES if the database file has been created, NO otherwise.
 */
- (SUPBoolean)databaseExists;
/*!
 @method createDatabase
 @abstract Creates the database file and tables for the database accessed by this SUPDatabaseClass instance.
 */
- (void)createDatabase;
/*!
 @method deleteDatabase
 @abstract Deletes the database file for the database accessed by this SUPDatabaseClass instance.
 */
- (void)deleteDatabase;
/*!
 @method executeQuery
 @abstract Runs a query on the database accessed by this SUPDatabaseClass instance, and returns an SUPQueryResultSet.
 @param query The SUPQuery passed in
 */
- (SUPQueryResultSet*)executeQuery:(SUPQuery*)query;
/*!
 @method loginToSync
 @abstract Executes the login operation on the database accessed by this SUPDatabaseClass instance.
 @param username The username string
 @param password The password string
 */
- (void)loginToSync:(SUPString)username:(SUPString)password;
/*!
 @method synchronize
 @abstract Executes the synchronize operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)synchronize;
/*!
 @method subscribe
 @abstract Executes the subscribe operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)subscribe;
/*!
 @method unsubscribe
 @abstract Executes the unsubscribe operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)unsubscribe;
/*!
 @method suspendSubscription
 @abstract Executes the suspendSubscription operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)suspendSubscription;
/*!
 @method resumeSubscription
 @abstract Executes the resumeSubscription operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)resumeSubscription;
/*!
 @method cancelPendingOperations
 @abstract Executes the cancelPendingOperations operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)cancelPendingOperations;
/*!
 @method submitPendingOperations
 @abstract Executes the submitPendingOperations operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)submitPendingOperations;
/*!
 @method registerCallbackHandler
 @abstract Sets a new callback handler for the database accessed by this SUPDatabaseClass instance.
 @param handler The new callback handler
 */
- (void)registerCallbackHandler:(id<SUPCallbackHandler>)handler;
/*!
 @method startBackgroundSynchronization
 @abstract Executes the startBackgroundSynchronization operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)startBackgroundSynchronization;
/*!
 @method stopBackgroundSynchronization
 @abstract Executes the stopBackgroundSynchronization operation on the database accessed by this SUPDatabaseClass instance.
 */
- (void)stopBackgroundSynchronization;
- (void)dealloc;

@end
