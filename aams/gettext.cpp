#include "basis.h"
#include "func.h"

int gettext()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    unsigned int num_fields;
    unsigned int i;

    conn = mysql_init(NULL);
    // 连接数据库
    if (mysql_real_connect(conn, "localhost", "root", "root", "mysql", 3306, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }



    // 执行 SQL 查询
    if (mysql_query(conn, "SELECT user FROM mysql.user;"))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // 获取结果集
    res = mysql_store_result(conn);
    num_fields = mysql_num_fields(res);


    FILE *file = fopen("C:\\git\\program\\aams\\output.txt", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file for writing\n");
        mysql_free_result(res);
        mysql_close(conn);
        exit(1);
    }


    // 遍历每一行
    while ((row = mysql_fetch_row(res)) != NULL)
    {

        for(i = 0; i < num_fields; i++)
        {
            string str = row[i];
            string prefix = "20";
            fprintf(file, "%s ", row[i] ? row[i] : "NULL");

            if(     strcmp(row[i],"root") == 0 )
            {
                fprintf(file, "1");
            }
            else if(  startsWith(str , prefix) )
            {
                fprintf(file, "2");
            }
            else
            {
                fprintf(file, "3");

            }



            fprintf(file, "\n");
        }

    }


    system("pause");
    // 清理资源
    mysql_free_result(res);
    mysql_close(conn);
    fclose(file);
    return 0;
}
