#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>// malloc的头文件
#include <cstring>//字符串头文件
using namespace std;
#include <iostream>
#include <string>
#include<algorithm>
#include <stack>//栈头文件
#include <vector>//动态数组
#include <queue>//队列
#include <deque>//单调队列
#include <utility>//pair
//用0表示未染色.1.2.3.4四个数字代表四种颜色
bool judge(int j,int i,const vector<int>&color, const vector<vector<int>>& arr1, int n)//p接受color，q接受arr1
{
	bool ok = false;
	for (int k = 1;k <= n;k++)
	{
		if (arr1[i - 1][k - 1] == 1 && j == color[k - 1])
		{
			return false;
		}
	}
	return true;
}
int count(int j,int i, vector<int>& color, const vector<vector<int>>& arr1, int n,int sum)
{
	i += 1;
	if (i == n + 1)
	{
		return 1;
	}
	for (;j < 5;j++)
	{
		if (judge(j, i, color, arr1, n)&&i<n+1)
		{
			color[i - 1] = j;
			sum+=count(1, i, color, arr1, n,0);
			color[i - 1] = 0;
		}
		
	}
	return sum;
	

}
int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<vector<int>> arr1(n, vector<int>(n, 0));
	int i = 0;
	int j = 0;
	for (int a=0;a < m ;a++)
	{
		cin >> i >> j;
		arr1[i-1][j-1] = 1;
		arr1[j-1][i-1] = 1;
	}
	vector<int>color(n,0);
	//i表示第几个点，j表示染什么色
	int sum = 0;
	i = 0;
	j = 1;
	sum=count(j, i, color, arr1, n, sum);
	cout << sum << endl;

	return 0;

}