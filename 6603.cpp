#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main(){
    array<int,6> iter;
    iter.fill(0);
    int n,val{},i;
    vector<int> v;
    do{
        cin >> val;
        v.resize(val);
        for(i=0;i<val;i++){
            cin >> v[i];
        }
        for(iter[0]=0;iter[0]<val;iter[0]++){
            for(iter[1]=iter[0]+1;iter[1]<val;iter[1]++){
                for(iter[2]=iter[1]+1;iter[2]<val;iter[2]++){
                    for(iter[3]=iter[2]+1;iter[3]<val;iter[3]++){
                        for(iter[4]=iter[3]+1;iter[4]<val;iter[4]++){
                            for(iter[5]=iter[4]+1;iter[5]<val;iter[5]++){
                                for(i=0;i<6;i++){
                                    cout << v[iter[i]] << " ";
                                }
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
    }while(val != 0);
    return 0;
}