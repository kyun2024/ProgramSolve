#include <iostream>

using namespace std;

bool check[31];

int main(){
    int i,x;
    for(i=1;i<=28;i++){
        cin >> x;
        check[x]=true;
    }
    for(i=1;i<=30;i++){
        if(!check[i])cout << i << endl;
    }
    return 0;
}