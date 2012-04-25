/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPObjMessageDeliverer.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Ported from Windows Mobile implementation of SUPObj.
 *                          At the moment, this is not being used, but we are keeping it 
 *                          in case it is needed later
 ******************************************************************************/

#if 0


#pragma once

#ifndef MESSAGE_DELIVERER_H
#define MESSAGE_DELIVERER_H

/******************************************************************************
* Name    : CSUPObjMessageDeliverer
* Desc    : Class for delivering message to SUP application
******************************************************************************/
class CSUPObjMessageDeliverer
{
public:
    static void DeliverToSUPApp( const char* app, const char* headers, const char* content );
};
#endif

#endif //0