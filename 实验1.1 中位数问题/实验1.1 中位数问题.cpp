// 实验1.1 中位数问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include<iostream>
using namespace std;

int Partition(int r[], int first, int end);				//划分
void QuickSort(int r[], int first, int end);  //快速排序
double GetMid(int r[], int n);

//划分
int Partition(int r[], int first, int end)				//划分
{
	int i = first, j = end;									//初始化待划分区间
	while (i < j)
	{
		while (i < j && r[i] <= r[j]) j--;				//右侧扫描
		if (i < j) {
			int temp = r[i]; r[i] = r[j]; r[j] = temp;	//将较小记录交换到前面
			i++;
		}
		while (i < j && r[i] <= r[j]) i++;				//左侧扫描
		if (i < j) {
			int temp = r[i]; r[i] = r[j]; r[j] = temp;    //将较大记录交换到后面
			j--;
		}
	}
	return i;												// 返回轴值记录的位置
}

//快速排序
void QuickSort(int r[], int first, int end) {  //快速排序
	int pivot;
	if (first < end) {
		pivot = Partition(r, first, end);		//划分，pivot是轴值在序列中的位置
		QuickSort(r, first, pivot - 1);			//求解子问题1，对左侧子序列进行快速排序
		QuickSort(r, pivot + 1, end);			//求解子问题2，对右侧子序列进行快速排序
	}
}


double GetMid(int r[], int n)
{
	//如果元素个数为偶数个，则为中间两个数 平均数
	if (n % 2 == 0)
		return (r[n / 2] + r[n / 2 + 1]) / 2.0;
	//为奇数，则中间数
	else
		return (double)r[n / 2 + 1];
}


int main() {
	int r[100];
	int n;
	float result;
	cout << "请输入序列元素个数：" ;
	cin >> n;
	cout << "请输入序列：" ;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	QuickSort(r, 1, n);
	cout << "求得此序列的中位数为：" << GetMid(r, n) << endl;
	return 0;
}