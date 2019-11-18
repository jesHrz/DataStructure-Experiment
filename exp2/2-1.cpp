#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
class Sort {
public:
	Sort(const T*, int);
	Sort(const Sort<T>&);
	~Sort();

	void rankSort();
	void selectionSort();
	void bubbleSort();
	void insertSort();

	void output();
	void update(const T*, int);
protected:
	int n, cmp, mv;
	T* a;
};

template<typename T>
Sort<T>::Sort(const T* arr, int len) {
	n = len;
	a = new T[n];
	copy(arr, arr + n, a);
	cmp = mv = 0;
}

template<typename T>
Sort<T>::Sort(const Sort<T>& s) {
	n = s.n;
	a = new T[n];
	copy(s.a, s.a + n, a);
	cmp = mv = 0;
}

template<typename T>
Sort<T>::~Sort() { delete[]a; }

template<typename T>
void Sort<T>::rankSort() {
	T* rk = new T[n];
	T* tmp = new T[n];
	for (int i = 0; i < n; ++i)	rk[i] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] >= a[j])	rk[i]++;
			else rk[j]++;
			cmp++;
		}
	}

	for (int i = 0; i < n; ++i)	tmp[rk[i]] = a[i];
	for (int i = 0; i < n; ++i) {
		mv++;
		a[i] = tmp[i];
		output();
	}
	delete[]tmp;
	delete[]rk;
}

template<typename T>
void Sort<T>::selectionSort() {
	bool sorted = false;
	for (int i = n; i > 1 && !sorted; --i) {
		int maxIndex = 0;
		sorted = true;
		for (int j = 0; j < i; ++j) {
			if (a[maxIndex] < a[j]) {
				cmp++;
				maxIndex = j;
			} else {
				sorted = false;
			}
		}
		swap(a[i - 1], a[maxIndex]);
		mv++;
		output();
	}
}

template<typename T>
void Sort<T>::bubbleSort() {
	bool sorted = false;
	for (int i = n; i > 1 && !sorted; --i) {
		sorted = true;
		for (int j = 0; j < i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				cmp++;
				mv++;
				swap(a[j], a[j + 1]);
				sorted = false;
			}
			output();
		}
	}
}

template <typename T>
void Sort<T>::insertSort() {
	for (int i = 1; i < n; ++i) {
		T tmp = a[i];
		int j;
		for (j = i - 1; j >= 0 && tmp < a[j]; --j) {
			cmp++;
			a[j + 1] = a[j];
		}
		mv++;
		a[j + 1] = tmp;
		output();
	}
}

template<typename T>
void Sort<T>::output() {
	for (int i = 0; i < n; ++i)	cout << a[i] << ' ';
	cout << endl << "比较: " << cmp << ", 移动: " << mv << endl;
}

template<typename T>
void Sort<T>::update(const T* arr, int len) {
	delete[]a;
	n = len;
	a = new T[n];
	copy(arr, arr + n, a);
	cmp = mv = 0;
}

int main() {
	srand(time(0));
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)	a[i] = rand() % 1001;

	cout << "原始:" << endl;
	for (int i = 0; i < n; ++i)	cout << a[i] << ' ';
	cout << endl;

	cout << endl << "按名次排序:" << endl;
	Sort<int> s(a, n);
	s.rankSort();
	s.output();

	cout << endl << "及时终止的选择排序:" << endl;
	s.update(a, n);
	s.selectionSort();
	s.output();

	cout << endl << "及时终止的冒泡排序:" << endl;
	s.update(a, n);
	s.bubbleSort();
	s.output();

	cout << endl << "插入排序: " << endl;
	s.update(a, n);
	s.insertSort();
	s.output();

	return 0;
}
