/*
 *  SUPObjDeviceConnection.h
 *  SUPObj
 *
 *  Created by Jane Yang on 11/23/09.
 *  Copyright 2009 Sybase, Inc.. All rights reserved.
 *
 */

#pragma once

#ifndef DEVICE_CONNECTION_H
#define DEVICE_CONNECTION_H

/******************************************************************************
 * Name    : CSUPObjDeviceConnection
 * Desc    : Class for handling messages assembled in SUPObj.
 *
 ******************************************************************************/
class CSUPObjDeviceConnection
{
    public:
        static void HandleConnectionStateChanged(
                                                 int iConnectionStatus, 
                                                 int iConnectionType,
                                                 int iError,
                                                 const char *pcErrorMessage);
        static void HandleRefreshData();
};
#endif
