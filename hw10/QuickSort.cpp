#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Quicksort
{
private:
	vector<int> data;
	int N,count=0;
public:
	void input();
	void operation(int,int);
};
void Quicksort::input()
{
	ifstream ifile("D:\\123.txt", ios::in);
	while (!ifile.eof())
	{
		ifile >> N;
		data.push_back(N);
	}

	int left = 0, right = data.size()-1;
	operation(left,right);

	return;
}
void Quicksort::operation(int left,int right)
{
	//cout <<" left  "<< left <<" right: "<< right<<endl;
	int pivot,i,j,replace,replace2;
	if (left < right)
	{
		i = left, j = right + 1;
		pivot = data.at(left);
		do{
			do i++; while (i<=right&&data.at(i) < pivot);
			do j--; while (data.at(j) > pivot);
			//cout << i << "   " << j << endl;
			if (i < j)
			{
				replace = data.at(i),replace2 = data.at(j);
				data.erase(data.begin() + i);
				data.insert(data.begin() + i, replace2);
				data.erase(data.begin() + j);
				data.insert(data.begin() + j, replace); 
			}
		}while (i < j);
		replace = data.at(left), replace2 = data.at(j);
		data.erase(data.begin()+left);
		data.insert(data.begin()+left , replace2);
		data.erase(data.begin() + j);
		data.insert(data.begin() + j, replace);
		/*for (int i = 0; i < data.size(); i++)
		cout << data.at(i) << "  ";
		cout << endl;*/
		//cout << i << "  " << j << endl;
		//if (count==3)
		//system("pause");
		count++;
		operation(left, j - 1);
		operation(j + 1, right);
	}


	return;
}
int main()
{
	Quicksort a;
	a.input();
	return 0;
}