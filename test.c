﻿#define _CRT_SECURE_NO_WARING
#include <stdio.h>

//笔试题1
/*
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d\n", *(a + 1), *(ptr - 1));
	return 0;
}//输出结果是：2,5
*/



//笔试题2
/*
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p的值为0x100000  如下表表达式的值分别为多少
//已知，结构体Test类型的变量大小是20个字节
int main()
{
	p = (struct Test*)0x100000;
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);//100000+1个字节
	printf("%p\n", (unsigned int*)p + 0x1);//100000+4个字节
	return 0;
}
//输出结果：00100014  ； 00100001  ； 00100004
*/



//笔试题3
/*
int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	//ptr1[-1] = *(ptr1 + (-1)) = *(ptr1 - 1)
	return 0;
	//输出结果：4,2000000
}
*/



//笔试题4
/*
int main()
{
	int a[3][2] = { (0,1),(2,3),(4,5) };//逗号表达式读后面的1,3,5
	int* p;
	p = a[0];//数组名表示首元素的地址
	printf("%d", p[0]);
	return 0;
	//输出结果：1
}
*/



//笔试题5
/*
int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;  //int (*)[4]  ------ int (*)[5]
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	//p[4][2] = *(*(p+4)+2)
	return 0;
}
*/



//笔试题6
/*
int main()
{
	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	//aa + 1 = aa[1] - 第二行首元素地址
	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
	return 0;
}//输出结果：10,5

	int arr[10] = {1,2,3,4,5};
	int* p = arr;
	*(p + 2) == p[2] ==> *(arr + 2) == arr[2] 
*/



//笔试题7
/*
int main()
{
	char* a[] = { "work", "at", "alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa); // 输出结果：at

	return 0;
}
*/



//笔试题8

int main()
{
	char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	 //%s 打印字符串
	printf("%s\n", **++cpp);  //POINT
	printf("%s\n", *-- * ++cpp + 3);//ER
	printf("%s\n", *cpp[-2] + 3);//ST
	printf("%s\n", cpp[-1][-1] + 1);//EW
	return 0;
}