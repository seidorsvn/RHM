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


#import "sybase_sup.h"

@class SUPLoginCertificate;
@class SUPLoginCredentials;
@class SUPDataVault;
@class DataVaultException;

/*!
 @defined
 @abstract Name field for exceptions thrown by SUPDataVault
 @discussion
 */
extern NSString * const DataVaultExceptionName;

// Reasons for exception thrown
/*!
 @defined
 @abstract Reason string for exception thrown if data vault is locked and method requires it to be unlocked.
 @discussion
 */
extern NSString * const kDataVaultExceptionReasonLocked;
/*!
 @defined
 @abstract Reason string for exception thrown if an invalid password is used.
 @discussion
 */
extern NSString * const kDataVaultExceptionReasonInvalidPassword;
/*!
 @defined
 @abstract Reason string for exception thrown if invalid arguments are passed in.
 @discussion
 */
extern NSString * const kDataVaultExceptionReasonInvalidArg;
/*!
 @defined
 @abstract Reason string for exception thrown if code tries to create a vault that already exists.
 @discussion
 */
extern NSString * const kDataVaultExceptionReasonAlreadyExists;
/*!
 @defined
 @abstract Reason string for exception thrown if code tries to access a vault or object that does not exist.
 @discussion
 */
extern NSString * const kDataVaultExceptionReasonDoesNotExist;

// ID of the standard messaging data vault
// Messaging vault must be unlocked before calling startEngine which will use the key from this vault to decrypt the messaging queue database
/*!
 @defined
 @abstract ID of the standard messaging data vault.
 @discussion Messaging vault must be unlocked before calling startEngine which will use the key from this vault to decrypt the messaging queue database.
 */
extern NSString * const kMessagingDataVaultID;

// Standard password and salt used in "No" security mode
/*!
 @defined
 @abstract Standard password used by messaging in "No" security mode.
 @discussion
 */
extern NSString * const kDVStandardPassword;
/*!
 @defined
 @abstract Standard salt used by messaging in "No" security mode.
 @discussion
 */
extern NSString * const kDVStandardSalt;


#define SUPDataVaultException DataVaultException

/*!
 @class SUPDataVault
 @abstract   This class encapsulates a secure on-device location for storing objects, and methods for unlocking and locking the store, and saving and retrieving objects.
 @discussion 
 */

@interface SUPDataVault : NSObject
{
@private
    NSObject* _vault;
}
/*!
 @method
 @abstract Create a new autoreleased instance of SUPDataVault
 @discussion To actually use a vault, it must be initialized using createVault or getVault methods.
 */
+ (SUPDataVault*)getInstance;
- (SUPDataVault*)init;

/*!
 @method
 @abstract Set the access group (iPhone specific method), if more than one app shares DataVaults.
 @discussion Class method specific for iPhone implementation.
    This method must be called before accessing any DataVault methods.
   Access group must be set only if DataVault must be shared by more than one application.
   If the DataVault is used only by one application access group should not be set.
   This access group in keychain-access-groups property of entitlements plist file is 
   usually in format "<BundleSeedID>.com.yourcompany.DataVault".
 @param accessGroup The access group name
 */
+ (void)setAccessGroup:(NSString *)accessGroup;

/*!
 @method
 @abstract Create a new secure store with the given name, password, and salt
 @discussion If a vault already exists with same name this will throw an exception with reason kDataVaultExceptionReasonAlreadyExists
 @param name The vault name
 @param password The password
 @param salt The salt
 @result The vault
 @throws SUPDataVaultException
 */
+ (SUPDataVault*)createVault:(NSString*)name withPassword:(NSString*)password withSalt:(NSString*)salt;
/*!
 @method
 @abstract Delete the vault with the given name from on-device storage.
 @discussion Throws an exception if the vault does not exist
 @param name The vault name
 @throws SUPDataVaultException
 */
