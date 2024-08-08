#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>//使用string時，必須加入
#include<iomanip>
#include<cstring>
using namespace std;
void RandomSet(void);
void Operation(void);
int length = 13;
string *c;
void RandomSet(void)
{
	string b[13] = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
	string s;
	srand((unsigned)time(NULL));//要加上unsigned
	int x, y;
	for (int i = 0; i<50; i++) {
		x = rand() % 13;
		y = rand() % 13;
		while (x == y)
			y = rand() % 13;
		s = b[x];
		b[x] = b[y];
		b[y] = s;
	}//random reset
	c = new string[length];
	for (int i = 0; i<13; i++)
		c[i] = b[i];
	return;
}
void Operation(void)
{
	int t, position = 0;
	string back;
	string *f, e[12], d[13] = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
	while (1) {
		if (length == 0)
                        break;
		for (int j = 0; j<length; j++)
			cout <<setw(2)<<c[j] << " ";
		cout << endl;
		if (c[0] == d[position]) {//the order of drawning out arrayc
			position++;
			f = new string[length];//relocate memory to f
			for (int i = 0; i<length; i++)
				f[i] = c[i];
			length -= 1;
			delete[] c;
			c = new string[length];//relocate memory to c
			for (int i = 0; i<length; i++) {
				c[i] = f[i + 1];//the index of f cannot be same as position,because we need to reset the content of c by using the second of f
			}
			delete[] f;
		}
		else {
			back = c[0];
			for (int i = 0; i<(length - 1); i++)
				e[i] = c[i + 1];
			for(int i=0;i<(length-1);i++)
				c[i]=e[i];
			c[length - 1] = back;
		}
	}
}
int main() {
	RandomSet();
	Operation();
	delete [] c;
    return 0;
}
