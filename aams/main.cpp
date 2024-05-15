#include "basis.h"
#include "func.h"
MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW column;
int main()
{
    bool input = 0 ;
    cout<<"You are using the academic management system!!!"<<endl;
    do
    {
        input =menu_aams();
    }while(input);
    return  0;
}
