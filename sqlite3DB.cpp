//
//  sqlite3DB.cpp
//  chats
//
//  Created by 付剑超 on 13-8-12.
//
//

#include "sqlite3DB.h"

#include "MessageBase.h"


SQLiteUtil::SQLiteUtil(){
    
}


SQLiteUtil::~SQLiteUtil(){
    
}


sqlite3 *  SQLiteUtil::PrepareDB(const char *dbFilename,const char*username){
    sqlite3 *pdb=NULL;
    char * errMsg=NULL;
    
    
    std::string sql;
    int result;
    result=sqlite3_open(dbFilename,&pdb);
    if(result!=SQLITE_OK)
        printf("open database  chat_%s on DB %s failed,  number%d",username,DbName,result);
    
    sql=sqlite3_mprintf("select * from chat_%s",username);
    
    result=sqlite3_exec( pdb, sql.c_str() ,NULL, NULL, &errMsg );
    
    if(result!=SQLITE_OK)
    {
        sql=sqlite3_mprintf("create table chat_%s ( MesLocalID integer primary key autoincrement,MesSvrID integer,createTime integer,message text,status integer,type integer,Des integer)",username);
    
        result=sqlite3_exec(pdb,sql.c_str(),NULL,NULL,&errMsg);

        if(result!=SQLITE_OK)
            printf("create table failed ,错误原因:%s",errMsg);
    }
    

    
    return pdb;
 

}

int SQLiteUtil::AddMessage(const char *dbFilename,const char*username,const int SvrID,const int creatTime,const char *message,const int status,const int type,const int Des){
    sqlite3* pDB=PrepareDB(dbFilename,username);
    std::string sql;
    int result;
    char * errMsg=NULL;
    
    printf("12345");
     if(pDB!=NULL){
         sql=sqlite3_mprintf("insert into chat_%s(MesSvrID,createTime,message,status,type,Des)  values(%d,%d,'%q',%d,%d,%d)",username,SvrID,creatTime,message,status,type,Des);
         result=sqlite3_exec(pDB,sql.c_str(),NULL,NULL,&errMsg);
         if(result!=SQLITE_OK)
             printf("insert data failed!错误原因:%s..sql:%s",errMsg,sql.c_str());
     }
    char **re;
    int r,c;
    sql=sqlite3_mprintf("select MeslocalID from  chat_%s order by MeslocalID DESC limit 1",username,SvrID,creatTime,message,status,type,Des);
    //result=sqlite3_exec(pDB,sql.c_str(),NULL,NULL,&errMsg);
    sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c, &errMsg);
    
    if(result!=SQLITE_OK)
        printf("set  failed!错误原因:%s..sql:%s\n",errMsg,sql.c_str());
    

    
    sqlite3_close(pDB);
    return atoi(re[1]);
}
bool SQLiteUtil::DelMessage(const char *dbFilename,const char*username,const int MesLocalID){
    sqlite3* pDB=PrepareDB(dbFilename,username);
    std::string sql;
    int result;
    char * errMsg=NULL;
    if(pDB!=NULL){
        sql=sqlite3_mprintf("delete from chat_%s where  MesLocalID = %d",username,MesLocalID);
        result=sqlite3_exec(pDB,sql.c_str(),NULL,NULL,&errMsg);
        if(result!=SQLITE_OK)
        {
            printf("delete data failed!错误原因:%s..sql:%s",errMsg,sql.c_str());
            sqlite3_close(pDB);

            return false;
        }
        else{
            sqlite3_close(pDB);

            return true;
        }
    }
    else {

        return false;
    }
    
}




char** SQLiteUtil::GetlastMsg(const char *dbFilename,const char *username,const int msgnum){
    

    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    char **re;
    int r,c;
    if(pDB!=NULL){
        
        sql=sqlite3_mprintf("select * from chat_%s order by MeslocalID DESC limit %d",username,msgnum);
        sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c, &errMsg);
        sqlite3_close(pDB);

        
        return re;
    }
    else {

        return 0;
    }

    
}

int loadUserRecord(void *para,int n_column,char**column_value,char**column_name){
    
   // printf("id=%s,svrid=%s,creattime=%s,message=%s,status=%s,type=%s,des=%s\n",column_value[0],column_value[1],column_value[2],column_value[3],column_value[4],column_value[5],column_value[6],column_value[7]);
    

    return 0;
}

