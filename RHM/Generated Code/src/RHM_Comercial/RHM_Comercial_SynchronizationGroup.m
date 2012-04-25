#import "RHM_Comercial_SynchronizationGroup.h"

@implementation RHM_Comercial_SynchronizationGroup

@synthesize entityNames = _entityNames;

+ (RHM_Comercial_SynchronizationGroup*)getInstance:(NSString*)name
{
	RHM_Comercial_SynchronizationGroup* inst = [[RHM_Comercial_SynchronizationGroup alloc] init];
	inst->_name = name;
	return [inst autorelease];		
}

- (NSString*)name
{
	return _name;
}

- (BOOL)adminLock
{
	return NO;
}

- (BOOL)enableSIS
{
	return NO;
}

- (void)setEnableSIS:(BOOL)_enableSIS
{
	// setter is present for API compatibility, but disabled in this version
}

- (int32_t)interval
{
	return 0;
}

- (SUPStringList*)getEntityNames
{
	return [self entityNames];
}

- (void)save
{
}

- (void)synchronize
{
}

- (void)submitPendingOperations
{
}

- (void)cancelPendingOperations
{
}


@end