#include<iostream>
#include <time.h>
using namespace std;
int main(void)
{
	//������� 1.2 200
	setlocale(LC_ALL,"Rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������
	double cpu_time_used;
	int i = 0, j = 0, r;
	int a[200][200], b[200][200], c[200][200], elem_c;
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i< 200)
	{
		while (j< 200)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i< 200)
	{
		while (j< 200)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}

	start = clock();
	for (i = 0; i< 200; i++)
	{
		for (j = 0; j < 200; j++)
		{
			elem_c = 0;
			for (r = 0; r < 200; r++)
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

	
}