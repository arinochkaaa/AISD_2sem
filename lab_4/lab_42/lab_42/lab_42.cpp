#include <iostream>
#include <random>

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

int main() {
	setlocale(LC_ALL, "rus");
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 100);
	int n, elem, num = 0;
	std::cout << "введите размер массива\n";
	std::cin >> n;
	if (n > 0 && n < 1000) {
		int* A = new int[n];
		for (int i = 0; i < n; i++) {
			elem = dis(gen);
			A[i] = elem;
		}
		/*for (int i = 0; i < n; i++) {
			std::cout << A[i] << ' ';
		}
		std::cout << '\n';*/

		selectionSort(A, n);
		for (int i = 0; i < n; i++) {
			std::cout << A[i] << ' ';
		}
		std::cout << '\n';

		int buf = A[n - 1];
		for (int i = n - 1, countDiplom = 0; i >= 0; i--) {
			if (A[i] != buf && A[i + 1] == buf && A[i - 1] != buf) {
				buf = A[i];
				countDiplom++;
				if (countDiplom == 3) break;
			}
			if (A[i] == buf) num++;
		}
		std::cout << "количество олимпиадников: " << num;
	}
	else std::cout << "не правильно введен размер массива ";
}