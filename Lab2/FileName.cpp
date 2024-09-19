#include<iostream>
#include <time.h>
using namespace std;
int main()
{
	//Задание 1.2 4000
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения
	double cpu_time_used;
	int ROW = 4000;
	int COL = 4000; int elem_c;
	int i = 0, j = 0, r;
	unsigned long** a = new unsigned long* [ROW];
	unsigned long** b = new unsigned long* [ROW];
	unsigned long** c = new unsigned long* [ROW];
	for (int i = 0; i < ROW; ++i) {
		a[i] = new unsigned long[COL];
		b[i] = new unsigned long[COL];
		c[i] = new unsigned long[COL];
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i< 4000)
	{
		while (j< 4000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< 4000)
	{
		while (j< 4000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	

	start = clock();
	for (i = 0; i< 4000; i++)
	{
		for (j = 0; j < 4000; j++)
		{
			elem_c = 0;
			for (r = 0; r < 4000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения:" << cpu_time_used << "секунд" << endl;

	return(0);
	//Время выполнения при размере матрицы  100 0,003 секунд
	//Время выполнения при размере матрицы  200 0,023 секунд
	//Время выполнения при размере матрицы  400 0,275 секунд
	//Время выполнения при размере матрицы  1000 10,22 секунд
	//Время выполнения при размере матрицы  2000 87,918 секунд

}