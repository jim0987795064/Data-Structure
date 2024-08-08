#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

vector<char> array[26];//this vector is to store every group
vector<char> store[2];//this vector equals to Queue and Output

char member, value, y;
int group, number, index, z = 0, position = 0, sum, count2 = 0, count3 = 0;//index is to note y is in which array

class Queue {
private:
	char val;
	int index2;
	Queue *next;
public:
	void Arrangement(void);
	void Operation(void);
	void Show(void);
};

Queue *head=new Queue;
Queue *current;
Queue *check;
Queue *insertion;
Queue *replace;
Queue *take;
Queue *current2;
void Queue::Arrangement(void) {
	cin >> group;
	while (count3<group) {
		cin >> number;
		while (count2<number) {
			cin >> member;
			array[position].push_back(member);
			count2 += 1;
		}
		position++;
		count2 = 0;
		count3 += 1;
	}
	return;
}

void Queue::Operation(void) {
	int index, z = 0,count = 1,a=0;//index is to note y is in which array
	string x;
	char y, value;
	head->next = NULL;
	while (!cin.eof()) {
		check = head;
		index = 99;
		cin >> x;
		if (cin.eof() == 0) {
			if (x == "DEQUEUE") {

				value = head->val;
				replace = head; //相反assign
				take = head->next;
				for (int i = 0; i < count; i++)
				{
					if (head->next == replace)
					{
						head->next = take;
						break;//多break
					}
					else
					head = head->next;//由if前換至此行
				}
				head = take;
				a = head->index2;//重新設定最前面的index，以便於134行時進行檢查
				store[1].push_back(value);
				count--;//數量少一個
			}
			else if (x == "ENQUEUE") {
				cin >> y;
				for (int i = 0; i < group; i++)
				for (int j = 0; j < array[i].size(); j++)
				if (array[i].at(j) == y)
					index = i;
				if (index == 99 && head->next!=NULL) { //this char is not in any group
					//cout << y << endl;//
					current->val = y;
					current->index2 = index;
					current->next = new Queue;
					current = current->next;
					current->next = head;
					current->val = NULL;//先用替代
					current->index2 = 100;
					count++;
					/*current2 = head;//
					for (int k = 0; k < count; k++)
					{
						cout << current2->val;
						current2 = current2->next;
					}
					cout << endl;//*/
					//計算在linked list中有幾個資料
				}
				else if (head->next == NULL) { //first char into array[0]
					//cout << y << endl;//
					head->val = y;
					head->index2 = index;
					head->next = new Queue;
					check = head;
					current = head->next;
					current->next = head;
					current->val = NULL;//先用替代
					current->index2 = 100;
					count++;
					a=index;
					/*current2 = head;//
					for (int k = 0; k < count; k++)
					{
						cout << current2->val;
						current2 = current2->next;
					}
					cout << endl;//*/
				}
				else if (head->next != NULL && index != 99) //not first or index=99
				for (int i = 0; i < count; i++) {
					if (check->index2 == index) { //find same index,linked list insertion
						//cout << y << endl;//
						//cout << count;
						insertion = new Queue;
						insertion->val = y;//
						insertion->next = check;//
						insertion->index2=index;//
						replace = check;
						check = head;
						if (a == index)
							head = insertion;
						for (int j = 0; j < count; j++)
						{
							if (check->next == replace)
							{
								check->next = insertion;
								break;
							}
							else
								check = check->next;//////是否可以如此換節點??
						}
						count++;
						/*current2 = head;//
						for (int k = 0; k < count; k++)
						{
							cout << current2->val;
							current2 = current2->next;
						}
						cout << endl;//*/
						break;
					}
					else if (i == count - 1) { //first char of some group into array
						check = head;
						//cout << count;
						for (int j = 0; j < count; j++)
						{
							if (check->next == head)
							{
								//cout << y<<endl;//
								current = check;
								/*current->next = new Queue;
								current = current->next;
								current->val = y;
								current->index2 = index;*/
								///current->next = new Queue;
								///current = check->next;
								current->val = y;
								current->index2 = index;
								current->next = new Queue;
								current = current->next;
								current->next = head;
								count++;
								/*current2 = head;//
								for (int k = 0; k < count; k++)
								{
									cout << current2->val;
									current2 = current2->next;
								}
								cout << endl;//*/
								break;
							}
							else
								check = check->next;
						}
						break;
					}
					else
						check = check->next;
				}
			}
		}
		/*current = head;
		if (current != NULL)
		{
			cout << current->val;
			current = current->next;
		}
		cout << endl;*/
	}
	sum = count;
	return;
}

void Queue::Show(void)
{
	for (int i = 0; i<store[1].size(); i++)
	{
		cout << store[1].at(i) << endl;
		
	}
	return;
}

int main()
{

		Queue test;
		test.Arrangement();
		test.Operation();
		test.Show();
	
	return 0;
}