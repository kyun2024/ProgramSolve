#include <iostream>

using namespace std;

int pos[3];

int main(){
    int n,a,b,i,j;
    for(i=0;i<3;i++)pos[i]=i+1;
    cin >> n;
    while(n--){
        cin >> a >> b;
        for(i=0;i<3 && pos[i]!=a;i++);
        for(j=0;j<3 && pos[j]!=b;j++);
        swap(pos[i],pos[j]);
    }
    cout << pos[0] << endl;
}