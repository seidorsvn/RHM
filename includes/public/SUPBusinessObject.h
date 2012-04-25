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

/*!
 @protocol
 @abstract    This protocol declares a common interface that is implemented by all Sybase Unwired Platform business objects (entities or MBOs, both client-only and server-communicating).  
 @discussion  See also @link //apple_ref/occ/intf/SUPLocalBusinessObject SUPLocalBusinessObject @/link and @link //apple_ref/occ/intf/SUPMobileBusinessObject SUPMobileBusinessObject @/link.

 */

@protocol SUPBusinessObject<NSObject>
/*!
    @method     
    @abstract   Returns true if the entity is new.
    @discussion 
*/

//- (SUPBoolean)isNew;

/*!
 @method     
 @abstract   Returns true if the entity is was loaded from the database and was subsequently modified (in memory), but the change has not yet been saved to the database.
 @discussion 
 */
//- (SUPBoolean)isDirty;

/*!
 @method     
 @abstract   Returns true if this entity was loaded from the database and was subsequently deleted.
 @discussion 
 */

//- (SUPBoolean)isDeleted;


- (void)save;
- (void)create;
- (void)update;
- (void)delete;
- (void)refresh;

@end
