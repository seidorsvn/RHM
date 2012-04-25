/******************************************************************************
 * Copyright 2009 Sybase, Inc.
 * Source File            : SUPObjJsonUtil.h
 * Created By             : Douglas Lowder
 * Date Created           : 5/25/2009
 * Platform Dependencies  : 
 * Description            : Ported from Windows Mobile implementation of SUPObj.
 *                          Used for construction and parsing of JSON.
 ******************************************************************************/

#pragma once
#ifndef NULL
#define NULL 0x00000000
#endif NULL

#ifndef JSON_UTIL_H
#define JSON_UTIL_H

enum json_type
{
    json_type_noset,
    json_type_null,
    json_type_boolean,
    json_type_int,
    json_type_float,
    json_type_object,
    json_type_array,
    json_type_string
};

typedef class CJsonArray;
typedef class CJsonObject;

/******************************************************************************
* Name    : CJsonValue
* Desc    : Json value item
******************************************************************************/
class CJsonValue
{
public:
    /******************************************************************************
    * Name    : CJsonValue
    * Desc    : Constructor
    ******************************************************************************/
    CJsonValue();
    /******************************************************************************
    * Name    : ~CJsonValue
    * Desc    : Destructor - Free alloced memory
    ******************************************************************************/
    ~CJsonValue();
    /******************************************************************************
    * Name    : Type
    * Desc    : Get the type of CJsonValue
    ******************************************************************************/
    json_type Type() const;
    /******************************************************************************
    * Name    : Set
    * Desc    : Set value as specified type
    ******************************************************************************/
    void Set( CJsonArray* );
    void Set( CJsonObject* );
    void Set( const char* );
    void Set( const int );
    void Set( const float );
    void Set( const bool );
    /******************************************************************************
    * Name    : GetXXX
    * Desc    : Get Value as specified type
    ******************************************************************************/
    CJsonArray*  GetJsonArray() const;
    CJsonObject* GetJsonObject() const;
    char*       GetString() const;
    int          GetInt() const;
    float        GetFloat() const;
    bool         GetBoolean() const;
    /******************************************************************************
    * Name    : ToString
    * Desc    : Format Json Value to string
    ******************************************************************************/
    char* ToString() const;

private:
    json_type m_type;
    union {
        CJsonArray*  arr;
        CJsonObject* obj;
        char*       str;
        int          int_value;
        float        float_value;
        bool         bool_value;
    } m_vu;
};

/******************************************************************************
* Name    : CJsonPair
* Desc    : Json key and value pair
******************************************************************************/
class CJsonPair
{
public:
    /******************************************************************************
    * Name    : CJsonPair
    * Desc    : Constructor
    ******************************************************************************/
    CJsonPair( const char* key, const CJsonValue* value );
    /******************************************************************************
    * Name    : ~CJsonPair
    * Desc    : Destructor - Free alloced memory
    ******************************************************************************/
    ~CJsonPair();

    char      *key;
    CJsonValue *value;
};

/******************************************************************************
* Name    : CJsonObject
* Desc    : Json Object Class
******************************************************************************/
class CJsonObject
{
public:
    /******************************************************************************
    * Name    : CJsonObject
    * Desc    : Constructor
    ******************************************************************************/
    CJsonObject();
    /******************************************************************************
    * Name    : ~CJsonObject
    * Desc    : Destructor - Free alloced memory
    ******************************************************************************/
    ~CJsonObject();
    /******************************************************************************
    * Name    : Size
    * Desc    : Item numbers in JsonObject
    ******************************************************************************/
    int Size() const;
    /******************************************************************************
    * Name    : GetPair
    * Desc    : Get the CJsonPair by index from JsonObject
    ******************************************************************************/
    CJsonPair* GetPair( int ) const;
    /******************************************************************************
    * Name    : Put
    * Desc    : Put a CJsonValue with a Key in JsonObject
    ******************************************************************************/
    void Put( const char*, CJsonValue* );
    void Put( const char*, CJsonArray* );
    void Put( const char*, CJsonObject* );
    void Put( const char*, const char* );
    void Put( const char*, const int );
    void Put( const char*, const float );
    void Put( const char*, const bool );
    /******************************************************************************
    * Name    : Get
    * Desc    : Get a CJsonValue by a Key from JsonObject
    ******************************************************************************/
    CJsonValue* Get( const char* ) const;
    /******************************************************************************
    * Name    : Remove
    * Desc    : Remove a CJsonPair by a Key from JsonObject
    ******************************************************************************/
    void Remove( const char* );
    /******************************************************************************
    * Name    : ToString
    * Desc    : Format Json Object to string
    ******************************************************************************/
    char* ToString() const;

private:
    int         m_max_size;
    int         m_size;
    CJsonPair **m_values;
};

