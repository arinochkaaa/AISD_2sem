#undef HASHDEL
#include "Hash.h"
#include <chrono>
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int siz = 10, choice, k, choise_t;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> siz;
	Object H = create(siz, key);
	Object H1 = create(32, key);
	Object H2 = create(64, key);
	Object H3 = create(128, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1:
		{
			cout << "Выберите таблицу:\n 1-ваше значение\n 2-32 \n 3-64\n 4-128\n";
			cin >> choise_t;
			switch (choise_t)
			{
			case 0: exit(0);
			case 1: {
				cout << "хеш таблица на " << siz << '\n';
				H.scan(AAA_print);


			}break;
			case 2: {
				cout << "хеш-таблица на 32\n";
				H1.scan(AAA_print);
			}break;
			case 3: {
				cout << "хеш-nаблица на 64\n";
				H2.scan(AAA_print);
			}break;
			case 4: {cout << "хеш-таблица на 128\n";
				H3.scan(AAA_print);
			}break;

			} break;
		}
		case 2: {  AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;
			cin >> k;
			a->key = k;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			cout << "введите строку" << endl;
			cin >> str;
			a->mas = str;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			if (H.N == H.size)
				cout << "Таблица заполнена" << endl;
			else
				H.insert(a);
			if (H1.N != H1.size && H2.N != H2.size && H3.N != H3.size) {
				H1.insert(a);
				H2.insert(a);
				H3.insert(a);
			}
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));

			auto timeStart = std::chrono::high_resolution_clock::now();
			H.search(k);
			auto timeEnd = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> timeAll = timeEnd - timeStart;
			std::cout << "поиск элемента выполнен для 16 за " << timeAll.count() << " секунд.\n";

			timeStart = std::chrono::high_resolution_clock::now();
			H1.search(k);
			timeEnd = std::chrono::high_resolution_clock::now();
			timeAll = timeEnd - timeStart;
			std::cout << "поиск элемента выполнен для 32 за " << timeAll.count() << " секунд.\n";

			timeStart = std::chrono::high_resolution_clock::now();
			H2.search(k);
			timeEnd = std::chrono::high_resolution_clock::now();
			timeAll = timeEnd - timeStart;
			std::cout << "поиск элемента для 64 выполнен за " << timeAll.count() << " секунд.\n";

			timeStart = std::chrono::high_resolution_clock::now();
			H3.search(k);
			timeEnd = std::chrono::high_resolution_clock::now();
			timeAll = timeEnd - timeStart;
			std::cout << "поиск элемента для 128 выполнен за " << timeAll.count() << " секунд.\n";

			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
		}  break;
		}
		cin.ignore(cin.rdbuf()->in_avail());
		cin.sync();
		}
		return 0;
	}

