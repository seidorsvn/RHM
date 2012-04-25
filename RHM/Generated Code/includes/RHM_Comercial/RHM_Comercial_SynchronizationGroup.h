#import "SUPSynchronizationGroup.h"

@interface RHM_Comercial_SynchronizationGroup : NSObject<SUPSynchronizationGroup>
{
@private
	NSString* _name;
	SUPStringList *_entityNames;
}
/*!
 @property     
 @abstract   Returns an SUPStringList with the names of the MBOs in the group.
 @discussion 
 */
@property(readwrite,retain,nonatomic) SUPStringList *entityNames;

- (NSString*)name;
/*!
 @property     
 @abstract   Returns the name of the group.
 @discussion 
 */
@property(readonly,copy,nonatomic) NSString* name;
- (BOOL)adminLock;
/*!
 @property     
 @abstract   Returns true if there is an admin lock on the group.
 @discussion 
 */
@property(readonly,assign,nonatomic) BOOL adminLock;
- (BOOL)enableSIS;
- (void)setEnableSIS:(BOOL)_enableSIS;
/*!
 @property     
 @abstract   Returns true if SIS enabled.
 @discussion 
 */
@property(readwrite,assign,nonatomic) BOOL enableSIS;
- (int32_t)interval;
/*!
 @property     
 @abstract   Returns the synchronization interval.
 @discussion 
 */
@property(readonly,assign,nonatomic) int32_t interval;

/*!
 @method     
 @abstract   Get the names of all MBOs included in the sync group.
 @discussion 
 @returns  An SUPStringList of the entity names.
 */
- (SUPStringList*)getEntityNames;

/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)save;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)synchronize;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)submitPendingOperations;
/*!
 @method     
 @abstract   Not currently implemented, reserved for future use.
 @discussion 
 */
- (void)cancelPendingOperations;


+ (RHM_Comercial_SynchronizationGroup*)getInstance:(NSString*)name;


@end