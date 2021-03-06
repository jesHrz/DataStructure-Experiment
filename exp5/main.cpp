#include <iostream>
#include <fstream>
#include <ctime>
#include <matrix/sparseMatrix.h>
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	int value;
	clock_t start, end;
	start = clock();
	fin >> n >> m;
	sparseMatrix<int> a(n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			fin >> value;
			a.set(i, j, value);
		}
	}
	fin >> n >> m;
	sparseMatrix<int> b(n, m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			fin >> value;
			b.set(i, j, value);
		}
	}
	(a * b).print(fout);
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}