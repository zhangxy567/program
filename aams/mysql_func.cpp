//
// Created by 15189 on 2024/5/15.
//
#include "basis.h"
#include "etrdef.h"

bool ConnectMysql( const string & username, const string & password)
{
    mysql_init(&mysql);//初始化mysql


    if (
            !(mysql_real_connect(&mysql,"localhost",username.c_str(),
             password.c_str(),"aams",3306,NULL, 0))
       )
    {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    }
    else
    {
        cout << "Connected..." << endl;
        return true;
    }
}
void mysql_login(string userlogin,string passlogin)
{

    ConnectMysql(userlogin,passlogin);
    system("pause");
    return ;
}