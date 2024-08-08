#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std ;

class data
{
public:
	int number,dur,act1;
	data *next;
};

class aoe
{
private:
	data *adlist[100],*current;
	vector<int> store[4],vertex,dis,dis2,act2,act3,slack,critical1;
	vector<string> critical2;
	int n,act, vertex1, vertex2,weight;
	vector<int>::iterator result;
public:
	void input();
	void operation();
	void show();
};
void aoe::input()
{
	int pos=0,count;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >>act>> vertex1 >> vertex2 >> weight;
		store[0].push_back(act);
		store[1].push_back(vertex1);
		store[2].push_back(vertex2);
		store[3].push_back(weight);
	}
	for (int i = 0; i < store[1].size(); i++)
	{
		result = find(vertex.begin(), vertex.end(), store[1].at(i));
		if (result == vertex.end())
		vertex.push_back(store[1].at(i));
		result = find(vertex.begin(), vertex.end(), store[2].at(i));
		if (result == vertex.end())
		vertex.push_back(store[2].at(i));
	}
	for (int i = 0; i < vertex.size(); i++)//initialize for adlist and dis 
	{
		dis.push_back(0);
		adlist[i] = new data;
		adlist[i]->number = i;
		adlist[i]->dur = 0;
		adlist[i]->act1 = 0;
	}
	current = adlist[pos];
	for (int i = 0; i < store[1].size(); i++)
	{
		if (pos == store[1].at(i))
		{
			current->next = new data;
			current = current->next;
			current->number = store[2].at(i);
			current->dur = store[3].at(i);
			current->act1 = store[0].at(i);
			
		}
		else
		{
			current->next = NULL;
			pos = store[1].at(i);
			current = adlist[pos];
			current->next = new data;
			current = current->next;
			current->number = store[2].at(i);
			current->dur = store[3].at(i);
			current->act1 = store[0].at(i);
			
		}
		if (i == store[1].size() - 1)
			current->next = NULL;
			
	}
	for (int i = 0; i < vertex.size(); i++)
	{
		result = find(store[1].begin(), store[1].end(),i);
		if (result == store[1].end())
			adlist[i]->next = NULL;
	}
	for (int i = 0; i < store[1].size();i++)
	if (store[1].at(i) == 0)
	{
		dis.erase(dis.begin() + store[2].at(i));
		dis.insert(dis.begin() + store[2].at(i), store[3].at(i));
	}
	for (int i = 0; i < n; i++)
	{
		act2.push_back(0);
		act3.push_back(0);
	}
	return;
}
void aoe::operation()
{
	int length,max=0;
	for (int i = 1; i < vertex.size(); i++)
	{
		current = adlist[i]->next;
		while (current!= NULL)
		{
			if ((current->dur + dis.at(i))>dis.at(current->number))
				length = current->dur + dis.at(i);
			if (length>max)
			max = length;
			dis.erase(dis.begin() + current->number);
			dis.insert(dis.begin() + current->number, length);
			current = current->next;
		}
	}
	for (int i = 0; i<vertex.size(); i++)
	{
		/*dis2.push_back(0);
		if(i == vertex.size()-1)*/
			dis2.push_back(max);
	}
	for (int i = vertex.size()-1; i >-1; i--)
	{
		current = adlist[i]->next;
		while (current != NULL)
		{
			length = dis2.at(current->number) - current->dur;
			if (length < dis2.at(i))
				dis2.at(i) = length;
			current = current->next;
		}

	}
	for (int i = 0; i < vertex.size(); i++)
	{
		current = adlist[i]->next;
		while (current != NULL)
		{
			act2.erase(act2.begin() + (current->act1-1));
			act2.insert(act2.begin() + (current->act1-1), dis.at(i));
			current = current->next;
		}
	}
	for (int i = 0; i < vertex.size(); i++)
	{
		current = adlist[i]->next;
		while (current != NULL)
		{
			act3.erase(act3.begin() + (current->act1 - 1));
			act3.insert(act3.begin() + (current->act1 - 1), (dis2.at(current->number)-current->dur));
			current = current->next;
		}
	}
	for (int i = 0; i < act; i++)
	{
		slack.push_back(act3.at(i) - act2.at(i));
		if (act3.at(i) - act2.at(i) == 0)
		{
			critical1.push_back(i + 1);
			critical2.push_back("Yes");
		}
		else
			critical2.push_back("No");
	}
	return;
}
void aoe::show()
{
	/*for (int i = 0; i < vertex.size(); i++)
	{
		current = adlist[i];
		while (current != NULL)
		{
			cout << current->number << current->dur << current-> act1<< "  ";
			current = current->next;
		}
		cout << endl;
	}*/
	/*for (int i = 0; i < critical1.size(); i++)
		cout << critical1.at(i) << "  ";*/
	cout << "event" << setw(11) << "ee" << setw(13) << "le"<<endl;
	for (int i = 0; i<vertex.size(); i++)
		cout << i << setw(15) << dis.at(i) << setw(13) << dis2.at(i) << endl;
	cout << endl;
	cout << "act." << setw(12) << "e" << setw(12) << "l" << setw(14) << "slack" << setw(15) << "critical" << endl;
	for (int i = 0; i<n; i++)
	cout << i + 1 << setw(14) << act2.at(i) << setw(12) << act3.at(i) << setw(10) << slack.at(i) << setw(13) <<critical2.at(i)<< endl;
	cout << endl<<endl;
	for (int i = 0; i < critical1.size(); i++)
		cout << critical1.at(i) << " ";
	return;
}
int main()
{//dis dis2 act2 act3 print out
	aoe a;
	a.input();
	a.operation();
	a.show();
	return 0;
}