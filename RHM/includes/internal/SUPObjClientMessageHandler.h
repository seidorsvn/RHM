#pragma once

#ifndef CLIENT_MESSAGE_HANDLER_H
#define CLIENT_MESSAGE_HANDLER_H


#include "SUPObj.h"

/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPObjClientMessageHandler.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Handles routing of messages from SUP client application  
 *                          to the MO layer for sending to server.
 ******************************************************************************/

class CSUPObjClientMessageHandler
{
public:
    static int Handle(
                const char* cheader,
                const unsigned char*  content,
                char *returnID
                );
};
#endif
