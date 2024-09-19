#include<iostream>
#include <time.h>
using namespace std;
int main()
{
	//������� 1.2 4000
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
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
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i< 4000)
	{
		while (j< 4000)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i< 4000)
	{
		while (j< 4000)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
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
	cout << "����� ����������:" << cpu_time_used << "������" << endl;

	return(0);
	//����� ���������� ��� ������� �������  100 0,003 ������
	//����� ���������� ��� ������� �������  200 0,023 ������
	//����� ���������� ��� ������� �������  400 0,275 ������
	//����� ���������� ��� ������� �������  1000 10,22 ������
	//����� ���������� ��� ������� �������  2000 87,918 ������

}