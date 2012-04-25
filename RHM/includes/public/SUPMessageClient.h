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



//  Created by Jane Yang on 2/16/10.


#import "SUPConnectionUtil.h"

#define kServerNamePref @"servername_preference"
#define kServerPortPref @"serverport_preference"
#define kCompanyIDPref @"companyid_preference"
#define kUserNamePref @"username_preference"
#define kActivationCodePref @"activationcode_preference"

// Return codes by SUPEngine startEngine, stopEngine and restartEngine APIs
// Operation successful 
#define kSUPEngineSuccess           0

// Operation failed. General failure
#define kSUPEngineFailure           -1

// Operation failed
// Unable to access the key from MessagingVault
// MessagingVault must be unlocked before performing this operation
#define kSUPEngineMessagingKeyNotAvailable   -100



// Return code for status API
#define STATUS_NOT_START            0
#define STATUS_START_CONNECTED      1
#define STATUS_START_NOT_CONNECTED  2

// Return codes by SUPMessageClient start/stop/restart APIs
// Operation successful 
#define kSUPMessageClientSuccess           1

// Operation failed. General failure
#define kSUPMessageClientFailure           -1

// Operation failed
// Unable to access the key from KeyVault
// KetVault must be unlocked before performing this operation
#define kSUPMessageClientKeyNotAvailable   -100

// Operation failed
// no required provisioning information in setting
#define kSUPMessageClientNoSettings           -2


/*!
 @class SUPMessageClient
 @abstract   This class declares the programmatic interface to the SUPMessageClient API. 
 The messaging client is responsible for setting up a connection between the user application and the server. It also sends the the client messages up to the server and receives the import messages sent down to the client. 
 @discussion 
 */
@interface SUPMessageClient : NSObject {

}
/*!
 @method   setAssertionState
 @abstract   determines whether assertions should be displayed or not
 @param      hideAssertions - Boolean settings for hideAssertions or not.
 @result
 */

+(void)setAssertionState:(BOOL)hideAssertions;

/*!
 @method start
 @abstract   Start the messaging client.
 @result     Return the return code defined kSUPMessageClientSuccess/kSUPMessageClientFailure/kSUPMessageClientNotAvailable/kSUPMessageClientNoSettings
             
 */
+(NSInteger)start;

/*!
 @method   stop
 @abstract   Stop the messaging client.
 @result     Return the return code defined kSUPMessageClientSuccess/kSUPMessageClientFailure
 */
+(NSInteger)stop;

/*!
 @method   restart
 @abstract   Restart the messaging client.   
 @result     Return the return code defined kSUPMessageClientSuccess/kSUPMessageClientFailure/kSUPMessageClientNotAvailable/kSUPMessageClientNoSettings
 */
+(NSInteger)restart;

/*!
 @method   provisioned
 @abstract   Check if the required provisioning information is set.
 @result     Returns NO when required preferences are not set. Returns YES when all the required information is set.
 */
+(BOOL)provisioned;

/*!
 @method   status
 @abstract   Returns the last status received from messaging client.
 @result    0: Not started.
            1: Started,but not connected.
            2: Started and connected.
 */
+(int)status;
@end

//The following methods are only used by library code.
@interface SUPMessageClient (internal)
+(void)setConnectionStatus:(SUPDeviceConnectionStatus)newStatus;
+(void)checkDefaults;
@end