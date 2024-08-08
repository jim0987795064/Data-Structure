#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

class UinonFind
{
private:
	int T, N, p, q;
	vector<int> Store[4];
	vector<int> Searched;
public:

	void Input();
	void Instruction();
	void heightUnion(int ,int);
	int collaspsingFind(int);
	int Height(int);
	void Show();
};

void UinonFind::Input()
{
	cin >> T;
	for (int j = 0; j < 100; j++)
		Store[0].push_back(1000);
	for (int j = 0; j < T; j++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> p >> q;
			Store[0].erase(Store[0].begin() + p);
			Store[0].insert(Store[0].begin() + p, q);
		}
	}
	for (int i = 0; i <Store[0].size(); i++)
	if (Store[0].at(i) != 1000)
		Store[1].push_back(Store[0].at(i));
	for (int i = 0; i < Store[1].size(); i++)
		Searched.push_back(0);
	return;
}
void UinonFind::Instruction()
{
	int a, b;
	string x;
	while (1)
	{
		/*for (int k = 0; k < Store[1].size(); k++)
			cout << Store[1].at(k) << " ";
		cout << endl;*/
		cin >> x;
		if (x == "UNION")
		{
			cin >> a >> b;
			heightUnion(a, b);
		}
		else if (x == "FIND")
		{
			cin >> a;
			Store[3].push_back(collaspsingFind(a));
		}
		else if (x == "STOP")
			break;
	}
	return;
}
void UinonFind::heightUnion(int a,int b)
{
	int i,j,height;
	//height要重算
	i = Store[1].at(a), j = Store[1].at(b);//比較height
	if ((-i) < (-j))
	{
		Store[1].erase(Store[1].begin() + a);
		Store[1].insert(Store[1].begin() + a, b);
		height = -Height(b);
		Store[1].erase(Store[1].begin() + b);
		Store[1].insert(Store[1].begin() + b, height);

	}
	else
	{
		Store[1].erase(Store[1].begin() + b);
		Store[1].insert(Store[1].begin() + b, a);
		height = -Height(a);
		Store[1].erase(Store[1].begin() + a);
		Store[1].insert(Store[1].begin() + a, height);
	}

	return;
}
int UinonFind::Height(int x)
{

	int j,count;
	for (int i = 0; i < Store[1].size(); i++)
	{
		count = 1;
		j = i;
		while (Store[1].at(j) >= 0)
		{
			count++;
			j = Store[1].at(j);
		}
		Store[2].push_back(count);
	}
	while (Store[2].size()>1)
	if (Store[2].at(0) > Store[2].at(1))
		Store[2].erase(Store[2].begin() + 1);
	else
		Store[2].erase(Store[2].begin());
		return Store[2].front();
}
int UinonFind::collaspsingFind(int i)
{
	int c = Store[1].at(i);
	int root = i, trail = i, lead, count = 0;
	if (Searched.at(i) == 1||Store[1].at(c)<0)
		while (Store[1].at(root) >= 0)
		{
			root = Store[1].at(root);
			count++;
		}
	else
	{
		while (Store[1].at(root) >= 0)//transverse
		{
			root = Store[1].at(root);
			count++;
		}
		while (trail != root)//rootnode reset
		{
			lead = Store[1].at(trail);
			Store[1].at(trail) = root;
			Searched.erase(Searched.begin() + trail);
			Searched.insert(Searched.begin() + trail, 1);
			trail = lead;
			if (trail == root)
			count++;
		}	
	}
	/*for (int k = 0; k < Searched.size(); k++)
	cout << Searched.at(k) << " ";
	cout<< endl;*/

	return count;
}
void UinonFind::Show()
{
	for (int j = 0; j < Store[3].size(); j++)
		cout << Store[3].at(j) << endl;
	return;
}
int main()
{
	UinonFind a;
	a.Input();
	a.Instruction();
	a.Show();

	return 0;
}