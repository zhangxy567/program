#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <iostream>
using namespace std;

int main()
{ 
	char charget[20] = { 0 };
	printf("******************是否关机?**************** \n");
	printf("***输入y:一分钟后关机   ****   输入n:取消关机***\n");
	errorto:
	scanf("%s", charget);
	if (strcmp("y", charget) == 0)
	{
		printf("输入成功,一分钟后关机\n");
		system("shutdown -s -t 60");
		goto errorto;
	}

	else if (strcmp("n", charget) == 0)
	{
		system("shutdown -a");
		printf("取消关机成功!!!\n");
		goto errorto;
	}
	else
	{
		printf("输入错误,重新输入\n");
		goto errorto;
	}

	return 0;
}