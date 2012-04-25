/*
 *  SUPObjConnectionUtil.h
 *  SUPObj
 *
 *  Created by Jane Yang on 11/23/09.
 *  Copyright 2009 Sybase, Inc.. All rights reserved.
 *
 */
#pragma once

#ifndef CONNECTION_UTIL_H
#define CONNECTION_UTIL_H

#include "SUPObjJsonUtil.h"

class CSUPObjConnectionUtil
{
    public:
        static const char* GetConnectionStateName(const int);
        static const char* GetConnectionTypeName(const int);
};
#endif
