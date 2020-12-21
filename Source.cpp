#include <stdio.h>
#include<malloc.h>
using namespace std;
#include<iostream>


int main() {
	int n, m;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	int* dim1 = (int*)malloc(n * m * sizeof(int));
	int** dim2 = (int**)malloc(n * sizeof(int*));
	
	for (int i = 0; i < n; i++) {
		dim2[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			dim2[i][j] = rand() % 21 - 3;
			printf("%4d", dim2[i][j]);
		}
		printf("\n");
	}
	cout << "merge that" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dim1[i * m + j] = dim2[i][j];
			cout<<dim1[i * m + j]<<" ";
		}
	}
	cout << "in 2 dimensions" << endl;
	for (int t = 0; t < m * n - 1; ++t) {
		dim2[t % n][t % m] = dim1[t];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << dim2[i][j] << " ";
		}
		cout << endl;
	}
}