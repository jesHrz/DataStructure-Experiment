#include <iostream>

/**
 * get all subsets of arr
 * @param flag 用二进制压位来表示第i个元素是否在子集中
 * @param k    arr的左端点
 * @param n    arr的右端点
 * @param arr  全集
 */
 template<typename T>
void subset(long long flag, int k, int n, const T* arr) {
	if (k == n) {
		for (int i = 0; i < n; ++i)
			// if in position i, the binary expression of flag is 1, then output arr[i]
			if (flag >> i & 1)	std::cout << arr[i] << ' ';
		std::cout << std::endl;
		return;
	}
	//there may be 1 or 0 on this position k
	subset(flag, k + 1, n, arr);
	subset(flag | (1ll << k), k + 1, n, arr);
}

//int main() {
//	int n;
//	std::cin >> n;
//	int* num = new int[n];
//	for (int i = 0; i < n; ++i)	std::cin >> num[i];
//	subset(0, 0, n, num);
//	delete[]num;
//	return 0;
//}
