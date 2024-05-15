//
// Created by 15189 on 2024/5/15.
//
#include "basis.h"
#include "func.h"
bool menu_aams()
{
    string username;
    string password ="test";
    cout<<"********************************"<<endl;
    cout<<"********** 1  :  login   *******"<<endl;
    cout<<"********** 0  :   exit   *******"<<endl;
    cout<<"********************************"<<endl;
    cout<<" 1 / 0 ->";
    int minput =0;
    cin>>minput;

    if(minput == 0 )
    {
        system("cls");
        cout<<"********************************"<<endl;
        cout<<" AAMS System has closed!!!"<<endl;
        cout<<"********************************"<<endl;

        system("pause");

        return false;
    }
    else
    {
        cout<<"********************************"<<endl;
        cout<<"please cin your count message"<<endl;
        cout<<"enter your username "<<endl;
        cin>>username;
        cout<<"********************************"<<endl;


         secgetpasseord(password);
        // cout<<"realpass:"<<password;//Test kink good
        //system("pause");
        cout<<endl;

        mysql_login(username,password);

    }
    return false;
}
