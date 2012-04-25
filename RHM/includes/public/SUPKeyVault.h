
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// This file is deprecated.
// SUP 2.0.1 and later applications should use SUPDataVault to secure the client messaging database and to store encryption keys, etc.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/*
Copyright (c) Sybase, Inc. 2010 All rights reserved. 

In addition to the license terms set out in the Sybase License Agreement for 
the Sybase Unwired Platform ("Program"), the following additional or different 
rights and accompanying obligations and restrictions shall apply to the source 
code in this file ("Code"). Sybase grants you a limited, non-exclusive, 
non-transferable, revocable license to use, reproduce, and modify the Code 
solely for purposes of (i) maintaining the Code as reference material to better 
understand the operation of the Program, and (ii) development and testing of 
applications created in connection with your licensed use of the Program. 
The Code may not be transferred, sold, assigned, sublicensed or otherwise 
conveyed (whether by operation of law or otherwise) to another party without 
Sybase's prior written consent. The following provisions shall apply to any 
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

//
//  SUPKeyVault.h
//
//  SUP Class to store a key in a secure manner
//  An application can choose to have multiple key vaults
//  Each vault is used to store a key like one for storing DB encryption Key another for a certificate etc.
//  Each vault should be accessed by unique vaultId (unique within the application) like "dbKey", "certKey"
//  KeyVault is unlocked by a PIN

#ifndef __SUPKEYVAULT_H__
#define __SUPKEYVAULT_H__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// ID of the standard messaging vault
// Messaging vault must be unlocked before caling startEngine which will use the key from this vault to decrypt the messaging queue database
extern NSString * const kMessagingVaultID;

// Use this constant for 'maxRetriesAllowed' if unlimited failure attempts can be allowed during unlock
#define kUnlimitedRetriesAllowed   -1

// Use this constant for idleTimeoutSec if application requires user to enter PIN everytime the app is launched
#define kNoIdleTimeout              0

// Return codes used by unlock and changePIN methods
typedef enum {
   kPINStatusSuccess = 0,
   kPINStatusIncorrect,
   kPINStatusTooManyAttempts,
   kPINStatusDoNotMatch,
   kPINStatusInvalid,
   kPINStatusError
} SUPPINStatus;

@interface SUPKeyVault : NSObject {
   NSString * vaultId;
   NSData * pinHash;
   NSData * encryptedKey;

   NSInteger idleTimeoutSec;
   NSInteger maxRetriesAllowed;

   NSDate * lastUsedTimeSec;
   BOOL idleTimeoutFeatureEnabled;
   NSInteger retryCount;
}

//
// Public instance methods supported by this class
//

// Getter method for key
// Fetches the key stored in the vault
- (NSData *) key;

// Setter method for key
// If supplied it will be used the very first time.
// If not supplied the very first time it will be generated and used
- (BOOL)setKey: (NSData *) key;

// Checks if the vault is currently locked
// Returns NO if default PIN is used
// If default PIN is NOT used
//   - If idleTimeoutSec & lastUsedTimeSec are valid
//       - Return NO if current time <= lastUsedTimeSec + idleTimeoutSec
//       - Return YES if current time > lastUsedTimeSec + idleTimeoutSec
//   - If idleTimeoutSec or lastUsedTimeSec are NOT valid
//       - Return YES
- (BOOL) isLocked;

// Checks if custom(user-entered) PIN is in use
// Returns YES if user-entered PIN is in use
// Returns NO if default PIN is in use
- (BOOL) hasCustomPIN;

// Configures the KeyVault with idleTimeoutSec and maxRetriesAllowed settings
// Application should configure the KeyVault if it chooses to implement idleTimeoutSec or maxRetriesAllowed settings
// If only one of setting is required by application it should set the other setting to default value
// idleTimeoutSecValue - Idle time in seconds before asking for PIN from user again. Default value kNoIdleTimeout
// maxRetriesAllowedValue - Maximum number of failed retrys allowed during unlock. Default value kUnlimitedRetriesAllowed
// Returns YES if successfully configured and NO otherwise
- (BOOL)configure:(NSInteger)idleTimeoutSecValue maxRetriesAllowed:(NSInteger)maxRetriesAllowedValue;

// Unlocks the vault with given key
// Should be called during application launch or wakeup when it is locked.
// pin - PIN to unlock the Vault. If nil is supplied default PIN will be used.
// Returns 'kPINStatusSuccess' if sucecssfully unlocked
// Returns 'kPINStatusIncorrect' if unable to unlock the vault with given PIN
// Returns 'kPINStatusTooManyAttempts' if too many failure attempts are made.
// Returns 'kPINStatusError' for generic error
//         KeyVault will remove the key from keychain which means it will not be available to application anymore.
//         Application can choose to wipe the data on receiving error.
// Note: If the idle timeout feature is enabled, the KeyVault is unsecure until the KeyVault is explicitly locked
- (SUPPINStatus)unlock:(NSString *)pin;

// Locks the vault
// Should be called when application wants to explicity lock the KeyVault (like user clicking Exit&Lock button)
// Returns YES if successfully locked and NO otherwise
- (BOOL)lock;

// Resets the idle timer to extend the time to lock the KeyVault
// Application must call this API when it exits or when application sleeps
// Returns YES if idle timer is successfully reset and NO otherwise
- (BOOL)resetIdleTime;

// Changes the PIN to newly supplied PIN
// First verifies if the current PIN is valid before changing it to new PIN
// currentPIN - Current PIN used. If nil default PIN is used
// nPIN - New PIN to use
// cnPIN - Confirmation of new PIN
// Returns 'kPINStatusSuccess' if PIN is successfully changed
// Returns 'kPINStatusInvalid' if newPIN or confirmNewPIN is nil or empty
// Returns 'kPINStatusDoNotMatch' if newPIN does not match confirmNewPIN
// Note: If the idle timeout feature is enabled, the KeyVault is unsecure until the KeyVault is explicitly locked
- (SUPPINStatus)changePIN:(NSString *)currentPIN newPIN:(NSString *)nPIN confirmPIN:(NSString *)cnPIN;

// Resets the PIN to default one
// Application should use this API when it wishes to change the PIN from custom to default
// The KeyVault must be unlocked first before reseting it
// Returns YES if PIN is successfully reset to default PIN and NO otherwise
- (BOOL)resetPIN;

// Removes all SUPKeyVault data from keychain
// Can be used to "reinitialize" keychain to a known state
// Common usage might be at start of app if it is known that key data is invalid  
// since the data the key was to be used to unlock no longer exists
+ (void)resetVault:(NSString*)vaultIdentifier;

// Class method to return the singleton SUPKeyVault object for the given Vault Id
// An application can choose to have multiple key vaults (like one for storing DB encryption Key another for a certificate etc.)
+ (SUPKeyVault*)getSUPKeyVault:(NSString *)vaultId;

@end

#endif // __SUPKEYVAULT_H__