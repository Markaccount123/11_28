#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ΪʲôҪ���ڶ�̬�ڴ�����أ�
//int val = 20; // ��ջ�ռ��Ͽ���4���ֽ�
//char arr[10] = { 0 }; //��ջ�ռ��Ͽ���10���ֽڵ������ռ�
//���������Ŀ��ٿռ�ķ�ʽ�������ص㣺
//1.�ռ俪�ٴ�С�ǹ̶���
//2.������ʲô��ʱ�򣬱���ָ������ĳ��ȣ�������Ҫ���ڴ��ڱ���ʱ���䡣
//���Ƕ��ڿռ�����󣬲��������������������ʱ��������Ҫ�Ŀռ��С�ڳ������е�ʱ���֪����������ı���ʱ���ٿռ�ķ�ʽ�Ͳ��������ˡ�
//������ʱ�����Ҫ���붯̬�ڴ濪���ˡ�

//#include<stdlib.h> //malloc��ͷ�ļ�
//void* malloc(size_t size); // ����
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	//���ڴ�����10�����εĿռ�
//	int* p = (int*)malloc(10 * sizeof(int)); //������ɹ���ʱ��ͻ᷵�����뵽����ʼ��ַ
//	if (p == NULL) // ��Ҳ��һ���Ŀ��ܻ�����ʧ�ܣ��ͻ᷵��һ����ָ��
//	{
//		//��ӡ�����ԭ��
//		printf("%s\n", strerror(errno));
//	}
//  ����̬����Ŀռ䲻��ʹ�õ�ʱ��
//��Ӧ�û�������ϵͳ��������free�������
//	return 0;
//}




//
//void* calloc(size_t num, size_t size); //���� 
//1.�����Ĺ�����Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0.
//2.��malloc������ֻ������calloc���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊ0.



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
//1.realloc�����ĳ����ö�̬�ڴ������ӵ����
//2.�������Ƿ��ֹ�ȥ����Ŀռ�̫С�ˣ���ʱ�������ֻ��������Ŀռ�����ˣ���Ϊ�˺����ڴ棬����һ������ڴ�Ĵ�С�����ĵ�����
//void* realloc(void* ptr, size_t size);
//���У�
//1.ptr��Ҫ�������ڴ��ַ
//2.size����֮���µĴ�С
//3.����ֵΪ����֮����ڴ���ʼλ��
//4.�����������ԭ�ڴ�ռ�Ĵ�С�����ϣ����Ὣԭ���ڴ��е������ƶ����µĿռ�

//�ڿ��ٵ�ʱ���realloc���صĵ�ַ��һ���µ�ָ��������
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


//���г������ɳ���ı���
//str��ֵ���ݵ���ʽ��p��p��Getmemory�������βΣ�ֻ�ܺ����ڲ���Ч����Getmemory���������Ժ󣬶�̬�����ڴ���δ�ͷţ������޷��ҵ���������ڴ�й©
//void GetMemory(char *p)  // p�����������βα����������������������Ժ��������βξͻ��Զ������٣����޷����ҵ�����ռ�
//{ 
//	p = (char *)malloc(100);
//} 
//void Test(void) 
//{ 
//	char *str = NULL;   
//	GetMemory(str);  
//	strcpy(str, "hello world");   // ��ʱ��str����һ��NULL
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}


////����������Ϊ��p����˾���������ٵĿռ����Եף���p����֮ǰ��������ܸ��߱����Ե׵���ݣ��Ǿͻ�������֪�������Ե�
//char* GetMemory(char *p) 
//{ 
//	p = (char *)malloc(100);
//	return p;
//} 
//void Test(void) 
//{ 
//	char *str = NULL;   
//	str = GetMemory(str);  
//	strcpy(str, "hello world");   // ��ʱ��str����һ��NULL
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//����ջ�ռ��ַ������
//char *GetMemory(void)
//{ 
//	char p[] = "hello world";   //����p��������һ���ֲ������飬��������������ڲ��Ժ󣬾ͻ����ٵ������������ɷ���������������ַ������
//	//��ַ����Ȼ��ʱstr���������p�ĵ�ַ�����Ǵ�ʱp������ʲô�Ѿ�û����֪���ˣ����Խ�������ֵ
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
//	static int a = 10; // �������static ��ô������������a��ջ���ģ���������������ͻ��ͷŵ���Ȼ���㷵����a�ĵ�ַ�����Ǵ�ʱa���������
//	//�Ѿ��������ˣ����Ծͻ���ַǷ������ڴ�����⡣
//	//������Ϊ������static�����������ջ���䵽�˾�̬��������������ֲ�����������������Խ��к������޸ģ�Ҳ���ᱨ��
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}

////һ��Ҫ��һ������ʶ������malloc ��calloc��realloc��Ҫ����free�ͷţ�����������һ��һ��Ҫ�ɶԳ��ֵģ���Ȼ�ͻ�����ڴ�й©������
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
//		strcpy(str, "world");//��ʱ��һ��ռ��Ѿ����ͷ��ˣ��㻹Ҫ�������в���������˷Ƿ������ڴ�����⡣     
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
//	int arr[];//�ṹ�������һ����δ֪��С��--���������Ա--����Ĵ�С�ǿ��Ե�����
//};
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));// �����4����Ϊ�ڼ�����������Ĵ�С��ʱ���ǲ��������������Ա��
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[];//�ṹ�������һ����δ֪��С��--���������Ա--����Ĵ�С�ǿ��Ե�����
//};
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));// �����4����Ϊ�ڼ�����������Ĵ�С��ʱ���ǲ��������������Ա��
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	//�����ҽ��п��ٵ�ʱ���ǲ�֪��������������Ա�Ĵ�С�ģ��������ֶ��ĸ�������һ����С��5*sizeof��int����ô��
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i<5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct S* ptr = realloc(ps, 44);//��ʱ����Ϊ��ԭ�ȿ��ٵ����������Ա��С�������Ҹ�������һ��
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//	for (i = 0; i<10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//�ͷ�
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
	//����һ��ʹ��������malloc����ҲҪ�������ε��ͷ�
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
	//������С
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
	//�ͷ��ڴ�
	free(ps->arr); // ��Ϊ�����ps->arr�ǰ�����ps����ģ�������ͷ�psָ�룬��ô���Ҳ���ps->arr���ָ����
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}


