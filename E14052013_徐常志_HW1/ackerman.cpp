#include<iostream>
#include<cstdlib>
using namespace std;

int A(int, int);

int A(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return A(m - 1, 1);
	else if (m != 0 && n != 0)
		return A(m - 1, A(m, n - 1));
}

int main()
{
	int a, b;
	while (1)
	{
		cin >> a >> b;
		cout << endl << A(a, b) << endl;
	}
	system("pause");
	return 0;
}