#include <iostream>

/**
 * get the permutation of arr[k, n)
 */
template<typename T>
void permutations(int k, int n, T* arr) {
	if (k == n) {
		for (int i = 0; i < n; ++i)	std::cout << arr[i] << ' ';
		std::cout << std::endl;
		return;
	}
	for (int i = k; i < n; ++i) {
		std::swap(arr[i], arr[k]);
		permutations(k + 1, n, arr);
		std::swap(arr[i], arr[k]);
	}
}

int main() {
	int n;
	std::cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; ++i)	std::cin >> num[i];
	permutations(0, n, num);
	delete[]num;
	return 0;
}
