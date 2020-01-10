#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    v.resize(9);
    for(int i=0;i<9;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int i[7];
    for(i[0]=0;i[0]<9;i[0]++){
        for(i[1]=i[0]+1;i[1]<9;i[1]++){
            for(i[2]=i[1]+1;i[2]<9;i[2]++){
                for(i[3]=i[2]+1;i[3]<9;i[3]++){
                    for(i[4]=i[3]+1;i[4]<9;i[4]++){
                        for(i[5]=i[4]+1;i[5]<9;i[5]++){
                            for(i[6]=i[5]+1;i[6]<9;i[6]++){
                                if(v[i[0]]+v[i[1]]+v[i[2]]+v[i[3]]+v[i[4]]+v[i[5]]+v[i[6]]==100){
                                    for(auto x : i){
                                        cout << v[x] << '\n';
                                    }
                                    exit(0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}