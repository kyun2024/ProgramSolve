#include <iostream>

using namespace std;

int v[9];
int p[7];

bool check;

void dfs(int idx,int c){
    p[c]=v[idx];
    if(c==6){
        int s=0;
        for(int i=0;i<7;i++)s+=p[i];
        if(s==100){
            check=true;
            for(int i=0;i<7;i++){
                cout << p[i] << endl;
            }
        }
        return;
    }
    for(int i=idx+1;i<9;i++){
        if(check)break;
        dfs(i,c+1);
    }
}

int main(){
    int i;
    for(i=0;i<9;i++)cin >> v[i];
    for(i=0;i<3;i++)dfs(i,0);
}