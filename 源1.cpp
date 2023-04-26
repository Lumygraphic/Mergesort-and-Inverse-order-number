#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include <iomanip>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int sp[100];//顺序存储
int sup[100];//辅助用数组
int cunt = 0;//记录逆序数


void Merge(int sp[], int low, int mid, int high)//归并子表，将前后相邻两个有序表归并为一个有序表
{
	//将两段有序子表合并为一个有序表
	for (int k = low; k <= high; k++)
	{
		sup[k] = sp[k];//构造辅助数组
	}

	int i = low;//i为遍历第一个数组的指针
	int j = mid + 1;//j为遍历第二个数组的指针
	int m = i;//m为给原数组赋值用指针

	while (i <= mid && j <= high)//两个数组的指针均为遍历完
	{
		if (sup[i] <= sup[j])//比较结果小的赋值给原数组
		{
			sp[m] = sup[i];
			i++;
			m++;
		}
		else//前者大时产生逆序数
		{
			sp[m] = sup[j];
			cunt += mid - i + 1;//求逆序数
			j++;
			m++;
			
		}
	}

	while (i <= mid)//若j指向的数组已遍历完，则直接将i指向数组的剩余部分直接赋值给原数组 
	{
		sp[m] = sup[i];
		i++;
		m++;
	}

	while (j <= high)//若i指向的数组已遍历完，则直接将j指向数组的剩余部分直接赋值给原数组 
	{
		sp[m] = sup[j];
		j++;
		m++;
	}
}

void MergeSort(int sp[], int low, int high)//分解子表
{
	if (low < high)//前提条件
	{
		int mid = (low + high) / 2;//中点
		MergeSort(sp, low, mid);//继续分解子表
		MergeSort(sp, mid + 1, high);//继续分解子表
		Merge(sp, low, mid, high);//归并
	}

}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sp[i];//输入测试样例
	}

	cout << "序列" << " ";
	for (int i = 0; i < n; i++)
	{
		cout << sp[i] << " ";//输出测试样例
	}
	cout << endl;

	MergeSort(sp, 0, n - 1);//二路归并排序

	cout << "排序后" << " ";
	for (int i = 0; i < n; i++)
	{
		cout << sp[i] << " ";//输出排序结果
	}
	cout << endl;

	cout << "逆序数为" << cunt;
	return 0;
}
