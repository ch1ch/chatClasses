//
//  MessageHandle.cpp
//  chats
//
//  Created by 付剑超 on 13-8-14.
//
//

#include "MessageHandle.h"
#include "MessageBase.h"
bool SendMessage(const char *dbFilename,const char *username,const char *message,const int type){
    
    if(!SendMsg(username, message, type))
        return false;
    
    int des=1;
    int LocID=SaveMsgdb(dbFilename,username,0, SyncTime(0), message, 0, type, des);

    
    char *Msgpack =PackMessage(SyncTime(0), username, message, type);
    
    int MsgSvrID=SendtoSvr(Msgpack);
    
    
    
    if(SendstatusOk(MsgSvrID, username))
    {
        int status=1;
        
        
    }
    else{

        return false;
    }

    return true;
}

bool receiveMessage(const char *dbFilename,const char *username){
    

    int type=1;
    char message[1000]="我接收到的";
    if(!SendMsg(username, message, type))
        return false;
        
    int des=2;
    
    int locID=50;
    
    int svrID=SyncSvrID(50);
    
    
    char *packMsg=ReceivePackmsg(username, svrID);
    
    char **unpackMsg=UnpackMsg(packMsg);
    int msgSvrID=60;
    
    int LocID=SaveMsgdb(dbFilename,username,msgSvrID, time(NULL), message, 0, type, des);
    
    char *Msgpack =PackMessage(SyncTime(0), username, message, type);
    
    int MsgSvrID=SendtoSvr(Msgpack);
    
    if(SendstatusOk(MsgSvrID, username))
    {
        int status=1;
        
    }
    else{

        return false;
    }

    return true;

    
}

bool DelMessage(){
    return true;
}

bool DelChat(){
    return true;
}

messageDate get1Msg(const char *dbFilename,const char *username,const int mesLocalID){
    
    char **re=GetOneMessage(dbFilename, username, mesLocalID);
    
    messageDate messagedate;
    
    for (int i=messagecolumn;i<messagecolumn*2;){
               
        messagedate.MeslocalID=re[i++];
        messagedate.MesSvrID=re[i++];
        messagedate.createTime=re[i++];
        messagedate.message=re[i++];
        messagedate.status=re[i++];
        messagedate.type=re[i++];
        messagedate.Des=re[i++];
    }

    return messagedate;
    
    
}

messageDate* getLast10Msg(const char *dbFilename,const char *username){
   
    char **re=GetNumMsg(dbFilename, username,10);
    messageDate *messagedate=new messageDate[10];
    
    for (int i=0,j=9;i<messagecolumn*10;){
        if (i%messagecolumn==0 &&i!=0) j--;
        
        messagedate[j].MeslocalID=re[i++];
        messagedate[j].MesSvrID=re[i++];
        messagedate[j].createTime=re[i++];
        messagedate[j].message=re[i++];
        messagedate[j].status=re[i++];
        messagedate[j].type=re[i++];
        messagedate[j].Des=re[i++];
    }

    return messagedate;    
}

messageDate getLastMsg(const char *dbFilename,const char *username){
    
    char **re=GetNumMsg(dbFilename, username,1);
    messageDate messagedate;
    
    for (int i=messagecolumn;i<messagecolumn*2;){
        
        messagedate.MeslocalID=re[i++];
        messagedate.MesSvrID=re[i++];
        messagedate.createTime=re[i++];
        messagedate.message=re[i++];
        messagedate.status=re[i++];
        messagedate.type=re[i++];
        messagedate.Des=re[i++];
    }
    
    return messagedate;


}