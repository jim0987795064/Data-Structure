#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;

class data
{
public:
	int number;
	data *next;
	data *next2;
};

class Bridge
{
private:
	int vertex;
	int edge;
	vector<int> Edge[100];
	int dfn[15] ;
	int low[15] ;
	vector<bool> visited;
	int num=0;
	int count = 0;

public:
	void Input();
	void Operation();
	void Show();
	void dfnlow(int);
	void init();
	int compare1(int,int);
};
data *AdjacencyList[100];
int compare1(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
void Bridge::Input(void)
{

	int x, y;
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++)
	{
		cin >> x >> y;
		Edge[i].push_back(x);//Edge[i]代表第i邊
		Edge[i].push_back(y);
	}
	return;
}
void Bridge::init(void)
{
	for (int i = 0; i < vertex; i++)
	{
		visited.push_back(false);
		dfn[i] = -1;
		low[i] = -1;
	}

	//num = 0;
}
void Bridge::Operation(void)
{
	int count = 0;
	data *current;
	for (int i = 0; i < vertex; i++)
	{
		AdjacencyList[i] = new data;
		AdjacencyList[i]->number = i;
		AdjacencyList[i]->next = new data;
		current = AdjacencyList[i]->next;
		for (int j = 0; j < edge; j++)
		{
			count = 0;
			while (count < 2)
			{
				if (Edge[j].at(count) == i)
				{
					if (count == 0)
						current->number = Edge[j].at(count + 1);
					else
						current->number = Edge[j].at(count - 1);
					current->next = new data;
					current = current->next;
				}
				count++;
			}
			if (j == edge - 1)
				current->next = NULL;

		}
	}
	return;
}
void Bridge::Show()
{

	for (int i = 0; i < vertex; i++)
	{
		cout << dfn[i] << endl;
	}
	return;
}
void Bridge::dfnlow(int u)
{
	data *current;
	int w;
	cout << u << "   u " << endl;
	dfn[u] = count;
	cout << count<<"   count "<<endl;
	count += 1;
	current = AdjacencyList[u]->next;
	while (current != NULL)
	{
		w = current->number;
		if (dfn[w] < 0)
			dfnlow(w);
		current = current->next;
		cout << "0" << endl;
	}
	cout << "k"<< endl;
	return;
}
/*{
	data *current;
	int w;
	dfn[u] = low[u] = num++;
	for (current = AdjacencyList[u]->next; current; current = current->next)
	{
		w = current->number;
		if (dfn[w] < 0)
		{
			dfnlow(w, u);
			low[u] = compare1(low[u], low[w]);
		}
		else if (w != v)
			low[u] = compare1(low[u], dfn[w]);
	}
	return;
}*/
int main()
{
	Bridge a;
	a.Input();
	a.init();
	a.Operation();
	a.dfnlow(3);
	a.Show();
	system("pause");
	return 0;
}