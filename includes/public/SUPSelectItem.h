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

@class SUPJsonObject;
@class SUPStringUtil;

@class SUPSelectItem;

/*!
 @class SUPSelectItem
 @abstract   An SUPSelectItem represents one of the items selected in an @link //apple_ref/occ/cl/SUPQuery SUPQuery @/link.
 @discussion For example, in an SUPQuery described by "select count(x.a),x.b from Customer x", there would be two SUPSelectItems objects for 
            the query.The first SUPSelectItem would have aggregate = "count", alias = "x", attribute = "a".The second SUPSelectItem would have a null
           aggregate, alias = "x", and attribute = "b".
 */

@interface SUPSelectItem : NSObject
{
    SUPNullableString _aggregate;
    SUPNullableString _alias;
    SUPNullableString _attribute;
}

/*!
    @method     
    @abstract   Returns a new instance of SUPSelectItem.
    @discussion 
*/

+ (SUPSelectItem*)getInstance;

/*!
 @method     
 @abstract   (Deprecated) Returns a new instance of SUPSelectItem.
 @discussion This method is deprecated. use getInstance.
 */

+ (SUPSelectItem*)newInstance DEPRECATED_ATTRIBUTE;
- (SUPSelectItem*)init;

/*!
 @property     
 @abstract   The aggregate.
 @discussion 
 */
@property(readwrite, retain, nonatomic) SUPNullableString aggregate;

/*!
 @property     
 @abstract   The alias.
 @discussion
 */
@property(readwrite, retain, nonatomic) SUPNullableString alias;

/*!
 @property     
 @abstract   The attribute.
 @discussion
 */
@property(readwrite, retain, nonatomic) SUPNullableString attribute;

/*!
 @method     
 @abstract   Returns the item SUPSelectItem for the given token.
 @discussion 
 @param token The token
 @result The SUPSelectItem.
 */
+ (SUPSelectItem*)get:(SUPString)token;


+ (SUPSelectItem*)fromJsonObject:(SUPJsonObject*)_object_1:(SUPInt)_flags;
+ (SUPJsonObject*)toJsonObject:(SUPSelectItem*)_object:(SUPInt)_flags;
- (void)readJson:(SUPJsonObject*)_object_1:(SUPInt)_flags;
- (SUPJsonObject*)writeJson:(SUPInt)_flags;
- (void)dealloc;

@end
