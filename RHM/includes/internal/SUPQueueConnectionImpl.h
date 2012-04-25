/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPQueueConnectionImpl.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Implementation of queue connection used by SUP application.
 ******************************************************************************/

#import <SUPQueueConnection.h>
#import <SUPConnectionProfile.h>
#import <SUPMessageListener.h>
#import "SUPObjectList.h"


@interface SUPQueueConnectionImpl : NSObject<SUPQueueConnection>
{
    NSObject<SUPMessageListener>* listener;
@private
    SUPConnectionProfile*       _connectionProfile;
    NSString*                   _package;
    NSString*                   _cidfilename;
    BOOL                        _cidfilelock;
    unsigned int                _cidcachedvalue;
    unsigned int                _previouscidcachedvalue;
}


@property(readonly, retain)  SUPConnectionProfile         *connectionProfile;
@property(readwrite, copy)  NSString* package;
@property(readwrite, copy)  NSString* cidfilename;
@property(readwrite, assign) BOOL cidfilelock;
@property(readwrite, assign) unsigned int cidcachedvalue;
@property(readwrite, assign) unsigned int previouscidcachedvalue;

+ (SUPQueueConnectionImpl*)getInstance;
+ (SUPQueueConnectionImpl*)getInstance:(SUPConnectionProfile*)cp;

// New methods to allow SUPObj to handle one queueConnection per package, instead of a single queueConnection for all
// (Above methods still work, so code expecting the interface above will continue to work)

+ (SUPQueueConnectionImpl*)getInstance:(SUPConnectionProfile*)cp withPackage:(SUPString)package;
+ (SUPQueueConnectionImpl*)findInstanceForPackage:(SUPString)package;

- (void)changeCID;

+ (NSString*)getApplicationName;
+ (SUPObjectList *)findAll;
- (void)setConnectionProfile:(SUPConnectionProfile*)cp;
- (SUPConnectionProfile*)connectionProfile;

- (void)acknowledge:(SUPJsonMessage*)message;
- (SUPJsonMessage*)receive:(SUPInt)timeout;
- (void)send:(SUPJsonMessage*)message;
- (void)setListener:(id<SUPMessageListener>)ml;
#if 0
/*!
    @function   sendPIM
    @abstract   send PIM data from SUP application to IMO's writeToPim
    @discussion 
    @param      message - contains the JSON message of SUP PIM data
                retval - this is an out parameter, caller should provide address of an integer, 
                to get back the return code of IMO writeToPIM().
 
    @result     return valid PIM recordID, if successful;
                return nil if fails
*/

- (NSString *)sendPIM:(SUPJsonMessage*)message:(int *)retval;
#endif

// Used by SUPObj to pass message to SUP code
- (void)dispatchReceivedMessage:(SUPJsonMessage*)message;

// Used to pass client message to SUP code
- (void)dispatchLocalMessage:(SUPJsonMessage*)message;
@end
