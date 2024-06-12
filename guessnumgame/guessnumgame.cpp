#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include <iostream>
using namespace std;
//游戏要求:生成1-100的随机数
//玩家猜数字,猜数字过程中,根据玩家输入的值给出大了,或者小了的反馈



//怎么样生成随机数:C语言提供一个函数rand来生成随机数
// 原型:  int rand(void)
//注:   (1)rand函数会生成一个[伪]随机数,范围0-RAND_MAX(32767)之间,对专有名词右击转到定义
//      (2)使用rand函数,需要包含头文件<stdlib.h>
//      (3)伪随机数不是真正的随机数(因为它的下一个值可以预测,真正的随机数是无法预测下一个值是多少的),rand函数是通过某种算法生成的随机数
//         即rand函数是对一个叫做"种子"的基准运算产生的随机数,也就是说,种子不变,每次生成的随机数都一样(rand函数的默认种子是1)
//			也就是说,想要生成真正的随机数,rand函数的种子就得一直改变
//			但是为了获得一个随机数,我们就得rand函数的种子一直在变,但是rand的种子不需要也是随机变化,因为我们不能为了产生一个随机数而需要一个随机数做种子
//			所以rand函数的种子只要是一直在变化就好(看第五点)
//      (4)C语言又提供一个函数叫做srand,用来初始化随机数的生成数        //使用srand也需要使用<stdlib.h>头文件
//		   使用格式:  void srand(unsigned int seed);  //表明在括号内输入一个种子,就可以初始化/修改rand函数的随机值
//		(5)时间是每时每刻变化的,我们一般拿时间作为生成随机数的种子(时间戳的概念:时间戳是指从1970年1月1日到目前所经历的时间)
//			C语言中有一个函数叫做time函数,就可以获得时间戳,使用格式:   time_t time1(time_t* timer);
//          time函数的参数timer如果是⾮NULL的指针的话，函数也会将这个返回的差值(时间戳)放在timer指向的内存中带回去,但是这个参数必须有,也就是说必须填一个指针(空指针也行)
//			如果timer是NULL，就只返回这个时间的差值。time函数返回的这个时间差也被叫做：时间戳
//		(6)使用time函数必须包含头文件<time.h>
//		(7)如果要生成某个范围的数值,可以通过模m,加n,
//			比如想生成100-200的值,则可以%101+100 (运算法则及左值先运算为0,取使之成立的值为n,此时再将n作用于右值,使之为m(0),则m=m(0)+1)
//			公式化即为需要a-b范围的数,公式化即为  a+num%(b-a+1)
// 		

//int main()
//{
	//srand(1);
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//srand(2);
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//
	//srand((unsigned int)time(NULL));
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
	//printf("%d\n", rand());
//
//	return 0;
//}


void game()
{
	system("cls");
	printf("*******  猜数字游戏  ********\n");
	printf("请输入0-100之间的数->\n");
		int rannum = rand() % (100) + 1;
		int guess = 0;
		int count = 7;
	while (count)
	{
		printf("还有%d机会\n", count);
		printf("请输入0-100之间的数->\n\n");
		scanf("%d", &guess);
		if (guess > rannum)
			printf("猜大了\n");
		else if (guess < rannum)
			printf("猜小了\n");
		else 
		{
			printf("猜对了\n");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("很遗憾,没能在规定次数内猜对\n");
	}
}
void menu()
{
	printf("************************\n");
	printf("*****  猜数字游戏  ******\n");
	printf("******* 1. play ********\n");
	printf("******* 0. exit ********\n");
	printf("************************\n");
	printf("请选择:>");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL) );
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
			game();
			break;
			}

			case 0:
			{
				system("cls");
				printf("游戏已退出");
				break;
			}
		
			default:
			{
				printf("输入错误,请重新输入");
				input = 1;
				break;
			}

		}
	} while (input);




	return 0;
}