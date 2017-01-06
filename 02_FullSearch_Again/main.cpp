#include <iostream>
using namespace std;

//char dataArr[10] = { 'a', 'b', 'c' };
char dataArr[] = { '1', '2', '3', '4', '5' };
int flag[10] = {0,};
char selected[10];



void PrintData(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << selected[i] << " ";
	}
	cout << endl;
}


/*
 * depth - from 0;
 * param n - data count
 */
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

void Perm2(int depth, int n, int r)
{
	if (depth == r)
	{
		PrintData(r);
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		if (flag[i] == 1) continue;
		flag[i] = 1;
		selected[depth] = dataArr[i];
		Perm2(depth + 1, n, r);
		flag[i] = 0;
	}

}

void Init(int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		flag[i] = 0;
	}
}

int main(void)
{

	
	int n = sizeof(dataArr) / sizeof(dataArr[0]);
	Init(n);
	//Full(0, n);
	//Perm(0, n);
	Perm2(0, n, 3);

	




	return 0;
}