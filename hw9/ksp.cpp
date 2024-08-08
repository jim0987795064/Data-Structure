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

class ksp
{
private:
	int N, M,o, vertex1, vertex2, cost1, pos = 1,max,num=0,w=-1,e;
	data *adlist[101], *current;
	vector<int> dis, mid, store[100], store2[100], length,sum1,can,sum2,h,u,sho[50];
	data *add[100];
public:
	void Input();
	void show();
	void operation(int x);
};
void ksp::Input()
{

		cin >> N >> M;
		for (int i = 0; i <= N; i++)//initialize adjacencylist
		{
			adlist[i] = new data;
			adlist[i]->number = i;
			adlist[i]->weight = 0;
			if (i==0||i==N)
			adlist[i]->next = NULL;
			//adlist[i]->next = new data;
		}
		current = adlist[1];
		for (int i = 0; i < M; i++)
		{
			cin >> vertex1 >> vertex2 >> cost1;
			if (pos == vertex1)
			{
				current->next = new data;
				current=current->next;
				current->number = vertex2;
				current->weight = cost1;
			}
			else
			{
				current->next = NULL;
				pos = vertex1;
				current = adlist[pos];
				current->next = new data;
				current = current->next;
				current->number = vertex2;
				current->weight = cost1;
			}
			if (i == M - 1)
				current->next = NULL;
		}
		for (int k = 0; k < 100;k++)
		store[k].push_back(1);
		cin >> o;
	return;
}

void ksp::operation(int x)
{
	current = adlist[x]->next;

	while (current!=NULL)
	{
		w++;
		add[w]=current;
		length.push_back(current->weight);
		mid.push_back(current->number);
		//cout << " " << current->weight << " "<<current->number<<endl;
		operation(current->number);
		mid.pop_back();
		length.pop_back();
		//length = 0;
		current =add[w]->next;
		add[w] = NULL;
		w--;
	}
	if (x == 6)
	{
		//mid.push_back(6);
		/*for (int l = 0; l < mid.size(); l++)
			cout << mid.at(l);
		cout << endl;
		for (int l = 0; l < length.size(); l++)
			cout << length.at(l);
		cout << endl;*/
		//dis.push_back(length);
		for (int y = 0; y < mid.size(); y++)
			store[num].push_back(mid.at(y));
		for (int y = 0; y < length.size(); y++)
			store2[num].push_back(length.at(y));
		num++;
		/*mid.pop_back();
		length.pop_back();*/
		//mid.pop_back();
	}
	return;
}
void ksp::show()
{
	int sum = 0,b,c;
	for (int j = 0; j < 100; j++)
	if (store2[j].size()!=0)
	{
		sum = 0;
		for (int a = 0; a < store2[j].size(); a++)
			sum += store2[j].at(a);
		sum1.push_back(sum);
	}

	for (int j = 0; j < 100; j++)
	if (store[j].size() != 0)
	{
		sum = 1;
		for (int a = 0; a < store2[j].size(); a++)
		{
			if (store2[j].at(a) != 0)
				sum += 1;
		}
		sum2.push_back(sum);
	}
	for (int i = 0; i < sum1.size(); i++)
		u.push_back(sum1.at(i));
	for (int i = 0; i < o; i++)
	{
		sum = sum1.at(0);
		b = 0;
		for (int j = 0; j < sum1.size(); j++)
		{
			if (sum1.at(j) < sum)
			{
				sum = sum1.at(j);
				b = j;
			}
		}
		sum1.erase(sum1.begin()+b);
		can.push_back(sum);
	}
	for (int g = 0; g < can.size(); g++)
	{
		for (int i = 0; i < u.size(); i++)
		{
			if (u.at(i) == can.at(g))
				h.push_back(i);
		}
	}
	/*for (int g = 0; g < h.size(); g++)
		cout << h.at(g);*/
	int count = 0,min=150,v=0;
	for (int g = 0; g < h.size(); g++)
	{
		count = 0,min=150;
		for (int j = 0; j < 100; j++)
		if (j == h.at(g))
		{
			if (store[j].size() < min)
			{
				min = store[j].size();
				count++;
			}
			if (count == 1)
			{
				for (int i = 0; i < store[j].size(); i++)
					sho[v].push_back(store[j].at(i));
				v++;
			}
			else if(count != 1)
			{
				for (int i = 0; i < store[j].size(); i++)
					sho[v].push_back(store[j].at(i));
			}
		}
	}



	for (int g = 0; g < h.size(); g++)
	for (int j = 0; j < 100; j++)
	if (j == h.at(g))
	{for (int i = 0; i < store[j].size(); i++)
		cout<<store[j].at(i);
	cout << endl;
	}



	int count = 0,t=0;
	for (int g = 0; g < h.size(); g++)
	{
		h.at(t);
		count++;
	}



	/*for (int i = 1; i <= N; i++)
	{
		current = adlist[i];
		while (current != NULL)
		{
			cout << current->number << current->weight << "  ";
			current = current->next;
		}
		cout << endl;
	}*/
	/*for (int j = 0; j < 100; j++)
	if (store[j].size()!=0)
	{for (int a = 0; a < store[j].size(); a++)
	{cout<<store[j].at(a)<<" ";
	}
	cout << endl;
	}*/
	return;
}
int main()
{
	ksp a;
	a.Input();
	a.operation(1);
	a.show();
	return 0;
}