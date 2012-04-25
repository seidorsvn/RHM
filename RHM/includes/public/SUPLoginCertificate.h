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
 @class SUPLoginCertificate
 @abstract   This class represents a certificate that can be used for authentication to an SUP server.
 @discussion 
 */
@interface SUPLoginCertificate : NSObject
{
@protected
    NSString * _subjectCN;
    NSString * _issuerCN;
    NSString * _subjectDN;
    NSString * _issuerDN;
    NSDate   * _notBefore;
    NSDate   * _notAfter;
    
    NSData   * _signedCertificate;
}

/*!
 @method     
 @abstract   Return a new instance of SUPLoginCertificate.
 @discussion 
 @result The SUPLoginCertificate object.
 */
+ (SUPLoginCertificate*)getInstance;
- (SUPLoginCertificate*)init;
/*!
 @property     
 @abstract   In iPhone, this contains the common name (CN) of the certificate.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSString* subjectCN;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSString* subjectDN;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSString* issuerCN;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSString* issuerDN;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSDate* notBefore;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSDate* notAfter;
/*!
 @property     
 @abstract   Not available on iPhone in this release.
 @discussion
 */
@property(readonly,retain,nonatomic) NSData* distinguishedName;
/*!
 @property     
 @abstract   The signed certificate data.
 @discussion 
 */
@property(readwrite,retain,nonatomic) NSData* signedCertificate;
/*!
 @method     
 @abstract   Find and load the certificate from the data vault that matches the given label.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the certificate
 @param vaultPassword The password needed to unlock the data vault
 @result The SUPLoginCertificate object representing the certificate
 @throws SUPDataVaultException
 */
+ (SUPLoginCertificate*)load:(NSString*)label withVault:(SUPDataVault*)vault;
/*!
 @method     
 @abstract   Save this certificate into the data vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the certificate
 @param vaultPassword The password needed to unlock the data vault
 @throws SUPDataVaultException
 */
- (void)save:(NSString*)label withVault:(SUPDataVault*)vault;
/*!
 @method     
 @abstract   Delete the certificate with the given label from the data vault.
 @discussion The vault must be unlocked when this is called, or an exception will be thrown.
 @param label The label used to store the certificate
 @param vaultPassword The password needed to unlock the data vault
 @throws SUPDataVaultException
 */
+ (void)delete:(NSString*)label withVault:(SUPDataVault*)vault;

- (void)dealloc;
- (NSString*)description;

@end

@interface SUPLoginCertificate (internal)

+ (SUPLoginCertificate*)fromJsonObject:(SUPJsonObject*)_object_1:(int32_t)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPLoginCertificate*)_object_1:(int32_t)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(int32_t)_flags;
- (void)writeJson:(SUPJsonObject*)_object_1:(int32_t)_flags;

@end

