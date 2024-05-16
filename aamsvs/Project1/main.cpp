#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include <iostream>




int usermessget();
void getstruct(int num);
int judicewhichmenu();


char arr1[20][20] = { 0 };


struct username_type
{
    char name_arr[20];
    int user_type;
}arr2[20];




int main()
{
    int k = judicewhichmenu();
}




int judicewhichmenu()
{
    int usernum = 0;
    usernum = usermessget() + 1;
    getstruct(usernum);
    return 0;
}


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
    
    for (i=0; i < num; i++)
    {
        printf("%s ", arr2[i].name_arr);
        printf("%d\n", arr2[i].user_type);

    }
}
int usermessget()
{
    int k = 0;
    FILE* fp = fopen("user.txt", "r");
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
    return k;//·µ»ØÐÐÊý-1
}