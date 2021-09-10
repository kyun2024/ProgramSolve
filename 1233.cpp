#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> p[81];

int main(){
    int a,b,c,i,j,k;
    cin >> a >> b >> c;
    for(i=1;i<=80;i++)p[i].first=i;
    for(i=1;i<=a;i++)for(j=1;j<=b;j++)for(k=1;k<=c;k++)p[i+j+k].second++;
    sort(p,p+81,[](pair<int,int> i,pair<int,int> j){
        if(i.second==j.second){
            return i.first<j.first;
        }
        return i.second>j.second;
    });
    cout << p[0].first << endl;
    return 0;
}