#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_NUM 1000 
void change(int* nums, char* s, int* plen)
{
	scanf("%s", s);
	int len = strlen(s);
	*plen = len;
	for (int i = 0; i < len; i++)nums[i] = s[len - 1 - i] - '0';
}
void add(int* nums1,int* nums2,int* p1,int* p2,int*sum,int*ps)
{
	memset(sum,0,sizeof(int)*2*MAX_NUM);

	int max_num = (*p1 > *p2) ? *p1 : *p2;
	for (int i = 0;i < max_num; i++)//nums1
	{
		sum[i] = nums1[i] + nums2[i];
	}
	
	int buffer = 0;
	int k = 0;
	while (k < *ps)
	{
		sum[k] += buffer;
		buffer = sum[k] / 10;
		sum[k] = sum[k] % 10;
		k++;
	}
	if (buffer != 0)
	{
		*ps+=1;
		sum[*ps] = buffer;
	}
}
void print(int* sum,int* lens)
{
	while (*lens > 1 && sum[*lens-1] == 0)
	{
		(*lens)--;
	}
	for (int i = 0; i < *lens; i++)
	{
		printf("%d", sum[(*lens) - 1 - i]);
	}
	printf("\n");
}
int main()
{
	
	char s1[MAX_NUM];
	char s2[MAX_NUM];
	int num_1[MAX_NUM] = { 0 };
	int num_2[MAX_NUM] = { 0 };
	int len1, len2;
	change(num_1,s1,&len1);
	change(num_2,s2,&len2);
	int sum[2 * MAX_NUM];
	int lens = len1 + len2;
	add(num_1,num_2,&len1,&len2,sum,&lens);
	print(sum,&lens);
	
	return 0;
}