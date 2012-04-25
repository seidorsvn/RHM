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



#import "SUPAbstractEntity.h"
#import "SUPParameterMetaData.h"
#import "SUPAttributeMetaData.h"
#import "SUPAttributeMetaData_DC.h"
#import "SUPEntityMetaData.h"
#import "SUPOperationMetaData.h"
#import "SUPDataType.h"
#import "SUPCallbackHandler.h"
#import "SUPDefaultCallbackHandler.h"

@class SUPJsonArray;
@class SUPJsonObject;
@class SUPAbstractDB;

/*!
 @enum 
 @abstract   Enumeration of the possible values for the entity property pendingChange.
 @discussion 
 */
typedef enum
{
	NotPending      = 'N',
	PendingCreate   = 'C',
	PendingUpdate   = 'U',
	PendingDelete   = 'D',
	HasPendingChild = 'P',
	Snapshot        = 'S',
	
} SUPEntityPendingState;

/*!
 @enum 
 @abstract   Table identifiers for each entity -- used internally by SUP generated iPhone code.
 @discussion 
 */
typedef enum
{
	MainEntityTable,
	OriginalStateEntityTable,
	
} SUPEntityTable;


/*!
 @class SUPAbstractEntity
 @abstract   This is the base class for all entity classes.The methods in this class are documented in each entity class.
 @discussion 
 */
// Base class for entity classes
@interface SUPAbstractEntity : NSObject//SUPAbstractEntity
{
@protected
    BOOL                  _isNew;
    BOOL                  _isDirty;
    BOOL                  _isDeleted;
    BOOL                  _pending;
    SUPEntityPendingState _pendingChange;
    int64_t               _replayCounter;
    int64_t               _replayPending;
    int64_t               _replayFailure;
	SUPAbstractEntity*    _originalState;
	BOOL                  _originalStateValid;
	SUPAbstractEntity*	  _downloadState;
	BOOL				  _downloadStateValid;
	BOOL				  _disableSubmit;
}

/** Returns true if this entity is new (i.e. has not yet been created in the database). */
@property(readonly, assign, nonatomic) BOOL isNew;

/** Returns true if this a create operation is pending */
@property(readonly, assign, nonatomic) BOOL isCreated;

/** Returns true if this entity was loaded from the database and was subsequently modified (in memory), but the change has not yet been saved to the database. */
@property(readwrite, assign, nonatomic) BOOL isDirty;

/** Returns true if this entity was loaded from the database and was subsequently deleted. */
@property(readonly, assign, nonatomic) BOOL isDeleted;

/** Returns true if this an update operation is pending */
@property(readonly, assign, nonatomic) BOOL isUpdated;

/** True for any row that represents a pending create, update, or delete operation (optionally also set for snapshot rows, and when pendingChange is 'P'). False otherwise. */
@property(readwrite, assign, nonatomic) BOOL pending;

/** If pending is true, then 'C' (create), 'U' (update), 'D' (delete), 'P' (to indicate that this row is a parent in a cascading relationship for one or more pending child objects,
 but this row itself has no pending create, update or delete operations) or 'S' (to indicate that this row is a snapshot row). If pending is false, then 'N'.*/
@property(readwrite, assign, nonatomic) SUPEntityPendingState pendingChange;

/** Updated each time a row is created or modified by the client.  This value is derived from the time in seconds since an epoch, so it always 
 ** increases each time the row is changed. */
@property(readwrite, assign, nonatomic) int64_t replayCounter;

/** When a pending row is submitted to the server, the value of replayCounter is copied to replayPending.  This allows client code to detect 
 ** if a row has been changed since it was submitted to the server --the test to look for : replayCounter > replayPending. */
@property(readwrite, assign, nonatomic) int64_t replayPending;

/** When the server responds with a replayFailure message for a row that was submitted to the server, the replayCounter value is copied to 
 ** replayFailure, and replayPending is set to 0. */
@property(readwrite, assign, nonatomic) int64_t replayFailure;

/* If set, changes in this entity will not be submitted to the server by a submitPending (or submitPendingOperations) call */
@property(readwrite, assign, nonatomic) BOOL disableSubmit;

/*abstract*/ - (SUPAbstractDB*)database;

- (SUPAbstractEntity*)originalState;
- (void)setOriginalState:(SUPAbstractEntity*)newOriginalState;
/* The state of this entity as saved in the original state table */
@property(readwrite, assign, nonatomic) SUPAbstractEntity* originalState;

- (SUPAbstractEntity*)downloadState;
- (void)setDownloadState:(SUPAbstractEntity*)newDownloadState;
/* The state of this entity at last download from the server, before any pending changes were made */
@property(readwrite, assign, nonatomic) SUPAbstractEntity* downloadState;

- (void)cancelPending;
+ (void)cancelPendingOperations;
/*abstract*/ - (void)copyAll:(SUPAbstractEntity*)other;
- (void)create;
- (void)delete;
- (SUPObjectList*)getLogRecords;
- (id)init;
- (BOOL)isPending;
/*abstract*/ - (NSString*)id_string;
- (SUPJsonObject*)json:(int32_t)flags;
- (void)refresh;
- (void)save;
- (void)submitPending;
+ (void)submitPendingOperations;
- (void)update;
+ (SUPEntityMetaData*)metaData;
/*abstract*/ + (NSObject<SUPCallbackHandler>*)callbackHandler;
/*abstract*/ + (void)registerCallbackHandler:(NSObject<SUPCallbackHandler>*)newCallbackHandler;
@end

@interface SUPAbstractEntity(protected)

/*abstract*/ - (void)copyAll:(SUPAbstractEntity*)other withParent:(SUPAbstractEntity*)parent;
- (void)createPending:(BOOL)isPending;
- (void)deletePending:(BOOL)isPending;
+ (void)importData:(SUPAbstractEntity*)serverEntity:(SUPJsonObject*)jsonObject;
- (void)importData_childcascade;
+ (void)importHandler:(SUPJsonArray*)content;
#if 0
/*abstract*/ + (void)importPimHandler:(SUPJsonObject*)pim;
/*abstract*/ + (void)onPimDataStoreCleared;
#endif
- (void)merge:(SUPAbstractEntity*)entity withJson:(SUPJsonObject*)json;
- (void)refresh_childcascade:(SUPAbstractEntity*)parent;
- (void)replayAccepted_childcascade;
- (void)replayRejected_childcascade;
/*abstract*/ + (void)replayAccepted:(SUPJsonObject*)headers withContent:(SUPJsonArray*)content;
/*abstract*/ + (void)replayRejected:(SUPJsonObject*)headers withContent:(SUPJsonArray*)content;
+ (void)searchAccepted:(SUPJsonObject*)headers withContent:(SUPJsonArray*)content;
+ (void)searchRejected:(SUPJsonObject*)headers withContent:(SUPJsonArray*)content;
+ (SUPObjectList*)searchResults:(SUPAbstractEntity*)entity;
- (void)savePending:(BOOL)isPending;
- (void)submitPending_save_childcascade:(SUPAbstractEntity*)parent;
- (void)submitPending_update_childcascade:(SUPAbstractEntity*)parent;
- (void)updatePending:(BOOL)isPending;
- (void)updateOriginalState;
- (void)evict:(int)days;
- (void)dealloc;
@end
