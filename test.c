#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//为什么要存在动态内存分配呢？
//int val = 20; // 在栈空间上开辟4个字节
//char arr[10] = { 0 }; //在栈空间上开辟10个字节的连续空间
//但是上述的开辟空间的方式有两个特点：
//1.空间开辟大小是固定的
//2.数组在什么的时候，必须指定数组的长度，它所需要的内存在编译时分配。
//但是对于空间的需求，不仅仅是上述的情况，有时候我们需要的空间大小在程序运行的时候才知道，那数组的编译时开辟空间的方式就不能满足了。
//所以这时候就需要引入动态内存开辟了。

//#include<stdlib.h> //malloc的头文件
//void* malloc(size_t size); // 声明
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	//向内存申请10个整形的空间
//	int* p = (int*)malloc(10 * sizeof(int)); //当申请成功的时候就会返回申请到的起始地址
//	if (p == NULL) // 但也有一定的可能会申请失败，就会返回一个空指针
//	{
//		//打印错误的原因
//		printf("%s\n", strerror(errno));
//	}
//  当动态申请的空间不再使用的时候
//就应该还给操作系统，引入了free这个函数
//	return 0;
//}




//
//void* calloc(size_t num, size_t size); //声明 
//1.函数的功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0.
//2.与malloc的区别只是在于calloc会在返回地址之前把申请的空间的每个字节初始化为0.



//calloc
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//}
////realloc
//1.realloc函数的出现让动态内存管理更加的灵活
//2.有事我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理内存，我们一定会对内存的大小做灵活的调整。
//void* realloc(void* ptr, size_t size);
//其中：
//1.ptr是要调整的内存地址
//2.size调整之后新的大小
//3.返回值为调整之后的内存起始位置
//4.这个函数调整原内存空间的大小基础上，还会将原来内存中的数据移动到新的空间

//在开辟的时候把realloc返回的地址用一个新的指针来接收
  //  int* ptr = realloc(P, INT_MAX);
  //  if (ptr != NULL)
  //  {
		//p = ptr;
  //   }

//int main()
//{
//	int* p = (int*)malloc(5*sizeof(int));
//	if (p == NULL)
//	{
//		return 0;
//	}
//	else 
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;
//	*p = 20;
//	free(p);
//	p = NULL;
//	return 0;
//}

//4
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	free(p);
//	// ....
//	free(p);
//	p = NULL;
//
//	return 0;
//}
i/*nt main()
{
	while (1)
	{
		malloc(1);
	}
	return 0;
}*/


//运行程序会造成程序的崩溃
//str以值传递的形式给p，p是Getmemory函数的形参，只能函数内部有效，等Getmemory函数返回以后，动态开辟内存尚未释放，并且无法找到，会造成内存泄漏
//void GetMemory(char *p)  // p是所创建的形参变量，在这个函数调用完成以后，这个这个形参就会自动的销毁，且无法在找到这个空间
//{ 
//	p = (char *)malloc(100);
//} 
//void Test(void) 
//{ 
//	char *str = NULL;   
//	GetMemory(str);  
//	strcpy(str, "hello world");   // 此时的str还是一个NULL
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}


////程序可以理解为：p是上司，他所开辟的空间是卧底，在p死掉之前，如果他能告诉别人卧底的身份，那就还会有人知道它是卧底
//char* GetMemory(char *p) 
//{ 
//	p = (char *)malloc(100);
//	return p;
//} 
//void Test(void) 
//{ 
//	char *str = NULL;   
//	str = GetMemory(str);  
//	strcpy(str, "hello world");   // 此时的str还是一个NULL
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//返回栈空间地址的问题
//char *GetMemory(void)
//{ 
//	char p[] = "hello world";   //这里p创建的是一个局部的数组，当除了这个函数内部以后，就会销毁掉，但是他依旧返回了这个创建了字符数组的
//	//地址，虽然此时str接受了这个p的地址，但是此时p里面是什么已经没有人知道了，所以结果是随机值
//	return p;
//} 
//void Test(void) 
//{ 
//	char *str = NULL;   
//	str = GetMemory(); 
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//int* test()
//{
//	static int a = 10; // 如果不加static 那么这里所创建的a在栈区的，除了这个函数，就会释放掉，然后你返回了a的地址，但是此时a里面的内容
//	//已经被销毁了，所以就会出现非法访问内存的问题。
//	//但是因为增加了static是这个变量从栈区变到了静态区，增加了这个局部变量的寿命，遍可以进行后续的修改，也不会报错
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}

////一定要有一定的意识：看见malloc 和calloc，realloc就要进行free释放，他们两个是一定一定要成对出现的，不然就会出现内存泄漏的问题
//void GetMemory(char **p, int num) 
//{ 
//	*p = (char *)malloc(num); 
//} 
//void Test(void) 
//{ 
//	char *str = NULL; 
//	GetMemory(&str, 100); 
//	strcpy(str, "hello"); 
//	printf(str);
//}
//int mian()
//{
//	Test();
//	return 0;
//}


//void Test(void) 
//{ 
//	char *str = (char *)malloc(100);   
//	strcpy(str, "hello");  
//	free(str);   
//	if (str != NULL)   
//	{ 
//		strcpy(str, "world");//此时这一块空间已经被释放了，你还要对他进行操作，造成了非法访问内存的问题。     
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}

//
//struct S
//{
//	int n;
//	int arr[];//结构体中最后一个是未知大小的--柔性数组成员--数组的大小是可以调整的
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));// 结果是4，因为在计算柔性数组的大小的时候，是不包含柔性数组成员的
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[];//结构体中最后一个是未知大小的--柔性数组成员--数组的大小是可以调整的
//};
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));// 结果是4，因为在计算柔性数组的大小的时候，是不包含柔性数组成员的
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//这里我进行开辟的时候是不知道这个柔型数组成员的大小的，所以我手动的给他设置一个大小，5*sizeof（int）这么大。
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i<5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct S* ptr = realloc(ps, 44);//此时我认为我原先开辟的柔性数组成员大小不够，我给他调整一下
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 0; i<10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//释放
//	free(ps);
//	ps = NULL;
//	return 0;
//}


struct S
{
	int n;
	int* arr;
};
int main()
{
	//这里一共使用了两次malloc所以也要进行两次的释放
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//调整大小
	int* ptr = realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 5; i < 10; i++)
	{
		printf("%s ", ps->arr[i]);
	}
	//释放内存
	free(ps->arr); // 因为这里的ps->arr是包含在ps里面的，如果先释放ps指针，那么就找不到ps->arr这个指针了
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}


