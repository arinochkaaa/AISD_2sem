#include <iostream>

void selectionSort(int* a, int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;

		for (int j = i + 1; j < n; j++)
			min = (a[j] < a[min]) ? j : min;

		if (i != min) {
			int buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, elem, nBuf;
	std::cout << "введите размер массива\n";
	std::cin >> n;
	if (n > 0 && n < 1000) {
		nBuf = n;
		int* A = new int[n];
		int* B = new int[n];
		for (int i = 0; i < n; i++)
		{
			elem = --nBuf;
			A[i] = elem;
		}
		/*for (int i = 0; i < n; i++)
		{
			std::cout <<A[i] << ' ';
		}
		std::cout << '\n';*/
		/*for (int i = 0; i < n; i++)
		{
			std::cout << "введите " << i + 1 << " элемент массива\n";
			std::cin >> elem;
			A[i] = elem;
		}*/

		selectionSort(A, n);
		/*for (int i = 0; i < n; i++)
		{
			std::cout << A[i] << ' ';
		}
		std::cout << '\n';*/

		int sum = 0;
		for (int i = 0, k = n - 1, z = 0; i < k; i++)
		{
			B[z] = A[k];
			B[z + 1] = A[i];
			sum += B[z];
			z += 2;
			k--;
		}
		for (int i = 0; i < n; i++)
		{
			std::cout << B[i] << ' ';
		}
		std::cout << '\n';
		std::cout << "итоговая сумма чека равна: " << sum;
	}
	else std::cout << "неправильно введен размер массива ";
}