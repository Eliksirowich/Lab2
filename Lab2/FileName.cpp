#include<iostream>
#include <time.h>
using namespace std;
int main()
{
	//������� 1.2 2000
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
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
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i< 2000)
	{
		while (j< 2000)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i< 2000)
	{
		while (j< 2000)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
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
	cout << "����� ����������:" << cpu_time_used << "������" << endl;

	return(0);
	//����� ���������� ��� ������� �������  100 0,003 ������
	//����� ���������� ��� ������� �������  200 0,023 ������
	//����� ���������� ��� ������� �������  400 0,275 ������
	//����� ���������� ��� ������� �������  1000 10,22 ������
	//����� ���������� ��� ������� �������  2000 87,918 ������
	
}