/*#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<iomanip>
using namespace std;
vector<string> a = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
vector<string> compare = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };

class board{
private:
	string number;
	board *next;
	
public:
	void RandomSet(void);
	void Show(void);
	void Pull(void);

};
board *head;
board *replace;
board *show=head;
board *current;
void board::RandomSet(void)
{
	srand(unsigned(time(NULL)));
	board take;
	
	head = new board;
	int count = 13, position=rand()%count;
	count--;
	head->number = a[position];//position=0-12
	a.erase(a.begin() + position);
	head->next = new board;
	current = head->next;
	for (int i = 1; i < 13; i++)
	{
		position = rand()% count;//position=0-11
		current->number = a[position];
		a.erase(a.begin() + position);
		if (i == 12)
			current->next = head;//將current的位置停留在最後一個
		else
		{
			current->next = new board;
			current = current->next;
		}
		count--;

	}
	return;
}

void board::Show(void)
{
	cout << a.size()<<" ";
	show = head;//此行放在迴圈之外
	for (int i = 0; i < 13;i++)
	{
		
		cout <<setw(2)<< show->number<<"  ";
		show = show->next;
	}
}

void board::Pull(void)
{
	while (compare.size()!=0)
	{
		show = head;
		while (1)
		{
			cout <<setw(2)<< show->number << " ";
			show = show->next;
			if (show == head)
				break;
		}
		cout << endl;
		if (head->number == compare[0])
		{
			replace = head;
			head = head->next;
			current->next = head;//將最後一個元素的next存head的位置
			show = head;
			delete replace;
			compare.erase(compare.begin());
		}
		else
		{
			current = current->next;//Very important!!!此步驟為將原本head元素設成最後一個，即將第一張牌抽至最後面
			head = head->next;//此步驟為將第二張牌抽至第一個位置
			current->next = head;
		}
	}
}

int main()
{
	board test;
	test.RandomSet();
	test.Pull();
	return 0;
}*/
#include <iostream>
using namespace std;
class G {
public: G() { cout << "G ctor" << endl; }
		~G() { cout << "G dtor" << endl; }
};
class A {
public: A() { cout << "A ctor" << endl; }
		~A() { cout << "A dtor" << endl; }
		G objG;
};
class B : public A {
public: B() { cout << "B ctor" << endl; }
		~B() { cout << "B dtor" << endl; }
		G objG;
};
class C : public A{
public: C() { cout << "C ctor" << endl; }
		~C() { cout << "C dtor" << endl; }
		G objG;
};
class D {
public: D() { cout << "D ctor" << endl; }
		~D() { cout << "D dtor" << endl; }
		G objG;
};
class E : public B {
public: E() { cout << "E ctor" << endl; }
		~E() { cout << "E dtor" << endl; }
		G objG;
};
class F : public C, public D {
public: F() { cout << "F ctor" << endl; }
		~F() { cout << "F dtor" << endl; }
		G objG;
};
int main()
{
	E objE;
	cout << endl;
	F objF;
	cout << endl;
	return 0;
}