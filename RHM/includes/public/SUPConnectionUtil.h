/*
 
 Copyright (c) Sybase, Inc. 2010  All rights reserved.                                    
 
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

/*!
 @enum       
 @abstract   The connection status enumeration.  Used by the onConnectionStatusChange callback handler method.
 @discussion 
 */

typedef enum {
    WRONG_STATUS_NUM        = 0,
	CONNECTED_NUM           = 1,   // Device is connected.
	DISCONNECTED_NUM		= 2,   // Device is not connected.
	DEVICEINFLIGHTMODE_NUM	= 3,   // Device is not connected due to flight mode.
	DEVICEOUTOFNETWORKCOVERAGE_NUM	= 4, // Device is not connected due to no network coverage.
	WAITINGTOCONNECT_NUM	= 5,   // Device is not connected and is waiting to retry for a connection.      
	DEVICEROAMING_NUM		= 6,   // Device is not connected since roaming was set to false and device is roaming.
    DEVICELOWSTORAGE_NUM    = 7    // Device is not connected due to low space.
} SUPDeviceConnectionStatus;

/*!
 @enum 
 @abstract   The connection type enumeration.  Used by the onConnectionStatusChange callback handler method.
 @discussion 
 */

typedef enum {
    WRONG_TYPE_NUM     = 0,
	ALWAYS_ON_NUM      = 1 // iPhone has only one connection type
} SUPDeviceConnectionType;


#define getConnectionStatusNum(s) [SUPConnectionUtil getConnectionStatusNum:s]
#define getConnectionTypeNum(t)   [SUPConnectionUtil getConnectionTypeNum:t]


// backwards compatibility
typedef SUPDeviceConnectionStatus ConnectionStatus DEPRECATED_ATTRIBUTE;
typedef SUPDeviceConnectionType ConnectionType DEPRECATED_ATTRIBUTE;

// The following methods are only used by library code.
@interface SUPConnectionUtil : NSObject {

}
+ (SUPDeviceConnectionStatus) getConnectionStatusNum:(NSString *)status_name;
+ (SUPDeviceConnectionType) getConnectionTypeNum:(NSString *)type_name;
@end
