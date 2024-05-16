#include "basis.h"
#include "func.h"
char arr1[20][20] = { 0 };

struct username_type
{
    char name_arr[20];
    int user_type;
}arr2[20];



void menu_aams()
{
    menu_aams_display_1();


    int minput =0;
    cin>>minput;
    if(minput == 0 )
    {
        menu_aams_display_2();

        return ;
    }
    else
    {
        string username="test";
        string password ="test";
        cout<<"********************************"<<endl;
        cout<<"please cin your count message"<<endl;
        cout<<"enter your username "<<endl;
        cin>>username;
        cout<<"********************************"<<endl;

        secgetpasseord(password);
        // cout<<"realpass:"<<password;//Test kink good
        //system("pause");
        cout<<endl;


        if( mysql_login(username, password) )
        {
            //printf("test.");//test点
            //system("pause");
            int swinum =getwhichmenu(username);

            switch (swinum)//此时mysql仍在链接,进入菜单不许重复链接,故不传密码
            {
                case 1:menu_root(username);break;
                case 2:menu_student(username);break;
                case 3:menu_teacher(username);break;
                default : printf("程序出错");
            };
        }
        else
        {
            menu_aams_display_3();
        }


    }
    return ;
}



int getwhichmenu(string testname)
{
    int usernum = 0;
    usernum = usermessget() + 1;//用户个数
    getstruct(usernum);
    int i = 0;
    for(;i<=usernum;i++)
    {
        if(testname == arr2[i].name_arr)
        {
            break;
        }
    }
    return arr2[i].user_type;

}



void menu_root(const string& username)
{
    system("cls");
    cout<<"Hello ";
    cout<<"Welecome to root menu!!!"<<endl;
    system("pause");
}
void menu_student(const string& username)
{
    system("cls");
    cout<<"Hello student "<<username<<endl;
    cout<<"Welecome to student menu!!!"<<endl;
    system("pause");
}
void menu_teacher(const string& username)
{
    system("cls");
    cout<<"Hello teacher "<<username<<endl;
    cout<<"Welecome to teacher menu!!!"<<endl;
    system("pause");
}


//another func
void getstruct(int num)
{
    int i = 0;
    for (i; i < num; i++)
    {
        sscanf(arr1[i], "%s %d", arr2[i].name_arr, &arr2[i].user_type);
    }
    //char testname[20] = {0};
    //int testnum=0;
    //sscanf(arr1[i], "%s %d", testname, &testnum);
    //printf("%s %d", testname, testnum);

    // for (i=0; i < num; i++)
    // {
    //     printf("%s ", arr2[i].name_arr);
    //     printf("%d\n", arr2[i].user_type);
    //
    // }
}
int usermessget()
{
    int k = 0;
    FILE* fp = fopen("C:\\git\\program\\aams\\user.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 4;
    }

    {
        int i = 0;
        int j = 0;
        {
            char ch;
            while ((ch = fgetc(fp)) != EOF)
            {
                if (ch == '\n')
                {
                    arr1[i][j] = '\0';
                    i++;
                    j = 0;
                }
                else
                {
                    arr1[i][j] = ch;
                    j++;
                }

            }
            arr1[i][j] = '\0';
        }
        k = i;
        //test
        //for (int m = 0; m <= k; m++)
        //{
        //    printf("%s\n", arr1[m]);
        //}
    }
    fclose(fp);
    return k;//返回行数-1
}

void menu_aams_display_1()
{

    cout<<"You are using the academic management system!!!"<<endl;
    cout<<"********************************"<<endl;
    cout<<"********** 1  :  login   *******"<<endl;
    cout<<"********** 0  :   exit   *******"<<endl;
    cout<<"********************************"<<endl;
    cout<<" 1 / 0 ->";
}
void menu_aams_display_2()
{
    system("cls");
    cout<<"********************************"<<endl;
    cout<<" AAMS System has closed!!!"<<endl;
    cout<<"********************************"<<endl;
    system("pause");
}
void menu_aams_display_3()
{
    cout<<"********************************"<<endl;
    cout<<" Account or password error!!!"<<endl;
    cout<<"********************************"<<endl;
}
