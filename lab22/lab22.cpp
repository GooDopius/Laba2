#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void vnutrich(int** a, int n, int& i, int& j);
void okrug1(int** a, int n, int& i, int& j);


int main()
{
	int n, m;
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	}
	if (n == m)
	{
		if (n % 2 == 0)
		{
			a[(n / 2) - 1][(n / 2) - 1] = 1;
			a[(n / 2) - 1][n / 2] = 2;
			a[n / 2][(n / 2) - 1] = 4;
			a[n / 2][n / 2] = 3;
			if (n != 2)
			{
				a[n / 2][(n / 2) - 2] = 5;
				int i = n / 2, j = (n / 2) - 2;
				while (a[n - 2][0] == 0)
				{
					vnutrich(a, n, i, j);
				}
				okrug1(a, n, i, j);
			}
		}
		else if (n % 2 != 0)
		{
			if (n == 3)
			{
				a[0][0] = 7, a[0][1] = 8, a[0][2] = 9;
				a[1][0] = 6, a[1][1] = 1, a[1][2] = 2;
				a[2][0] = 5, a[2][1] = 4, a[2][2] = 3;
			}
			else
			{
				a[n / 2][n / 2] = 1;
				a[n / 2][(n / 2) + 1] = a[n / 2][n / 2] + 1;
				int i = n / 2, j = (n / 2) + 1;
				while (a[1][n - 1] == 0)
				{
					vnutrich(a, n, i, j);
				}
				a[n - 2][0] = a[n - 1][0] + 1;
				i = n - 1, j = 0;
				for (; i > 0; i--)
				{
					a[i - 1][j] = a[i][j] + 1;
				}
				for (; j < n - 1; j++)
				{
					a[i][j + 1] = a[i][j] + 1;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	return 0;
}

void vnutrich(int** a, int n, int& i, int& j)
{
	if (j < n - 1 && i > 1 && a[i - 1][j] == 0 && a[i][j + 1] != 0)
	{
		while (j < n - 1 && i > 1 && a[i - 1][j] == 0 && a[i][j + 1] != 0)
		{
			a[i - 1][j] = a[i][j] + 1;
			i -= 1;
		}
	}
	if (j < n - 1 && a[i][j + 1] == 0 && a[i + 1][j] != 0)
	{
		while (j < n - 1 && a[i][j + 1] == 0 && a[i + 1][j] != 0)
		{
			a[i][j + 1] = a[i][j] + 1;
			j += 1;
		}
	}
	if (i < n - 1 && a[i + 1][j] == 0 && a[i][j - 1] != 0)
	{
		while (i < n - 1 && a[i + 1][j] == 0 && a[i][j - 1] != 0)
		{
			a[i + 1][j] = a[i][j] + 1;
			i += 1;
		}
	}
	if (j > 1 && a[i][j - 1] == 0 && a[i - 1][j] != 0)
	{
		while (j > 1 && a[i][j - 1] == 0 && a[i - 1][j] != 0)
		{
			a[i][j - 1] = a[i][j] + 1;
			j -= 1;
		}
		if (j == 1)
		{
			a[i][j - 1] = a[i][j] + 1;
		}
	}
}

void okrug1(int** a, int n, int& i, int& j)
{
	i -= 1, j -= 1;
	a[i][j] = a[i + 1][j] + 1;
	for (; i > 0; i--)
	{
		a[i - 1][j] = a[i][j] + 1;
	}
	for (; j < n - 1; j++)
	{
		a[i][j + 1] = a[i][j] + 1;
	}
	for (; i < n - 1; i++)
	{
		a[i + 1][j] = a[i][j] + 1;
	}
	for (; j > 0; j--)
	{
		a[i][j - 1] = a[i][j] + 1;
	}
}

