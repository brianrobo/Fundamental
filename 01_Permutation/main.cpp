/*

 > abc가 있다면
   > 첫번째 a와 swap할 수 있는 경우를 다 만듬
   > a(bc)     b(ac)       c(ba)
   
   > 이제 첫번째는 관심의 대상에서 제외시키고,
     bc에서 첫번째와 swap할 수 있는 걸 모두
     > bc    cb

   > 다시 문교수님 말씀대로 컨셉을 정리하자면,
     현재 배열에서, 배열 시작(start pos)과 , 길이를 주면
	 시작에서 길이끝까지 반복하면서 swap을 한다. 

 > <참고자료>

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

// step1 까지만 확인하기 위함 함수.
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
	//return; //<-- 꼭 해줘야하나?
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