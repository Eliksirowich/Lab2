//#include<iostream>
//#include <time.h>
// #include <stdio.h>
//using namespace std;
/*int main()
{
	//Задание 1.2 10000
	
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения
	double cpu_time_used;
	int ROW = 10000;
	int COL = 10000; int elem_c;
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
	while (i< 10000)
	{
		while (j< 10000)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i< 10000)
	{
		while (j< 10000)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	

	start = clock();
	for (i = 0; i< 10000; i++)
	{
		for (j = 0; j < 10000; j++)
		{
			elem_c = 0;
			for (r = 0; r < 10000; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения:" << cpu_time_used << "секунд" << endl;
	

	setlocale(LC_ALL, "Rus");










	return(0);
	//Время выполнения при размере матрицы  100 0,003 секунд
	//Время выполнения при размере матрицы  200 0,023 секунд
	//Время выполнения при размере матрицы  400 0,275 секунд
	//Время выполнения при размере матрицы  1000 10,22 секунд
	//Время выполнения при размере матрицы  2000 87,918 секунд

}*/
/*
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	// выбор компаранда 
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}



int main()
{
	setlocale(LC_ALL, "RUS");
	double cpu_time_used;
	clock_t start, end;
	srand(time(NULL));
	int count = 10;
	int* items = new int[count];

	for (int i = 0; i < count; i++)
	{
		items[i] = rand() % 100;
		cout << items[i] << endl;


	}
	cout << "///////" << endl;
	start = clock();
	shell(items, count);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	for (int i = 0; i < count; i++)
	{

		cout << items[i] << endl;


	}
	cout << cpu_time_used << "секунд" << endl;
	for (int i = 0; i < count; i++)
	{
		items[i] = 0;
	}
	cout << "&&&&&" << endl;
	for (int i = 0; i < count; i++)
	{

		items[i] = rand() % 100;
		cout << items[i] << endl;


	}
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "&&&&&" << endl;
	for (int i = 0; i < count; i++)
	{


		cout << items[i] << endl;


	}
	cout << cpu_time_used << "секунд" << endl;
	delete[]items;

	system("pause");
}
*/

///Задание 2




#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	// выбор компаранда
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b); 
}

int main() {
	//Задание 2.2
	/*srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	clock_t start, end;
	double cpu_time_used;

	int count = 10000;
	int* items = new int[count];


	for (int i = 0; i < count; i++) {
		items[i] =  i+1 ;
		cout << items[i] << endl;
	}


	start = clock();
	shell(items, count);
	end = clock();


	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения shell при возрастании:  " << cpu_time_used << " секунд" << endl;
	start = 0;
	end = 0;
	start = clock();
	qs(items, 0, count - 1);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения qs при возрастании: " << cpu_time_used << " секунд" << endl;

	delete[] items; */


	//Задание 2.3
	/*srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	clock_t start, end;
	double cpu_time_used;

	int count = 10000;
	int* items = new int[count];


	for (int i = 0; i < count; i++) {
		items[i] = count - i;
		cout << items[i] << endl;
	}



	start = clock();
	shell(items, count);
	end = clock();


	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения shell при убывании: " << cpu_time_used << " секунд" << endl;

	start = clock();
	qs(items, 0, count - 1);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения qs при убывании: " << cpu_time_used << " секунд" << endl;

	delete[] items;*/


	//Задание 2.4
	/*srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	clock_t start, end;
	double cpu_time_used;

	int count = 10000;
	int* items = new int[count];

	for (int i = 0; i < count / 2; i++) {
		items[i] = i + 1;
	}
	
	for (int i = count / 2; i < count; i++) {
		items[i] = count - i;
	}

	for (int i = 0; i < count; i++) {
		cout << items[i] << endl;
	}

		start = clock();
		shell(items, count);
		end = clock();


		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		cout << "Время выполнения shell при возростании до половины,а после при убывании: " << cpu_time_used << " секунд" << endl;

		start = clock();
		qs(items, 0, count - 1);

		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		cout << "Время выполнения qs при возростании до половины,а после при убывании: " << cpu_time_used << " секунд" << endl;

		delete[] items;*/


		//Задание 2.5(возрастание)
     /*srand(time(NULL));
     setlocale(LC_ALL, "RUS");

     clock_t start, end;
     double cpu_time_used;

     int count = 10000; 
     int* items = new int[count]; 


	 for (int i = 0; i < count; i++)
	 {
		 items[i] = rand() % 100;
		 cout << items[i] << endl;


	 }


     start = clock();
     qsort(items, count, sizeof(int), compare); 
     end = clock();
	 for (int i = 0; i < count; i++)
	 {
		 
		 cout << items[i] << endl;


	 }

     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
     cout << "Время работы qsort: " << cpu_time_used << " секунд" << endl;
 


	 system("pause");*/

	 //Задание 2.5(возрастание)
    /* srand(time(NULL));
     setlocale(LC_ALL, "RUS");

     clock_t start, end;
     double cpu_time_used;

     int count = 10000;
     int* items = new int[count];


     for (int i = 0; i < count; i++) {
	     items[i] = i + 1;
	     cout << items[i] << endl;
     }


	 start = clock();
	 qsort(items, count, sizeof(int), compare);
	 end = clock();
	 for (int i = 0; i < count; i++)
	 {

		 cout << items[i] << endl;


	 }

	 cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	 cout << "Время работы qsort при возрастании: " << cpu_time_used << " секунд" << endl;
	 */
	 //Задание 2.5(убывание)
     /* srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	clock_t start, end;
	double cpu_time_used;

	int count = 10000;
	int* items = new int[count];


	for (int i = 0; i < count; i++) {
		items[i] = count - i;
		cout << items[i] << endl;
	}



	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();


	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения qsort при убывании: " << cpu_time_used << " секунд" << endl;*/
    srand(time(NULL));
	setlocale(LC_ALL, "RUS");

	clock_t start, end;
	double cpu_time_used;

	int count = 10000;
	int* items = new int[count];

	for (int i = 0; i < count / 2; i++) {
		items[i] = i + 1;
	}
	
	for (int i = count / 2; i < count; i++) {
		items[i] = count - i;
	}

	for (int i = 0; i < count; i++) {
		cout << items[i] << endl;
	}

    start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();


	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Время выполнения qsort при возростании до половины,а после при убывании: " << cpu_time_used << " секунд" << endl;
}