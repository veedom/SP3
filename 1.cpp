#include <iostream>


using namespace std;


void enter ( int **arr, int n, int z)
	{
		for (int j=0; j<n; j++)
		{
			for (int i=0; i<n; i++)
			{
				z+=1;
				arr[i][j] = z;
			}
		}
	}

void print ( int **arr, int n)
	{
		cout << "Полученный массив: \n";
		int i = 0;
		while (i<n)
		{
			for (int j=0; j<n; j++)
			{
				cout.width(4);
				cout << arr[i][j];
			}
			cout << endl;
			asm(
				"movl %[i], %%ebx		\n\t"
				"incl %%ebx			\n\t"
				"movl %%ebx, %[i]		\n\t"

				"end_asm:			\n\t"
				:[i]"=m"(i)
				:
				:"%ebx");
		}
	}

void clean ( int **arr, int n)
	{
		for (int i = 0; i<n; i++)
			{
				delete[] arr[i];
			}

		delete[] arr;
	}


int main ()
	{
		int n;
		int z = 0;
		cout << "Введите размер матрицы: \n";
		cin >> n;
		int **arr = new int* [n];
		for (int i = 0; i<n; i++)
		{
			arr[i] = new int [n];
		}
		enter(arr, n, z);
		print(arr, n);
		clean(arr, n);
	}

