/* Copyright (c) Sybase, Inc. 2009   All rights reserved.

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
 modified Code;OT BE LIABLE FOR ANY LOSS OR DAMAGE RELATING
 TO MODIFICATIONS MADE TO THE CODE OR FOR ANY DAMAGES RESULTING FROM USE OF THE
 MODIFIED CODE, INCLUDING, WITHOUT LIMITATION, ANY INACCURACY OF DATA, LOSS OF
 PROFITS OR DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, EVEN
 IF SYBASE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
 to indemnify, hold harmless, and defend Sybase from and against any claims or
 lawsuits, including attorney's fees, that arise from or are related to the
 modified Code or from use of the modified Code.

*/

//
// SUPMessageLiterals.h
//
// Copyright 2009 Sybase Inc. All rights reserved.
//
// see document below for more details
// http://share/sites/pto/adg/uep/Functional%20Specifications/Blue%20Nile%20(R2)%20Specifications/SUP-CGP-UTR-SUP-1.5.html

#import <Foundation/Foundation.h>

// Headers string literals
extern NSString* MSGHDR_PKG;
extern NSString* MSGHDR_MBO;
extern NSString* MSGHDR_METHOD;
extern NSString* MSGHDR_ID;
extern NSString* MSGHDR_CID;
extern NSString* MSGHDR_PID;
extern NSString* MSGHDR_UPA;
extern NSString* MSGHDR_PPM;
extern NSString* MSGHDR_LOG;
extern NSString* MSGHDR_PV;
extern NSString* MSGHDR_LOGINFAILED;
extern NSString* MSGHDR_CONNSTATUS;
extern NSString* MSGHDR_CONNTYPE;
extern NSString* MSGHDR_CONNERRORCODE;
extern NSString* MSGHDR_CONNERRORSTRING;
extern NSString* MSGHDR_NOSUB;
extern NSString* MSGHDR_SUBSCRIBED;

// Client to Server methods string literals
extern NSString* CMETHOD_LOGIN;
extern NSString* CMETHOD_SUBSCRIBE;
extern NSString* CMETHOD_SUBSCRIBEWITHSYNCPARAMS;
extern NSString* CMETHOD_UNSUBSCRIBE;
extern NSString* CMETHOD_SUSPEND;
extern NSString* CMETHOD_RESUME;
extern NSString* CMETHOD_REPLAY;
extern NSString* CMETHOD_SEARCH;
extern NSString* CMETHOD_RECOVER;
extern NSString* CMETHOD_SYNCHRONIZE;
extern NSString* CMETHOD_BEGINSYNCHRONIZE;

// Server to Client methods string literal
extern NSString* SMETHOD_LOGIN_RESULT;
extern NSString* SMETHOD_LOGIN_FAILED;
extern NSString* SMETHOD_SUBSCRIBE_RESULT;
extern NSString* SMETHOD_SUBSCRIBE_FAILED;
extern NSString* SMETHOD_UNSUBSCRIBE_RESULT;
extern NSString* SMETHOD_UNSUBSCRIBE_FAILED;
extern NSString* SMETHOD_SUSPEND_RESULT;
extern NSString* SMETHOD_SUSPEND_FAILED;
extern NSString* SMETHOD_RESUME_RESULT;
extern NSString* SMETHOD_RESUME_FAILED;
extern NSString* SMETHOD_REPLAY_RESULT;
extern NSString* SMETHOD_REPLAY_FAILED;
extern NSString* SMETHOD_SEARCH_RESULT;
extern NSString* SMETHOD_SEARCH_FAILED;
extern NSString* SMETHOD_IMPORT;
extern NSString* SMETHOD_SYNCHRONIZE_RESULT;
extern NSString* SMETHOD_SYNCHRONIZE_FAILED;
extern NSString* SMETHOD_CONNECTION_CHANGED;
extern NSString* SMETHOD_REREGISTER;

// suffix and prefix string literals
extern NSString* FAILURE;
extern NSString* SUCCESS;