/******************************************************************************
* Name    : CJsonArray
* Desc    : Json Array Class
******************************************************************************/
class CJsonArray
{
public:
    /******************************************************************************
    * Name    : CJsonArray
    * Desc    : Constructor
    ******************************************************************************/
    CJsonArray();
    /******************************************************************************
    * Name    : ~CJsonArray
    * Desc    : Destructor - Free alloced memory
    ******************************************************************************/
    ~CJsonArray();
    /******************************************************************************
    * Name    : Size
    * Desc    : Item numbers in CJsonObject
    ******************************************************************************/
    int Size() const;
    /******************************************************************************
    * Name    : Add
    * Desc    : Add a CJsonValue into array 
    ******************************************************************************/
    void Add( CJsonValue* );
    void Add( CJsonArray* );
    void Add( CJsonObject* );
    void Add( const char* );
    void Add( const int );
    void Add( const float );
    void Add( const bool );
    /******************************************************************************
    * Name    : Get
    * Desc    : Get the CJsonValue by index from array 
    ******************************************************************************/
    CJsonValue* Get( int ) const;
    /******************************************************************************
    * Name    : Remove
    * Desc    : Remove the CJsonValue by index from array 
    ******************************************************************************/
    void Remove( int );
    /******************************************************************************
    * Name    : ToString
    * Desc    : Format Json Array to string
    ******************************************************************************/
    char* ToString() const;

private:
    int          m_max_size;
    int          m_size;
    CJsonValue **m_values;
};


/******************************************************************************
* Name    : CJsonReader
* Desc    : Json object parser
******************************************************************************/
class CJsonReader
{
public:
    /**
     ** Parse a stream with JSON data (JavaScript Object Notation).
     ** Note: this method does not close the input stream.
     **/
    static CJsonObject* Read(const char*);
private:
    /**
     ** Parse an item of JSON data (JavaScript Object Notation).
     ** Return a List (for JSON array) or Map (for JSON object)
     ** or a String (for null, false, true, number or string).
     **/
    static CJsonValue* ReadItem(int, char**);
    /**
     ** Parse a JSON array up to terminating ']'.
     ** Assume leading ']' was already read.
     **/
    static CJsonArray* ReadArray(char**);
    /**
     ** Parse a JSON object up to terminating '}'.
     ** Assume leading '{' was already read.
     **/
    static CJsonObject* ReadObject(char**);
    static void   ReadSimpleValue(CJsonValue*, char**);
    static void   ReadSimpleValue(CJsonValue*, char*, int);
    static char* ReadStringValue(char**);
    static char  ReadNext(char**);
    static char  ReadNextNonSpace(char**);
    static char  ReadNextStringChar(char**);
    static char  GetCharHexUnicode(char, char, char, char);
    static float  StringToFloat(char*);
    static int    StringToInteger(char*);
};

/******************************************************************************
* Name    : CTextWriter
* Desc    : be used to output json object
******************************************************************************/
class CTextWriter
{
public:
    CTextWriter();
    ~CTextWriter();
    void   Write(char*);
    void   Write(char);
    char* ToString();
private:
    int    m_len;
    int    m_max_len;
    char* m_str;
    void   Write(char*, int);
};

/******************************************************************************
* Name    : CJsonWriter
* Desc    : Json object writer
******************************************************************************/
class CJsonWriter
{
public:
    static char* Format(const CJsonObject* value);
    static char* Format(const CJsonArray*  value);
    static char* Format(const CJsonValue*  value);
private:
    static void WriteObject(CTextWriter*, CJsonObject*);
    static void WriteArray(CTextWriter*, CJsonArray*);
    static void WriteValue(CTextWriter*, CJsonValue*);
    static void WriteQuoted(CTextWriter*, char*);
    static void WriteUnicodeEscape(CTextWriter*, char);
};

class JsonFormatException
{
};
#endif
