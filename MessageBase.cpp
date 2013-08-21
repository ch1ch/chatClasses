//
//  MessageBase.cpp
//  chats
//
//  Created by 付剑超 on 13-8-15.
//
//

#include "MessageBase.h"
#include "sqlite3DB.h"


bool SendMsg(const char *username,const char *message,const int type){
    
    

    return true;
    
}

int SyncTime(const int localTime){
    return time(NULL);
    
}

char *PackMessage(const int createTme ,const char *username,const char *message,const int type ){
    return NULL;
}

int SaveMsgdb(const char *dbFilename,const char *username,const int mesSvrID,const int createTime,const char *message,const int status,const int type, const int des){
    SQLiteUtil *DButil=new SQLiteUtil();
    int LocID=DButil->AddMessage(dbFilename,username, mesSvrID, createTime,message, status, type, des);
    //DButil->ReadFromSQLite(dbFilename,username);
    
    delete DButil;


    
    return LocID;
    
}

int SendtoSvr(const char *packMsg){
    

    return 0;
}

bool SendstatusOk(const int mesSvrID,const char *username){
    

    return true;
    
}

bool SendMesLocalID(const int meslocalID){
    return true;
    
}
int SyncSvrID(const int meslocalID){
    return 0;
}


char *ReceivePackmsg(const char *username, const int mesSvrID){
    

    return NULL;
}

char **UnpackMsg(const char *packMsg){
    
 
    return NULL;
}

bool MsgReadstatus(const char *user,const int mesSvrID){
    

    return true;
    
}

bool DelMsg(const char *username,const int MesLocID){
    
   
    return true;
    
}

bool DelChat(const char *username){
    

    return true;
    
}
char **GetOneMessage(const char *dbFilename,const char *username,const int mesLocalID){
    SQLiteUtil *DButil=new SQLiteUtil();
    char** result= DButil->GetOnemsg(dbFilename, username, mesLocalID);
    
    delete DButil;

    return result;
}

char **GetNumMsg(const char *dbFilename,const char *username,const int msgnum){
    SQLiteUtil *DButil=new SQLiteUtil();
    char** result= DButil->GetlastMsg(dbFilename, username, msgnum);
    
    delete DButil;

    
    return result;
}



