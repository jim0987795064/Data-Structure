#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
const int MAX = 20;
string a[MAX];
bool b[MAX];
int number;
void gen(int n){
	n++;
	if (n == number){
		cout << '{';
		for (int i = 0; i<number; i++)
		if (b[i])
			cout << a[i] << ' ';
		cout << '}' << endl;
	}
	else{
		b[n] = false;
		gen(n);
		b[n] = true;
		gen(n);
	}
}
int main()
{
	vector<string> input;
	string c;
	while (!cin.eof())
	{
		cin>>c;
		input.push_back(c);
	}
	number = input.size();
	for (int i = 0; i < number; i++)
	{
		a[i] = input[i];
	}
	gen(-1);
	return 0;
}