/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPObj.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Header for SUPObj interface used by libMO to transfer SUP messages 
 *                          between libMO and an SUP application.
 ******************************************************************************/


#pragma once

#ifndef __SUP_OBJ_H__
#define __SUP_OBJ_H__

#import <SupInterface.h>


#ifndef NULL
#define NULL 0x00000000
#endif NULL

#define L_ERROR             5
#define L_WARN              4
#define L_INFO              3
#define L_DEBUG             2
#define L_TRACE             1

typedef int (*PFNHandleMessageFromSUPClient)( const char* pcHeader,   // header argument
                                                const unsigned char* pbData,      // data argument
                                              char * returnID // if this is pim create operation, pim id will be returned.
                                                );

#if 0 
void SUPInitialize( PFNQueueAsyncMethodCallForServer pfnQueueAsyncMethodCallForServer, 
                            PFNWriteToPIM pfnWriteToPIM,
                            PFNLogText pfnLogText );

void SUPPIMChangeNotification( int iPimStore, int iOperation, const char* pcRecordID, 
                              const char* pcPimData, const char* pcSUPAppName );
void SUPDatastoreCleared( int iPimStoreType );
int SUPWriteToPIM(
                  int iPimStoreType,       // PIM store type
                  int iOperation,          // PIM operation
                  const char* pcPimData,  // PIM data
                  const char* pcSUPAppName,  // associated app name 
                  char* pcRecordID        // PIM record ID
                  );
#endif
void SUPInitialize( PFNQueueAsyncMethodCallForServer pfnQueueAsyncMethodCallForServer,
                   PFNLogText pfnLogText,
                   char *pcApplicationName );

void SUPDispose();

void SUPAsyncMethodCallFromServer( const char* pcHeader, const unsigned char* pbData, unsigned int uiByteCount );  

void SUPRefreshAllData();

void SUPLog(int loglevel, char *logmessage);

int SUPQueueAsyncMessageCallForServer(
    const char* pcHeader,     // header argument received
    const unsigned char* pbData,        // data argument received
    unsigned int uiByteCount   // length of data argument
    );

int SUPHandleMessageFromSUPClient(
                                    const char* cheader,
                                    const unsigned char*  content
                                );

void SUPConnectionStateChanged( int iConnectionStatus, int iConnectionType, int iError, const char *pcErrorMessage );

#endif //__SUP_OBJ_H__
