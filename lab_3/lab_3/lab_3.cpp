#include <iostream>
#include <chrono>
#include <time.h> 

//void quicksort(int* mas, int first, int last) {     //функция сортировки
//	int mid, count;
//	int f = first, l = last;
//	mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
//	do
//	{
//		while (mas[f] < mid) f++;
//		while (mas[l] > mid) l--;
//		if (f <= l) 				//перестановка элементов
//		{
//			count = mas[f];
//			mas[f] = mas[l];
//			mas[l] = count;
//			f++;
//			l--;
//		}
//	} while (f < l);
//	if (first < l) quicksort(mas, first, l);
//	if (f < last) quicksort(mas, f, last);
//}
//
//
//void selectionSort(int* a, int n) {
//	int min;
//	for (int i = 0; i < n; i++) {
//		min = i;
//
//		for (int j = i + 1; j < n; j++)
//			min = (a[j] < a[min]) ? j : min;
//
//		if (i != min) {
//			int buf = a[i];
//			a[i] = a[min];
//			a[min] = buf;
//		}
//	}
//}
//
//void ShakerSort(int* a, int n) {
//	int left, right, i, temp;
//	left = 0;
//	right = n - 1;
//	while (left < right) {
//		for (i = right; i >= left; i--) {
//			if (a[i - 1] > a[i]) {
//				temp = a[i];
//				a[i] = a[i - 1];
//				a[i - 1] = temp;
//			}
//		}
//		left++;
//		for (i = left; i <= right; i++) {
//			if (a[i - 1] > a[i]) {
//				temp = a[i];
//				a[i] = a[i - 1];
//				a[i - 1] = temp;
//			}
//		}
//		right--;
//	}
//}
//

int main()
{
	setlocale(LC_ALL, "rus");
	int n, elem, nBuf;
	std::cout << "введите размер массива\n";
	std::cin >> n;
	if (n > 0) {
		nBuf = n;
		int* A = new int[n];
		int* B = new int[n];

		for (int i = 0; i < n; i++)
		{
			elem = --nBuf;
			A[i] = elem;
			B[i] = elem;

		}

		for (int i = 0; i < n; i++)
		{
			std::cout << A[i] << ' ';
		}
		std::cout << '\n';

		auto timeStartB = std::chrono::high_resolution_clock::now();//bubles
		int nSwapsB = 1;
		while (nSwapsB != 0)
		{
			nSwapsB = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (B[i] > B[i + 1])
				{
					int temp = B[i];
					B[i] = B[i + 1];
					B[i + 1] = temp;
					nSwapsB++;
				}
			}
		}

	}
}