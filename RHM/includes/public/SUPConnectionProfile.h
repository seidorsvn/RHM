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
#define FROM_IMPORT_THREAD   TRUE
#define FROM_APP_THREAD      FALSE

@class SUPBooleanUtil;
@class SUPNumberUtil;
@class SUPStringList;
@class SUPStringUtil;
@class SUPPersistenceException;
@class SUPLoginCertificate;
@class SUPLoginCredentials;
@class SUPConnectionProfile;

/*!
 @class SUPConnectionProfile
 @abstract   This class contains fields and methods needed to connect and authenticate to an SUP server.
 @discussion 
 */
@interface SUPConnectionProfile : NSObject
{
    SUPConnectionProfile* _syncProfile;
    SUPBoolean _threadLocal;
    SUPString _wrapperData;    
    NSMutableDictionary* _delegate;
    SUPLoginCertificate* _certificate;
    SUPLoginCredentials* _credentials;
    int32_t _maxDbConnections;
}

/*!
    @method     
    @abstract   Return a new instance of SUPConnectionProfile.
    @discussion 
    @result The SUPconnectionprofile object.
*/

+ (SUPConnectionProfile*)getInstance;

/*!
 @method     
 @abstract   Return a new instance of SUPConnectionProfile.
 @discussion This method is deprecated. use getInstance instead.
 @result The SUPconnectionprofile object.
 */

+ (SUPConnectionProfile*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPConnectionProfile*)init;

/*!
 @property     
 @abstract   The sync profile.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPConnectionProfile* syncProfile;

/*!
 @property
 @abstract The maximum number of active DB connections allowed
 @discussion Default value is 4, but can be changed by application developer.
 */
@property(readwrite, assign, nonatomic) int32_t maxDbConnections;

/*!
    @method     
    @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPString value for a given string.
    @discussion 
    @param name The string.
*/
- (SUPString)getString:(SUPString)name;

/*!
 @method     
 @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPString value for a given string.
 If the value is not found, returns 'defaultValue'.
 @discussion 
 @param name The string.
 @param defaultValue The default Value.
 */
- (SUPString)getStringWithDefault:(SUPString)name:(SUPString)defaultValue;

/*!
 @method     
 @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPBoolean value for a given string.
 @discussion 
 @param name The string.
 */
- (SUPBoolean)getBoolean:(SUPString)name;

/*!
 @method     
 @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPBoolean value for a given string.
 If the value is not found, returns 'defaultValue'.
 @discussion 
 @param name The string.
 @param defaultValue The default Value.
 */
- (SUPBoolean)getBooleanWithDefault:(SUPString)name:(SUPBoolean)defaultValue;

/*!
 @method     
 @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPInt value for a given string.
 @discussion 
 @param name The string.
 */
- (SUPInt)getInt:(SUPString)name;


/*!
 @method     
 @abstract   The SUPConnectionProfile manages an internal dictionary of key value pairs. This method returns the SUPInt value for a given string.
 If the value is not found, returns 'defaultValue'.
 @discussion 
 @param name The string.
 @param defaultValue The default Value.
 */
- (SUPInt)getIntWithDefault:(SUPString)name:(SUPInt)defaultValue;
/*!
    @method   getUPA
    @abstract   retrieve upa from profile
    @discussion if it is in profile's dictionary, it returns value for key "upa";
                if it is not found in profile, it composes the upa value from base64 encoding of username:password;
                and also inserts it into profile's dictionary.
    @param      none
    @result     return string value of upa.
*/

- (SUPString)getUPA;

/*!
    @method     
    @abstract   Sets the SUPString 'value' for the given 'name'.
    @discussion 
    @param name The name.
    @param value The value.
*/
- (void)setString:(SUPString)name:(SUPString)value;

/*!
 @method     
 @abstract   Sets the SUPBoolean 'value' for the given 'name'.
 @discussion 
 @param name The name.
 @param value The value.
 */
- (void)setBoolean:(SUPString)name:(SUPBoolean)value;

/*!
 @method     
 @abstract   Sets the SUPInt 'value' for the given 'name'.
 @discussion 
 @param name The name.
 @param value The value.
 */
- (void)setInt:(SUPString)name:(SUPInt)value;

/*!
    @method     
    @abstract   Sets the username.
    @discussion 
    @param value The value.
*/
- (void)setUser:(SUPString)value;

/*!
 @method     
 @abstract   Sets the password.
 @discussion 
 @param value The value.
 */
- (void)setPassword:(SUPString)value;

/*!
 @method     
 @abstract   Sets the ClientId.
 @discussion 
 @param value The value.
 */
- (void)setClientId:(SUPString)value;

/*!
 @method     
 @abstract   Returns the databasename.
 @discussion 
 @param value The value.
 */
- (SUPString)databaseName;

/*!
 @method     
 @abstract   Sets the databasename.
 @discussion 
 @param value The value.
 */
- (void)setDatabaseName:(SUPString)value;
@property(readwrite,copy, nonatomic) SUPString databaseName;

/*!
 @method     
 @abstract   Sets the encryption key.
 @discussion 
 @param value The value.
 */
- (void)setEncryptionKey:(SUPString)value;
@property(readwrite,copy, nonatomic) SUPString encryptionKey;


/*!
 @property
 @abstract The authentication credentials (username/password or certificate) for this profile.
 @discussion
 */
@property(retain,readwrite,nonatomic) SUPLoginCredentials *credentials;
/*!
 @property     
 @abstract   The authentication certificate.
 @discussion If this is not null, certificate will be used for authentication.  If this is null, credentials property (username/password) will be used.
 */
@property(readwrite,retain,nonatomic) SUPLoginCertificate *certificate;

/*!
    @method     
    @abstract   Returns the user.
    @discussion 
    @result The username.
*/
- (SUPString)getUser;
/*!
 @method     
 @abstract   Returns the password hash value.
 @discussion 
 @result The password hash value.
 */

- (NSUInteger)getPasswordHash;
/*!
 @method     
 @abstract   Returns the password.
 @discussion 
 @result The password hash value.
 */

- (NSString*)getPassword;

/*!
 @method     
 @abstract   Adds a new key value pair.
 @discussion 
 @param key The key.
 @param value The value.
 */
- (void)add:(SUPString)key:(SUPString)value;

/*!
    @method     
    @abstract   Removes the key.
    @discussion 
    @param key The key to remove.
*/

- (void)remove:(SUPString)key;
- (void)clear;

/*!
 @method     
 @abstract   Returns a boolean indicating if the key is present.
 @discussion 
 @param key The key.
 @result The result indicating if the key is present.
 */
- (SUPBoolean)containsKey:(SUPString)key;

/*!
 @method     
 @abstract   Returns the item for the given key.
 @discussion 
 @param key  The key.
 @result The item.
 */
- (SUPString)item:(SUPString)key;

/*!
 @method     
 @abstract   Returns the list of keys.
 @discussion 
 @result The keylist.
 */
- (SUPStringList*)keys;

/*!
 @method     
 @abstract   Returns the list of values.
 @discussion 
 @result The value list.
 */
- (SUPStringList*)values;

/*!
 @method     
 @abstract   Returns the internal map of key value pairs.
 @discussion 
 @result The NSMutableDictionary with key value pairs.
 */
- (NSMutableDictionary*)internalMap;
/*!
    @method     
    @abstract   Returns the domain name.
    @result The domain name.
    @discussion 
*/
- (SUPString)getDomainName;


/*!
 @method     
 @abstract   Sets the domain name.
 @param value The domain name.
 @discussion 
 */
- (void)setDomainName:(SUPString)value;
- (void)dealloc;
@end
