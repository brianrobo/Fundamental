/*

 > abc�� �ִٸ�
   > ù��° a�� swap�� �� �ִ� ��츦 �� ����
   > a(bc)     b(ac)       c(ba)
   
   > ���� ù��°�� ������ ��󿡼� ���ܽ�Ű��,
     bc���� ù��°�� swap�� �� �ִ� �� ���
     > bc    cb

   > �ٽ� �������� ������� ������ �������ڸ�,
     ���� �迭����, �迭 ����(start pos)�� , ���̸� �ָ�
	 ���ۿ��� ���̳����� �ݺ��ϸ鼭 swap�� �Ѵ�. 

 > <�����ڷ�>

 http://stackoverflow.com/questions/9148543/program-to-print-permutations-of-given-elements
 https://www.youtube.com/watch?v=iFafKAUGqrY


*/

#include <iostream>


using namespace std;

int totalCnt = 0;

void Swap(char arr[], int i, int j)
{
	if (i == j)
		return;

	char temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void PrintArr(char arr[], int arrLen)
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

// step1 ������ Ȯ���ϱ� ���� �Լ�.
void Perm01(char arr[], int startIdx, int arrLen)
{
	int i;
	for (i = startIdx; i < arrLen; i++)
	{
		Swap(arr, startIdx, i);
		PrintArr(arr, arrLen);
		cout << endl;
		Swap(arr, startIdx, i);
	}
}

void Perm02(char arr[], int startIdx, int arrLen)
{
	if (startIdx == arrLen)
	{
		PrintArr(arr, arrLen);
		totalCnt++;
		return;
	}

	int i;
	for (i = startIdx; i < arrLen; i++)
	{
		Swap(arr, startIdx, i);
		//Perm02(arr, startIdx++, arrLen);		
		Perm02(arr, startIdx+1, arrLen);
		Swap(arr, startIdx, i);
	}
	//return; //<-- �� ������ϳ�?
}

void Test(int i)
{
	int temp = i;
}

int main(void)
{

	int a = 9;
	int b = 9;
	Test(a++);
	Test(b + 1);
	

	char strArr[4] = { 'A', 'B', 'C', 'D' };

	int startIdx = 0;
	int arrLen = 4;

	totalCnt = 0;

	//Perm01(strArr, startIdx, arrLen);
	Perm02(strArr, startIdx, arrLen);

	cout << "total count: " << totalCnt << endl;

	return 0;
}