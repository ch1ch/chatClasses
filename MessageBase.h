//
//  MessageBase.h
//  chats
//
//  Created by 付剑超 on 13-8-15.
//
//
#ifndef namelong
#define namelong 100
#endif
#ifndef messagecolumn
#define messagecolumn 7
#endif

#ifndef __chats__MessageBase__
#define __chats__MessageBase__

#include <iostream>

//#include "sqlite3.h"




bool SendMsg(const char *username,const char *message,const int type);

int SyncTime(const int localTime);

char *PackMessage(const int createTme ,const char *username,const char *message,const int type );

int SaveMsgdb(const char *dbFilename,const char *username,const int mesSvrID,const int createTime,const char *message,const int status,const int type,  const int des);

int SendtoSvr(const char *packMsg);

bool SendstatusOk(const int mesSvrID,const char *username);

bool SendMesLocalID(const int meslocalID);

int SyncSvrID(const int meslocalID);

char *ReceivePackmsg(const char *username, const int mesSvrID);

char **UnpackMsg(const char *mackMsg);

bool MsgReadstatus(const char *user,const int mesSvrID);

bool DelMsg(const char *username,const int MesLocID);

bool DelChat(const char *username);

char **GetOneMessage(const char *dbFilename,const char *username,const int mesLocalID);

char **GetNumMsg(const char *dbFilename,const char *username,const int msgnum);

#endif /* defined(__chats__MessageBase__) */



