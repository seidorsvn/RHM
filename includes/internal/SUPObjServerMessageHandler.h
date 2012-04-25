/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPObjServerMessageHandler.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Ported from Windows Mobile implementation of SUPObj.
 *                          Parses messages from server, handles PIM messages appropriately,
 *                          passes server messages to SUPDeliverMessage.m for SUP client app.
 ******************************************************************************/

#pragma once

#ifndef SERVER_MESSAGE_HANDLER_H
#define SERVER_MESSAGE_HANDLER_H

/******************************************************************************
* Name    : CSUPObjServerMessageHandler
* Desc    : Class for handling message from iMO server
******************************************************************************/
class CSUPObjServerMessageHandler
{
public:
    static void Handle( const char* headers, const unsigned char* content, unsigned int uiByteCount );
};

#endif
