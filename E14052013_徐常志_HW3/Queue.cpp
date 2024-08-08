#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;
class Queue {
  private:
    string x;
    int group,number,index,z=0,position=0,count2=0,count3=0;//index is to note y is in which array
    char member,value,y;
    vector<char> array[26];//this vector is to store every group
    vector<char> store[2];//this vector equals to Queue and Output
    vector<int>  n[1];

  public:
    void Arrangement(void);
    void Operation(void);
    void Show(void);
};
void Queue::Arrangement(void) {
    cin>>group;
    while(count3<group) {
        cin>>number;
        while(count2<number) {
            cin>>member;
            array[position].push_back(member);
            count2+=1;
        }
        position++;
        count2=0;
        count3+=1;
    }
    return;
}

void Queue::Operation(void) {
    int index, z = 0;//index is to note y is in which array
    string x;
    char y,value;
    while (!cin.eof()) {
        index = 99;
        cin >> x;
        if (cin.eof() == 0) {
            if (x == "DEQUEUE") {
                value = store[0].at(0);
                store[1].push_back(value);
                store[0].erase(store[0].begin());
                n[0].erase(n[0].begin());
            } else if (x == "ENQUEUE") {
                cin >> y;
                for (int i = 0; i < group; i++)
                    for (int j = 0; j < array[i].size(); j++)
                        if (array[i].at(j) == y)
                            index = i;
                if (index ==99) { //this char is not in any group
                    store[0].push_back(y);
                    n[0].push_back(index);
                } else if (store[0].size() == 0) { //first char into array[0]
                    store[0].push_back(y);
                    n[0].push_back(index);
                } else if (store[0].size() != 0 && index != 99) //not first or index=99
                    for (int i = 0; i < n[0].size(); i++) {
                        if (n[0].at(i) == index) { //find same index

                            store[0].insert(store[0].begin() + i, y);
                            n[0].insert(n[0].begin() + i, index);
                            break;
                        } else if (i == n[0].size()-1) { //first char of some group into array
                            store[0].push_back(y);
                            n[0].push_back(index);
                            break;
                        }
                    }
            }
        }
    }
    return;
}

void Queue::Show(void) {
    for (int i = 0; i< store[1].size(); i++)
        cout<<endl<<store[1].at(i)<<endl;
}

int main() {
    Queue a;
    a.Arrangement();
    a.Operation();
    a.Show();
    return 0;
}
