/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPDeliverMessage.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Takes header and content character strings from MOCA, creates an SUPJsonMessage object,
 *                          and passes it to the SUP queue connection.
 ******************************************************************************/

extern "C" {

    void SUPDeliverMessage(int cid, const char *headers, const unsigned char *content, unsigned int uiByteCount);
    void SUPDeliverLocalMessage(const char *headers);
	char *getApplicationNameAsCString();
}