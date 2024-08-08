#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class data
{
public:
	int number, weight;
	data *next;
};

class SingleSource
{
private:
	int N, M, vertex1, vertex2, cost1,pos=1;
	vector<int> mid[101], cost[101], found, distance;
	data *adlist[101],*current;
public:
	void Input();
	void ShortestPath(int);
	int Choose();
	void Show(int);
	void operation2();
};
void SingleSource::Input()
{
	adlist[0]->number = 0;
	adlist[0]->weight = 0;
	adlist[0]->next = NULL;
	while (1)
	{

		cin >> N >> M;
		for (int i = 0; i <= N; i++)//initialize adjacencylist
		{
			adlist[i]->number = i;
			adlist[i]->weight = 0;
			adlist[i]->next = new data;
		}
		if (cin.eof() == 1)
			break;
		for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
		{
			if (i == j)
				cost[i].push_back(0);
			else
				cost[i].push_back(30000);
		}

		for (int i = 0; i < M; i++)
		{
			cin >> vertex1 >> vertex2 >> cost1;
			pos = vertex1;
			cost[vertex1].erase(cost[vertex1].begin() + vertex2);
			cost[vertex1].insert(cost[vertex1].begin() + vertex2, cost1);
			//	while
			if (pos == vertex1)
			{
				current = adlist[pos]->next;
				current->number = vertex2;
				current->weight = cost1;
			}
			else
			{
				pos = vertex1;
			}
		}
	}
	/*for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < cost[i].size(); j++)
			cout << cost[i].at(j)<<"  ";
		cout << endl;
	}*/
	return;
}

void SingleSource::ShortestPath(int v)
{

	int u, x;
	vector<int>::iterator it;
	for (int i = 0; i <=N; i++)
	{
		if (i == v)
		{
			distance.insert(distance.begin() + i, 0);
			found.insert(found.begin() + i, 1);
		}
		else
		{
			distance.insert(distance.begin() + i, cost[v].at(i));
			found.push_back(0);
		}
	}

	for (int i = 0; i <N - 2; i++)
	{
		/*for (int j = 0; j < distance.size(); j++)
		cout << distance.at(j) << " ";
		cout << endl;*/
		u = Choose();
		//cout << u << endl;
		/*if (u = -1)
		return;*/
		if (u != -1)
		{
			found.erase(found.begin() + u);
			found.insert(found.begin() + u, 1);
			/*for (int j = 0; j < find.size(); j++)
			cout << find.at(j) << " ";
			cout << endl;*/
			for (int w = 0; w <=N; w++)
			if (!found.at(w))
			if (distance.at(u) + cost[u].at(w) < distance.at(w))
			{
				x = distance.at(u) + cost[u].at(w);
				distance.erase(distance.begin() + w);
				distance.insert(distance.begin() + w, x);
				mid[w].clear();
				for (int k = 0; k < mid[u].size(); k++)
				{
					it = find(mid[w].begin(), mid[w].end(), mid[u].at(k));
					if (it == mid[w].end())
						mid[w].push_back(mid[u].at(k));

				}
				it = find(mid[w].begin(), mid[w].end(), u);
				if (it == mid[w].end())
					mid[w].push_back(u);
			}
		}
		/*for (int j = 0; j < distance.size(); j++)
		cout << distance.at(j) << " ";*/
	}
	return;
}
int SingleSource::Choose()
{
	int min = 30000, minpos = -1;
	for (int k = 0; k < N; k++)
	{
		if (distance.at(k) < min&&!found.at(k))
		{
			min = distance.at(k);
			minpos = k;
		}
		//cout <<endl<< distance.at(k)<<endl;
	}
	return minpos;
}

void SingleSource::operation2()
{

}

void SingleSource::Show(int v)
{
	/*for (int i = 0; i < N; i++)
	{
	for (int j = 0; j < cost[i].size(); j++)
	cout <<setw(5)<< cost[i].at(j) << "¡@";
	cout << endl;
	}*/
	/*for (int j = 0; j < distance.size(); j++)
	cout << distance.at(j) << " ";
	cout << endl;
	for (int j = 0; j < find.size(); j++)
	cout << find.at(j) << " ";*/

	for (int j = 0; j < distance.size(); j++)
	{
		if (distance.at(j) == 30000)
			cout << "Impossible" << endl;
		else if (distance.at(j) != 0)
		{
			cout << v << ",";
			for (int k = 0; k < mid[j].size(); k++)
				cout << mid[j].at(k) << ",";
			cout << j << " " << distance.at(j) << endl;
		}
	}
	return;
}
int main()
{
	SingleSource a;
	int b = 1;
	a.Input();
	a.ShortestPath(b);
	cout << endl;
	a.Show(b);
	system("pause");
	return 0;
}