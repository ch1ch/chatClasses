//
//  sqlite3DB.h
//  chats
//
//  Created by 付剑超 on 13-8-12.
//
//

#ifndef __chats__sqlite3DB__
#define __chats__sqlite3DB__

#include <iostream>
#include "sqlite3.h"

#include "Main.h"

class SQLiteUtil
{
public:
    SQLiteUtil();
    
    ~SQLiteUtil();
    
    sqlite3 *PrepareDB(const char *dbFilename,const char *username);
    
    void ReadFromSQLite(const char *dbFilename,const char *username);
    
    int AddMessage(const char *dbFilename,const char*username,const int SvrID,const int creatTime,const char *message,const int status,const int type,const int Des);
    
    bool DelMessage(const char *dbFilename,const char*username,const int MesLocalID);
    
    char ** MessageallGet(const char *dbFilename,const char *username);
    
    char ** GetlastMsg(const char *dbFilename,const char *username,const int msgnum);

    char ** GetOnemsg(const char *dbFilename,const char *username,const int mesLocalID);

    int MessageallRow(const char *dbFilename,const char *username);
    
    bool UpdateMesdb(const char *dbFilename,const char*username,const int SvrID,const int creatTime,const char *message,const int status,const int type,const int Des);
    
    bool DeleteTable(const char *dbFilename,const char *username);



};

//int loadUserRecord(void *para,int n_column,char**column_value,char**column_name);

#endif /* defined(__chats__sqlite3DB__) */
