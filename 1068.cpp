#include <iostream>

using namespace std;

int p[50];
int n;
int d;

bool deleted(int);

bool is_leaf(int node){
    int i;
    for(i=0;i<n;i++){
        if(p[i]==node && !deleted(i)){
            return false;
        }
    }
    return true;
}

bool deleted(int node){
    while(node != -1){
        if(node == d)return true;
        node = p[node];
    }
    return false;
}

int main(){
    int i,s=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> p[i];
    }
    cin >> d;
    for(i=0;i<n;i++){
        if(is_leaf(i) && !deleted(i)){
            s += 1;
        }
    }
    cout << s << endl;
    return 0;
}