void SQLiteUtil::ReadFromSQLite(const char *dbFilename,const char *username){
    
    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    if(pDB!=NULL){

        sql=sqlite3_mprintf("select * from chat_%s",username);
        
        sqlite3_exec( pDB, sql.c_str() , loadUserRecord, NULL, &errMsg );
        
        if(errMsg!=NULL){
            printf("exec sql  witherror log:%s",errMsg);
            sqlite3_close(pDB);

        }
        
    }

    sqlite3_close(pDB);
}


char**  SQLiteUtil::MessageallGet(const char *dbFilename,const char*username){
    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    char **re;
    int r,c;
    if(pDB!=NULL){
        
        sql=sqlite3_mprintf("select * from chat_%s",username);
        sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c, &errMsg);
        sqlite3_close(pDB);
        delete dbFilename;
        delete username;
        delete errMsg;
        
        return re;
    }
    else {
        delete dbFilename;
        delete username;
        delete errMsg;
        return 0;
    }
    
}
int SQLiteUtil::MessageallRow(const char *dbFilename,const char *username){
    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    if(pDB!=NULL){
        char **re;
        int r,c;
        sql=sqlite3_mprintf("select * from chat_%s",username);
        sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c, &errMsg);
        //printf("row is %d ,column is %d ",r,c);
        sqlite3_close(pDB);
        delete dbFilename;
        delete username;
        delete errMsg;
        delete re;
        return r;
    }else {
        sqlite3_close(pDB);
        delete dbFilename;
        delete username;
        delete errMsg;
        return 0;
    }
    
}
bool SQLiteUtil::UpdateMesdb(const char *dbFilename,const char*username,const int SvrID,const int creatTime,const char *message,const int status,const int type,const int Des){
    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    if(pDB!=NULL){
        sql=sqlite3_mprintf("update chat_%s set MesSvrID=%d,createTime=%d,message=%q,status=%d,type=%d,Des=%d",username,SvrID,creatTime,message,status,type,Des);
        char result=sqlite3_exec(pDB,sql.c_str(),NULL,NULL,&errMsg);
        
        if(result!=SQLITE_OK)
        {
            printf("update data failed!错误原因:%s..sql:%s",errMsg,sql.c_str());
            sqlite3_close(pDB);
            delete dbFilename;
            delete username;
            delete errMsg;
            return false;
        }
        else{
            sqlite3_close(pDB);
            delete dbFilename;
            delete username;
            delete errMsg;
            return true;
        }

    }else
        return false;
    
}

bool  SQLiteUtil::DeleteTable(const char *dbFilename,const char *username){
        std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
        char *errMsg;
        if(pDB!=NULL){
            sql=sqlite3_mprintf("drop table chat_%s",username);
            char result=sqlite3_exec(pDB,sql.c_str(),NULL,NULL,&errMsg);
            if(result!=SQLITE_OK)
            {
                printf("update data failed!错误原因:%s..sql:%s",errMsg,sql.c_str());
                sqlite3_close(pDB);
                delete dbFilename;
                delete username;
                delete errMsg;
                return false;
            }
            else{
                sqlite3_close(pDB);
                delete dbFilename;
                delete username;
                delete errMsg;
                return false;
            }
        }
        else return false;

}

char ** SQLiteUtil::GetOnemsg(const char *dbFilename,const char *username,const int mesLocalID){
    std::string sql;
    sqlite3* pDB=PrepareDB(dbFilename,username);
    char *errMsg;
    char **re;
    int r,c;
    if(pDB!=NULL){
        
        sql=sqlite3_mprintf("select * from chat_%s where  MesLocalID = %d",username,mesLocalID);
        char result=sqlite3_get_table(pDB, sql.c_str(), &re, &r, &c, &errMsg);
        if(result!=SQLITE_OK)
            printf("get id=%d data failed!错误原因:%s..sql:%s",mesLocalID,errMsg,sql.c_str());
        sqlite3_close(pDB);

        return re;
    }
    else{
        sqlite3_close(pDB);

        return 0;
    }
    
}