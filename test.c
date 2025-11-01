#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_NUM 1000 
void change(int* nums, char* s, int* plen)
{
	char defend[20] = { 0 };
	snprintf(defend,sizeof(defend), "%%%ds", MAX_NUM - 1);
	scanf(defend, s);
	int len = strlen(s);
	*plen = len;
	for (int i = 0; i < len; i++)nums[i] = s[len - 1 - i] - '0';
}
void add(int* nums1,int* nums2,int* p1,int* p2,int*sum,int*ps)
{
	memset(sum,0,sizeof(int)*2*MAX_NUM);
    *ps = (*p1 > *p2) ? *p1 : *p2;
	int buffer = 0;
	for (int i = 0;i < *ps; i++)
	{
		int n1 = (i < *p1) ? nums1[i] : 0;
		int n2 = (i < *p2) ? nums2[i] : 0;
		sum[i] = n1+n2 + buffer;
		buffer = sum[i] / 10;
		sum[i] = sum[i] % 10;
	}
	if (buffer != 0)
	{
		sum[*ps] = buffer;
		(*ps)++;
	}
	if (*ps == 0)
	{
		*ps = 1;
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
	int sum[2*MAX_NUM];
	int lens = 0;
	add(num_1,num_2,&len1,&len2,sum,&lens);
	print(sum,&lens);
	return 0;
}