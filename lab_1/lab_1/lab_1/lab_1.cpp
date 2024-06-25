// lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h> 
#include <chrono>
#include <thread>
using namespace std;

clock_t time_all = 0;
clock_t start_r = 0;
clock_t end_r = 0;

unsigned long long  RecFib(unsigned long long arg_a = 0, unsigned long long  arg_b = 1, unsigned long long  arg_n = 1)
{
    start_r = clock();
    arg_n -= 1;
    if (arg_n == 0) {
        return arg_a + arg_b;
        end_r = clock();
        time_all += end_r - start_r;
    }
    else {
        unsigned long long  c = arg_a + arg_b;
        //this_thread::sleep_for(chrono::seconds(1));
        end_r = clock();
        time_all += end_r - start_r;
        return RecFib(arg_b, c, arg_n);
    }
}

void time(clock_t time) {
    //int time_arr[2];
    double seconds; int minutes = 0;
    seconds = (double)(time) / CLOCKS_PER_SEC;
    if (seconds > 60) {
        for (; seconds > 60;) {
            minutes++;
            seconds -= 60;
        }
    }

    cout << "Расчетное время циклом " << minutes << " минут " << seconds << " секунд." << "\n";
}

int main()
{
    setlocale(LC_ALL, "RU");
    unsigned long long n, a = 0, b = 1, result;
    cout << "введите порядковый номер числа Фибоначчи:";
    cin >> n;
    if (n == 1 || n == 0)
    {
        cout << "Через цикл. Результат вашего числа: " << 0 << "\n";
    }
    else
    {
        clock_t start_c = clock();
        for (int i = 2; i <= n; i++)
        {
            result = a + b;
            a = b;
            b = result;
        }
        clock_t end_c = clock();
        time_all = end_c - start_c;
        time(time_all);

        cout << "Через цикл. Результат вашего числа: " << result << "\n";
        time_all = 0;
        result = RecFib(0, 1, n - 1);
        time(time_all);

        cout << "Через рекурсию. Результат вашего числа: " << result;
    }

}
