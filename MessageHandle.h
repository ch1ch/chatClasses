//
//  MessageHandle.h
//  chats
//
//  Created by 付剑超 on 13-8-14.
//
//

#ifndef __chats__MessageHandle__
#define __chats__MessageHandle__

#include <iostream>


struct messageDate
{
    char *MeslocalID;
    char *MesSvrID;
    char *createTime;
    char *message;
    char *status;
    char *type;
    char *Des;
    
};

bool SendMessage(const char *dbFilename,const char *username,const char *message,const int type);

bool receiveMessage(const char *dbFilename,const char *username);

bool DelMessage();

bool DelChat();

messageDate get1Msg(const char *dbFilename,const char *username,const int mesLocalID);

messageDate* getLast10Msg(const char *dbFilename,const char *username);

messageDate getLastMsg(const char *dbFilename,const char *username);


#endif /* defined(__chats__MessageHandle__) */
