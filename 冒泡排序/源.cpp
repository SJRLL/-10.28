#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void BubbleSort1(int *arr, int sz)
{
	int i = 0;
	int j = 0;
	assert(arr);
	for (i = 0; i<sz - 1; i++)
	{
		for (j = 0; j<sz - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void TestBubbleSort(void(*BubbleSort)(int *arr, int sz))
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (i = 0; i<sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	TestBubbleSort(BubbleSort1);
	system("pause");
	return 0;
}


