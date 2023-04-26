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

int sp[100];//˳��洢
int sup[100];//����������
int cunt = 0;//��¼������


void Merge(int sp[], int low, int mid, int high)//�鲢�ӱ���ǰ���������������鲢Ϊһ�������
{
	//�����������ӱ�ϲ�Ϊһ�������
	for (int k = low; k <= high; k++)
	{
		sup[k] = sp[k];//���츨������
	}

	int i = low;//iΪ������һ�������ָ��
	int j = mid + 1;//jΪ�����ڶ��������ָ��
	int m = i;//mΪ��ԭ���鸳ֵ��ָ��

	while (i <= mid && j <= high)//���������ָ���Ϊ������
	{
		if (sup[i] <= sup[j])//�ȽϽ��С�ĸ�ֵ��ԭ����
		{
			sp[m] = sup[i];
			i++;
			m++;
		}
		else//ǰ�ߴ�ʱ����������
		{
			sp[m] = sup[j];
			cunt += mid - i + 1;//��������
			j++;
			m++;
			
		}
	}

	while (i <= mid)//��jָ��������ѱ����꣬��ֱ�ӽ�iָ�������ʣ�ಿ��ֱ�Ӹ�ֵ��ԭ���� 
	{
		sp[m] = sup[i];
		i++;
		m++;
	}

	while (j <= high)//��iָ��������ѱ����꣬��ֱ�ӽ�jָ�������ʣ�ಿ��ֱ�Ӹ�ֵ��ԭ���� 
	{
		sp[m] = sup[j];
		j++;
		m++;
	}
}

void MergeSort(int sp[], int low, int high)//�ֽ��ӱ�
{
	if (low < high)//ǰ������
	{
		int mid = (low + high) / 2;//�е�
		MergeSort(sp, low, mid);//�����ֽ��ӱ�
		MergeSort(sp, mid + 1, high);//�����ֽ��ӱ�
		Merge(sp, low, mid, high);//�鲢
	}

}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sp[i];//�����������
	}

	cout << "����" << " ";
	for (int i = 0; i < n; i++)
	{
		cout << sp[i] << " ";//�����������
	}
	cout << endl;

	MergeSort(sp, 0, n - 1);//��·�鲢����

	cout << "�����" << " ";
	for (int i = 0; i < n; i++)
	{
		cout << sp[i] << " ";//���������
	}
	cout << endl;

	cout << "������Ϊ" << cunt;
	return 0;
}
