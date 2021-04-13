#define _CRT_SECURE_NO_WARING
#include <stdio.h>

int main()
{
	//数组名是首元素的地址
	//1. sizeof（数组名） - 数组名表示整个数组
	//2. &数组名 - 数组名表示整个数组
	// 
	//一维数组
	int a[] = { 1,2,3,4 }; //整形数组，4个元素， 4*4 = 16
	printf("%d\n", sizeof(a));  //16 - sizeof(数组名) - 计算的是数组总大小 - 单位是字节 - 16
	printf("%d\n", sizeof(a+0)); //4 - 数组名这里表示首元素的值，a+0还是首元素地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(*a));  //4 - 数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4
	printf("%d\n", sizeof(a+1)); //4/8 - 数组名这里表示首元素的值，a+1第2个元素的地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(a[1]));//4 - 第2个元素的大小
	printf("%d\n", sizeof(&a));  //4 - &a取出的是数组的地址，但是数组的地址那也是地址，地址的大小就是4/8个字节
	printf("%d\n", sizeof(*&a)); //16 - &a是数组的地址，数组的地址解引用访问的是整个数组，sizeof计算的就是数组的大小，单位是字节
	printf("%d\n", sizeof(&a+1));//4/8 - &a是数组的地址，&a+1虽然地址跳过整个数组，但还是地址，所以是4/8个字节
	printf("%d\n", sizeof(&a[0]));//4/8 - &a[0]是第一个元素的地址
	printf("%d\n", sizeof(&a[0]+1));//4/8 - &a[0]+1是第二个元素的地址



	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));    //sizeof计算的是数组大小，6*1 = 6字节
	printf("%d\n", sizeof(arr+0));  //4/8，arr是首元素的地址，arr+0还是首元素的地址，地址的大小是4/8字节
	printf("%d\n", sizeof(*arr));   //1 - arr是首元素的地址，*arr就是首元素，首元素是字符，大小是一个字节
	printf("%d\n", sizeof(arr[1])); //1 - 计算第二个元素的大小，第二个元素是一个字符
	printf("%d\n", sizeof(&arr));   //&arr虽然是数组的地址，但还是地址，地址的大小是4/8个字节
	printf("%d\n", sizeof(&arr+1)); //&arr+1是跳过整个数组后的地址，地址大小是4/8个字节
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 - 第二个元素的地址

	printf("%d\n", strlen(arr));    //随机值   strlen碰到\0才停止
	printf("%d\n", strlen(arr + 0));//随机值
	printf("%d\n", strlen(*arr));   //err
	printf("%d\n", strlen(arr[1])); //err

	printf("%d\n", strlen(&arr));   //随机值，
	printf("%d\n", strlen(&arr + 1));//随机值，比上一个&arr少6
	printf("%d\n", strlen(&arr[0] + 1));//随机值，比&arr少1


	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));   //sizeof(arr)计算的是数组的大小，单位是字节：7 ,有\0
	printf("%d\n", sizeof(arr+0)); // 4/8 - 计算的是地址的大小 arr+0是首元素的地址
	printf("%d\n", sizeof(*arr));  //1 - *arr是首元素，sizeof(*arr)计算首元素的大小
	printf("%d\n", sizeof(arr[1]));//1 - arr[1]是第二个元素，sizeof(arr[1])计算的是第二个元素的大小
	printf("%d\n", sizeof(&arr));  //4/8 - &arr虽然是数组的地址，但也是地址，所以是4/8个字节
	printf("%d\n", sizeof(&arr+1));//4/8 - &arr+1是跳过整个数组后的地址，但也是地址
	printf("%d\n", sizeof(&arr[0]+1));//4/8 - &arr[0]+1	第二个元素的地址

	printf("%d\n", strlen(arr));      //6
	printf("%d\n", strlen(arr + 0));  //6
	printf("%d\n", strlen(*arr));     //err
	printf("%d\n", strlen(arr[1]));   //err
	printf("%d\n", strlen(&arr));     //6  &arr - 数组的地址-数组指针 char(*p)[7] = &arr;
	printf("%d\n", strlen(&arr + 1)); // 随机值
	printf("%d\n", strlen(&arr[0] + 1));//5


	char* p = "abcdef";           
	printf("%d\n", sizeof(p));      //4/8 - 计算指针变量p的大小
	printf("%d\n", sizeof(p + 1));  //4/8 - p+1 得到的是字符b的地址
	printf("%d\n", sizeof(*p));     //1  - *p就是字符串的第一个字符 - 'a'
	printf("%d\n", sizeof(p[0]));   //1 - int arr[10];  arr[0] == *(arr+0)     p[0] == *(p+0) =='a'
	printf("%d\n", sizeof(&p));     //4 - 地址
	printf("%d\n", sizeof(&p + 1)); //4 - 地址
	printf("%d\n", sizeof(&p[0] + 1));//4/8 - 地址

	printf("%d\n", strlen(p));       //6,存的是a的地址
	printf("%d\n", strlen(p + 1));   //5，存的是b的地址
	printf("%d\n", strlen(*p));      //err
	printf("%d\n", strlen(p[0]));    //err
	printf("%d\n", strlen(&p));      //随机值
	printf("%d\n", strlen(&p + 1));  //随机值
	printf("%d\n", strlen(&p[0] + 1)); //5 - 第二个元素的地址



	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));      //3*4*4 = 48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));   //16 - a[0]相当于第一行作为一维数组的数组名，sizeof(arr[0])把数组名单独放在sizeof()内，
	                                //计算的是第一行的大小
	printf("%d\n", sizeof(a[0]+1)); //4 -  a[0]是第一行的数组名，数组名此时是首元素的地址，a[0]其实就是第一行第一个元素的地址
	                                //所以 a[0]+1 就是第一行第二个元素的地址，地址大小是4/8个字节
	printf("%d\n", sizeof(*(a[0]+1)));//*(a[0]+1) 是第一行第二个元素，大小是4个字节
	printf("%d\n", sizeof(a+1));      //a是二维数组的数组名，没有sizeof(数组名)，也没有&(数组名)，所以a是首元素地址
	                                  //而把二维数组看成一位数组时，二维数组的首元素是他的第一行，a就是第一行(首元素)的地址
	                                  //a+1就是第二行的地址
	printf("%d\n", sizeof(*(a + 1)));// =sizeof(a[1]), 16 - 计算第二行的大小，单位是字节
	printf("%d\n", sizeof(&a[0]+1)); //4 - 第二行的地址 
	printf("%d\n", sizeof(*(&a[0] + 1)));//16 - 计算第二行的大小，单位是字节
	printf("%d\n", sizeof(*a));      //16 - a是首元素地址 - 第一行的地址，*a就是第一行，sizeof(*a)就是计算第一行的大小
	printf("%d\n", sizeof(a[3]));    //16 - 不访问，只计算大小

	//sizeof（数组名），这里的数组名表示整个数组，计算的是整个数组的大小
	//&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
	//除此之外所有的数组名都表示首元素的地址
	return 0;
}
