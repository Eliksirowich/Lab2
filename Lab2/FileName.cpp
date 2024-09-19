#include<iostream>
#include <time.h>
using namespace std;
int main()
{
	//Задание 1.2 400
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения
	double cpu_time_used;
	int ROW = 400;
	int COL = 400; int elem_c;
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
	while (i< 400)
	{
		while (j< 400)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< 400)
	{
		while (j< 400)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	

	start = clock();
	for (i = 0; i< 400; i++)
	{
		for (j = 0; j < 400; j++)
		{
			elem_c = 0;
			for (r = 0; r < 400; r++)
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

	
}