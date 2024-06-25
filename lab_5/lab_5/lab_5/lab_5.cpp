#include <iostream>
#include <string>

int searchBrackets(char breacket, std::string input) {
	int length = input.length();
	int x = (length - 1) / 2, interX = 0, numOfSteps = 0, numOfBrackets = 0;
	int maxIterNum = round(log(length - 1) / log(2));
	if (x == 0)
	{
		if (input[x] = breacket) numOfBrackets++;
	}
	char if_true = '>';
	while (maxIterNum >= numOfSteps)
	{
		if (input[x] == breacket)
		{
			numOfBrackets++;
			int buff = x;
			if (input[x + 1] == breacket)
			{
				while (input[buff + 1] == breacket)
				{
					buff++;
					numOfBrackets++;
				}
				buff = x;
			}
			if (x != 0)
			{
				if (input[x - 1] == breacket)
				{
					while (buff != 0)
					{
						if (input[buff - 1] == breacket) numOfBrackets++;
						buff--;
					}
				}
			}
			break;
		}
		else if (input[x] > breacket) if_true = '<';
		else if (input[x] < breacket) if_true = '>';
		if (if_true == '>')
		{
			int add = round(abs((float)x - (float)interX) / 2);
			x += add;
			interX = x - add;
			if (x > length - 1)
			{
				x = length - 1;
			}
		}
		else if (if_true == '<')
		{
			int add = round(abs((float)x - (float)interX) / 2);
			x -= add;
			interX = x + add;
			if (x <= 0)
			{
				x = 0;
			}
		}
		numOfSteps++;
	}
	return numOfBrackets;
}

void quicksort(std::string& mas, int first, int last) {
	int f = first, l = last;
	char mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 				//перестановка элементов
		{
			std::swap(mas[f], mas[l]);
			f++;
			l--;
		}
	} while (f <= l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}

int main()
{
    setlocale(LC_ALL, "rus");
	std::string input;

	std::cout << "Введите строку: ";
	std::getline(std::cin, input);

	std::cout << "Вы ввели: " << input << std::endl;
	int length = input.length();
	if (length <= 0) std::cout << "пожалуйста введите строку\n";
	else
	{
		int numOfBracketsR = 0, numOfBracketsSq = 0, numOfBracketsBr = 0;
		quicksort(input, 0, length - 1);
		std::cout << "Отсортированная строка: " << input << std::endl;
		numOfBracketsR += searchBrackets('(', input);
		numOfBracketsR += searchBrackets(')', input);
		numOfBracketsSq += searchBrackets('[', input);
		numOfBracketsSq += searchBrackets(']', input);
		numOfBracketsBr += searchBrackets('{', input);
		numOfBracketsBr += searchBrackets('}', input);
		std::cout << "Количество круглых скобок: " << numOfBracketsR << std::endl;
		std::cout << "Количество квадратных скобок: " << numOfBracketsSq << std::endl;
		std::cout << "Количество фигурных скобок: " << numOfBracketsBr << std::endl;
	}
}