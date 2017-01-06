#include <iostream>
using namespace std;



char dataArr[] = { 'a', 'b', 'c' };
char selected[10];
int flag[] = { 0, };

void Init()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		flag[i] = 0;
	}
}


void PrintData(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << selected[i] << " ";
	}
	cout << endl;
}

void Full(int depth, int n)
{
	if (depth == n)
	{
		PrintData(n);
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		selected[depth] = dataArr[i];
		Full(depth + 1, n);
	}
}

void Perm(int depth, int n)
{
	if (depth == n)
	{
		PrintData(n);
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		if (flag[i] == 1) continue;
		flag[i] = 1;
		selected[depth] = dataArr[i];
		Perm(depth + 1, n);
		flag[i] = 0;
	}
}

// today problem

void Comb(int depth, int n, int start)
{
	if (depth == n)
	{
		PrintData(n);
		return;
	}

	int i;
	for (i = start; i <= n; i++)
	{
		selected[depth] = dataArr[i];
		Comb(depth + 1, n, i);
	}
}

int main(void)
{
	Init();

	int n = sizeof(dataArr) / sizeof(dataArr[0]);
	//Full(0, n);
	//Perm(0, n);
	Comb(0, n, 0);


	return 1;
}