#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>
// Sleep 函数是windows提供的函数,功能是延时输出,延时单位是ms / 1000ms=1s
// Sleep和system("cls")可以形成很好的动画延时效果
// sizeof求的是整个变量类型(变量可以是内置类型,也可以是数组结构体)的大小(单位字节)  
// strlen求的是字符数组(仅局限于字符)中第一个字符'\0'前面的字符个数
//
// 
// 
//

#include <iostream>
using namespace std;

int main()
{
	char arrch1[] = "welcome to C++!!!";
	char arrch2[] = "*****************";
	int lefcoor=0;
	int rigtcoor=strlen(arrch1)-1;

	while(lefcoor<=rigtcoor)
	{
		system("cls");
		arrch2[lefcoor] = arrch1[lefcoor];
		arrch2[rigtcoor] = arrch1[rigtcoor];
		printf("%s\n", arrch2);
		lefcoor++;
		rigtcoor--;
		Sleep(700);

	}

	return 0;
}