+ (void)deleteVault:(NSString*)name;
/*!
 @method
 @abstract Return the vault object for the given name.
 @discussion Throws an exception if the vault does not exist
 @param name The vault name
 @result The vault
 @throws SUPDataVaultException
 */
+ (SUPDataVault*)getVault:(NSString*)name;
/*!
 @method
 @abstract Tests whether a vault with the given name exists.
 @discussion
 @param name The vault name
 @result YES if the vault exists, NO otherwise
 */
+ (BOOL)vaultExists:(NSString*)name;
/*!
 @method
 @abstract Locks the vault.
 @discussion If vault is already locked, this method has no effect.
 */
- (void)lock;
/*!
 @method
 @abstract Unlocks the vault.
 @discussion Throws exception with kDataVaultExceptionReasonInvalidPassword as reason if password given is incorrect
 @param password The password
 @param salt The salt
 @throws SUPDataVaultException
 */
- (void)unlock:(NSString*)password withSalt:(NSString*)salt;
/*!
 @method
 @abstract Tests whether the vault is locked.
 @discussion
 @result YES if the vault is locked, NO otherwise.
 */
- (BOOL)isLocked;
/*!
 @method
 @abstract Changes the password for the vault.
 @discussion  Throws exception (with reason kDataVaultExceptionReasonInvalidArg) if newPassword is empty or nil.
 Throws exception (with reason kDataVaultExceptionReasonLocked) if vault is locked.
 @param newPassword The new password
 @param salt The salt
 @throws SUPDataVaultException
 */
- (void)changePassword:(NSString*)newPassword withSalt:(NSString*)newSalt;
/*!
 @method
 @abstract Get the named binary value (NSData) object from the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name for the binary value
 @result The binary value
 @throws SUPDataVaultException
 */
- (NSData*)getValue:(NSString*)name;
/*!
 @method
 @abstract Get the named SUPLoginCertificate from the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name for the SUPLoginCertificate
 @result The SUPLoginCertificate
 @throws SUPDataVaultException
 */
- (SUPLoginCertificate*)getCertificate:(NSString*)name;
/*!
 @method
 @abstract Get the named string from the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name for the string
 @result The string
 @throws SUPDataVaultException
 */
- (NSString*)getString:(NSString*)name;
/*!
 @method
 @abstract Get the lock timeout value for the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @result The timeout value
 @throws SUPDataVaultException
 */
- (int32_t)getLockTimeout;
/*!
 @method
 @abstract Get the retry limit value for the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @result The retry limit
 @throws SUPDataVaultException
 */
- (int32_t)getRetryLimit;
/*!
 @method
 @abstract Store a binary (NSData) object in the vault under the given name.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name to store the object with
 @param value The object to store
 @throws SUPDataVaultException
 */
- (void)setValue:(NSString*)name withValue:(NSData*)value;
/*!
 @method
 @abstract Store a string object in the vault under the given name.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name to store the object with
 @param value The object to store
 @throws SUPDataVaultException
 */
- (void)setString:(NSString*)name withValue:(NSString*)value;
/*!
 @method
 @abstract Store an SUPLoginCertificate object in the vault under the given name.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param name The name to store the object with
 @param value The object to store
 @throws SUPDataVaultException
 */
- (void)setCertificate:(NSString*)name withValue:(SUPLoginCertificate*)certificate;
/*!
 @method
 @abstract Set the lock timeout value for the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param timeout The new lock timeout value
 @throws SUPDataVaultException
 */
- (void)setLockTimeout:(int32_t)timeout;
/*!
 @method
 @abstract Set the retry limit value for the vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param limit The new retry limit
 @throws SUPDataVaultException
 */
- (void)setRetryLimit:(int32_t)limit;
/*!
 @method
 @abstract Reset the lock timeout value for the vault to its default value.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @throws SUPDataVaultException
 */
- (void)resetLockTimeout;
- (void)dealloc;


@end
