#include <iostream>
using namespace std;


// comb(3, 2)
int mydata[8] = { 1, 2, 3, 4 };
int select[10];
int n;
int r;

void print() {
	for (int i = 0; i < r; i++) {
		cout << select[i] << " ";
	}
	cout << endl;
}

void comb(int n, int r, int s, int depth) {
	if (depth == r) {
		print();
	}
	else {
		for (int i = s; i < n; i++) {
			select[depth] = mydata[i];
			comb(n, r, i + 1, depth + 1);
		}
	}
}

int main(void) {

	n = 4;
	r = 2;

	comb(n, r, 0, 0);

}