#include<iostream>
#include <time.h>
using namespace std;
int main(void)
{
	//������� 1.2 100
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
	double cpu_time_used;
	int i = 0, j = 0, r;
	int a[100][100], b[100][100], c[100][100], elem_c;
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i< 100)
	{
		while (j< 100)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i< 100)
	{
		while (j< 100)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}

	start = clock();
	for (i = 0; i< 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			elem_c = 0;
			for (r = 0; r < 100; r++)
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
	//����� ���������� 0,003 ������
}