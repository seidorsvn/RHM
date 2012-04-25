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

#import "SUPJsonObject.h"

@class SUPDataVault;

/*!
 @class SUPLoginCredentials
 @abstract   This class represents the credentials (username and password) needed to access an SUP server.
 @discussion 
 */

@interface SUPLoginCredentials : NSObject
{
@protected
    NSString * _username;
    NSString * _password;
}

/*!
 @method     
 @abstract   Return a new instance of SUPLoginCredentials.
 @discussion 
 @result The SUPLoginCredentials object.
 */
+ (SUPLoginCredentials*)getInstance;


/*!
 @method     
 @abstract   Initialize this SUPLoginCredentials object.
 @discussion 
 @result The SUPLoginCredentials object.
 */

- (SUPLoginCredentials*)init;


/*!
 @method     
 @abstract   Initialize this SUPLoginCredentials object with the given username and password.
 @discussion 
 @result The SUPLoginCredentials object.
 */
- (SUPLoginCredentials*)initWithUsername:(NSString*)aUsername andPassword:(NSString*)aPassword;


/*!
 @property     
 @abstract   The username.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSString *username;
/*!
 @property     
 @abstract   The password.
 @discussion
 */
@property(readwrite,retain,nonatomic) NSString *password;

/*!
 @method     
 @abstract   Find and load the credentials from the data vault that matches the given label.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the credentials
 @param vaultPassword The password needed to unlock the data vault
 @result The SUPLoginCredentials object with username and password
 @throws SUPDataVaultException
 */
+ (SUPLoginCredentials*)load:(NSString*)label withVault:(SUPDataVault*)vault;
/*!
 @method     
 @abstract   Save the credentials into the data vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the credentials
 @param vaultPassword The password needed to unlock the data vault
 @throws SUPDataVaultException
 */
- (void)save:(NSString*)label withVault:(SUPDataVault*)vault;
/*!
 @method     
 @abstract   Delete the credentials with the given label from the data vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the credentials
 @param vaultPassword The password needed to unlock the data vault
 @throws SUPDataVaultException
 */
+ (void)delete:(NSString*)label withVault:(SUPDataVault*)vault;

- (void)dealloc;

- (NSString*)description;

@end

@interface SUPLoginCredentials(internal)

+ (SUPLoginCredentials*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPLoginCredentials*)_object_1:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (void)writeJson:(SUPJsonObject*)_object_1:(int32_t)_flags;

@end

