#include<iostream>
#include<vector>
using namespace std;

class MaxHeap
{
private:
	int T,M,N,seat;
	
	vector<int> price[1000],total;
public:
	void Input();
	void Push(int,int);
	int Pull(int);
	void Show();
};
void MaxHeap::Input()
{
	int count;
	cin >> T ;
	for (int i = 0; i < T; i++)
	{
		count=0;
		price[i].push_back(0);
		cin >> M >> N;
		for (int j = 0; j < M; j++)
		{
			cin >> seat;
			Push(i,seat);//Price[j] is address，*Price[j] is 第一個元素位址//sizeof計算出來的為位元組//cout << (sizeof(*Price[j]) / sizeof (int));
		}
		for (int j = 0; j < N; j++)
		{
			/*for (int k = 1; k < price[i].size(); k++)
				cout << price[i].at(k) << " ";
			cout << endl;*/
			count += Pull(i);
			
		}
		total.push_back(count);
	}
	return;
}
void MaxHeap::Push(int i,int seat)
{
	int pos,temp1,temp2;
	price[i].push_back(seat);
	pos = price[i].size()-1 ;
	if (price[i].size() == 2)
		return;
	while (price[i].at(pos)>price[i].at(pos / 2))
	{
		temp1 = price[i].at(pos / 2);
		temp2 = price[i].at(pos);
		price[i].erase(price[i].begin() + pos / 2);
		price[i].insert(price[i].begin() + pos / 2, temp2);
		price[i].erase(price[i].begin() + pos);
		price[i].insert(price[i].begin() + pos,temp1);
		pos = pos / 2;
		if (pos == 1)
			return;
	}
	
}
int MaxHeap::Pull(int i)
{

	int parent=1, child=2,item,temp,n,temp2;
	n = price[i].size() - 1;
	item = price[i].at(1);
	temp = price[i].at(n--);
	while (child <= n)
	{
		if ((child < n) && price[i].at(child) < price[i].at(child + 1))
			child++;
		if (temp >= price[i].at(child))
			break;
		temp2 = price[i].at(child);
		price[i].erase(price[i].begin() + parent);
		price[i].insert(price[i].begin() + parent,temp2);
		parent = child;
		child *= 2;
	}
	price[i].erase(price[i].begin() + parent);
	price[i].insert(price[i].begin() + parent, temp);
	Push(i, item - 1);
	return item;
}
void MaxHeap::Show()
{
	for (int j = 0; j<total.size(); j++)//Price[j] is address，*Price[j] is value
		cout <<total.at(j) << endl;
	return;
}
int main()
{
	MaxHeap a;
	a.Input();
	a.Show();
	
	return 0;

}