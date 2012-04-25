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
#import "SUPConnectionProfile.h"
#import "SUPLoginCertificate.h"
#import "SUPStringList.h"

/*!
 @class SUPCertificateStore
 @abstract   This class represents a store containing certificates that can be used for authentication to an SUP server.
 @discussion 
 */
@interface SUPCertificateStore : NSObject
{
}

/*!
 @method     
 @abstract   Return an instance of SUPCertificateStore.
 @discussion For iPhone, the SUPCertificateStore is a singleton, so this will always return the same object.
 @result The SUPCertificateStore object.
 */
+ (SUPCertificateStore*)getInstance;
/*!
 @method     
 @abstract   Return the default certificate store for this device.
 @discussion For iPhone, the SUPCertificateStore is a singleton, so this will always return the same object.
 @result The default SUPCertificateStore object.
 */
+ (SUPCertificateStore*)getDefault;
/*!
 @method     
 @abstract   Return the local store for this device.
 @discussion For iPhone, the SUPCertificateStore is a singleton, so this will always return the same object.
 @param name The name (not used in this version)
 @result The local SUPCertificateStore object.
 */
+ (SUPCertificateStore*)localStore:(NSString*)name;
/*!
 @method     
 @abstract   Return the remote server-based store for the given connection profile.
 @discussion For iPhone, the SUPCertificateStore is a singleton, so this will always return the same object.
 @param profile The connection profile (not used in this version)
 @result The remote SUPCertificateStore object.
 */
+ (SUPCertificateStore*)remoteStore:(SUPConnectionProfile*)profile;
/*!
 @method     
 @abstract   Provided for API compatibility -- returns nil on iPhone.
 @discussion 
 */
- (SUPStringList*)certificateLabels;
/*!
 @method     
 @abstract   Provided for API compatibility -- returns nil on iPhone.
 @discussion 
 */
- (SUPLoginCertificate*)getPublicCertificate:(NSString *)label;
/*!
 @method     
 @abstract   Imports a signed certificate from the store.
 @discussion On iPhone, this API imports the certificate from the iPhone keychain.
 @param label The label.  On iPhone, the keychain ID string for the certificate.
 @param password The password needed to access the certificate's private data.
 @result The SUPLoginCertificate object representing the certificate
 */
- (SUPLoginCertificate*)getSignedCertificate:(NSString *)label withPassword:(NSString *)password;

/*!
 @method     
 @abstract   Gets a certificate from the server.
 @discussion This API requires setup of a Windows share on the server, and access to the share by a user who also has remote batch job permission.
 @param username The username for the Windows user (in the form "DOMAIN\\username")
 @param serverPassword The password for the Windows user
 @param certPassword The password needed to access the certificate (may be the same or different from the Windows password)
 @result The SUPLoginCertificate object representing the certificate
 */
- (SUPLoginCertificate*)getSignedCertificateFromServer:(NSString *)username withServerPassword:(NSString *)serverPassword withCertPassword:(NSString *)certPassword;
/*!
 @method     
 @abstract   Gets a certificate from a file.
 @discussion 
 @param filePath The absolute path to the file.
 @param password The password needed to access the certificate's private data.
 @result The SUPLoginCertificate object representing the certificate
 */
- (SUPLoginCertificate*)getSignedCertificateFromFile:(NSString *)filePath withPassword:(NSString *)password;


- (void)dealloc;

// Internal name and reason string definitions for exceptions
extern NSString * const SSOCertManagerExceptionName;
extern NSString * const kSSOCertManagerExceptionPasswordRequired;
extern NSString * const kSSOCertManagerExceptionInvalidPassword;
extern NSString * const kSSOCertManagerExceptionInvalidArg;
extern NSString * const kSSOCertManagerExceptionParseError;
extern NSString * const kSSOCertManagerExceptionDoesNotExist;
extern NSString * const kSSOCertManagerExceptionNotSupported;
extern NSString * const kSSOCertManagerExceptionServerNotAvailable;

// Public name and reason string definitions
/*!
 @defined
 @abstract Name field for exceptions thrown by SUPDataVault
 @discussion
 */
#define SUPCertificateStoreExceptionName SSOCertManagerExceptionName
/*!
 @defined
 @abstract Reason string for exception thrown if a password is required.
 @discussion
 */
#define kSUPCertificateStoreExceptionPasswordRequired kSSOCertManagerExceptionPasswordRequired
/*!
 @defined
 @abstract Reason string for exception thrown if an invalid password is used.
 @discussion
 */
#define kSUPCertificateStoreExceptionInvalidPassword kSSOCertManagerExceptionInvalidPassword
/*!
 @defined
 @abstract Reason string for exception thrown if an invalid argument is passed in.
 @discussion
 */
#define kSUPCertificateStoreExceptionInvalidArg kSSOCertManagerExceptionInvalidArg
/*!
 @defined
 @abstract Reason string for exception thrown if a parse error occurs.
 @discussion
 */
#define kSUPCertificateStoreExceptionParseError kSSOCertManagerExceptionParseError
/*!
 @defined
 @abstract Reason string for exception thrown if a certificate or data vault does not exist.
 @discussion
 */
#define kSUPCertificateStoreExceptionDoesNotExist kSSOCertManagerExceptionDoesNotExist
/*!
 @defined
 @abstract Reason string for exception thrown if an unsupported API is called.
 @discussion
 */
#define kSUPCertificateStoreExceptionNotSupported kSSOCertManagerExceptionNotSupported
/*!
 @defined
 @abstract Reason string for exception thrown if the server is not available.
 @discussion
 */
#define kSUPCertificateStoreExceptionServerNotAvailable kSSOCertManagerExceptionServerNotAvailable



@end
