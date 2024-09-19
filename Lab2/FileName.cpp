#include<iostream>
#include <time.h>
using namespace std;
int main()
{
	//Задание 1.2 2000
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения
	double cpu_time_used;
	int ROW = 2000;
	int COL = 2000; int elem_c;
	int i = 0, j = 0, r;
	int** a = new int* [ROW];
	int** b = new int* [ROW];
	int** c = new int* [ROW];
	for (int i = 0; i < ROW; ++i) {
		a[i] = new int[COL];
		b[i] = new int[COL];
		c[i] = new int[COL];
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i< 2000)
	{
		while (j< 2000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< 2000)
	{
		while (j< 2000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	

	start = clock();
	for (i = 0; i< 2000; i++)
	{
		for (j = 0; j < 2000; j++)
		{
			elem_c = 0;
			for (r = 0; r < 2000; r++)
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