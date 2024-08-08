#include<iostream>
#include<vector>
#include<ctime>
using namespace std;


class data
{
public:
	int number;
	data *next;
};

class bipartite
{
private:
	int vertex;
	int edge;
	vector<int> ::iterator result;
	vector<int> Edge[100];
	vector<int> Store[100];
	vector<int> Store2[100];
	vector<int> Store3[100];
public:
	void Input();
	void Operation();
	void Show();
	void Seperate(int);
	void check(int);
};
data *AdjacencyList[100];
void bipartite::Input(void)
{

	int x,y;
	cin >> vertex >> edge;
	for (int i = 0; i < edge;i++)
	{
		cin>>x>>y;
		Edge[i].push_back(x);//Edge[i]代表第i邊
		Edge[i].push_back(y);
	}
	for (int j = 0; j < vertex; j++)
	{
		for (int i = 0; i < vertex; i++)
			Store[j].push_back(i);

		result= find(Store[j].begin(), Store[j].end(), j);
		Store[j].erase(result);
		Store[j].insert(Store[j].begin(), j);

	}
		
	return;
}
void bipartite::Operation(void)
{
	int count=0;
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
				if (j == edge-1)
					current->next = NULL;

			}
	}
	return;
}
void bipartite::Seperate(int j)
{
	data *current1;
	bool check=false;
	int i = 0,k=0,x=0,count=0;
	for (int i = 0; i < vertex; i++)
	{
		current1 = AdjacencyList[i]->next;//這裡有i
		if (check==false)
		{
			x = Store[j].front();
			k = x;//k為待移除項，x用於之後的檢查,x=adjacyclist的值
		}
		else if (Store[j].size() != 0&&check==true)
			k = Store[j].front();

		while (current1 != NULL&&i == k)//i要增加到edge檢查項
		{
			if (check == true && i == x)
				break;
			if (count == 0)
			{
				Store2[j].push_back(Store[j].front());
				Store[j].erase(Store[j].begin());

			}
			vector<int>::iterator result = find(Store[j].begin(), Store[j].end(), current1->number);
			if (result != Store[j].end())
			{
				Store3[j].push_back(current1->number);
				Store[j].erase(result);
			}
			current1 = current1->next;
			count++;
		} 
		count = 0;
		if (i == x&&check == false)
		{
			check = true;
			i = -1;
		}
	}
	j++;
	if (j!=vertex)
		Seperate(j);
		return;
}
void bipartite::check(int j)
{
	data *current1;
	vector<int>::iterator result;
	int k;
	for (int i = 0; i < Store2[j].size(); i++)
	{
		k = Store2[j].at(i);
		current1 = AdjacencyList[k]->next;
		while (current1 != NULL)
		{
			result = find(Store2[j].begin(), Store2[j].end(), current1->number);
			if (result != Store2[j].end())
			{
				i = Store2[j].size();
				Store2[j].clear();
				Store3[j].clear();
				break;
			}
			current1 = current1->next;
		}
	}
	if (Store3[j].size()!=0)
	for (int i = 0; i < Store3[j].size(); i++)
	{
		k = Store3[j].at(i);
		current1 = AdjacencyList[k]->next;
		while (current1 != NULL)
		{
			result = find(Store3[j].begin(), Store3[j].end(), current1->number);
			if (result != Store3[j].end())
			{
				i = Store3[j].size();
				Store2[j].clear();
				Store3[j].clear();
				break;
			}
			current1 = current1->next;
		}
	}
	j++;
	if (j != vertex)
		check(j);
	return;
}
void bipartite::Show(void)
{
	int count = 0;
	for (int j = 0; j < vertex; j++)
	{
		if (Store2[j].size() != 0)
		{
			cout << "true" << endl;
			for (int i = 0; i < Store2[j].size(); i++)
				cout << Store2[j].at(i) << " ";
			cout << endl;
			for (int i = 0; i < Store3[j].size(); i++)
				cout << Store3[j].at(i) << " ";
			cout << endl;
			count++;
			break;//只需輸出一組解
		}
	}
	if (count == 0)
		cout << "false" << endl;
	return;
}
int main()
{
	bipartite a;
	a.Input();
	a.Operation();
	a.Seperate(0);
	a.check(0);
	a.Show();
	return 0;
}