#include <iostream>
#include <string>

using namespace std;

int Int(int r,int g,int b){
    return 2126*r+7152*g+722*b;
}

int main(){
    int n,m;
    string str{};
    int i,j,it;
    int r,g,b;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> r >> g >> b;
            it = Int(r,g,b);
            if(it<510000)str+='#';
            else if(it<1020000)str+='o';
            else if(it<1530000)str+='+';
            else if(it<2040000)str+='-';
            else str+='.';
        }
        str += '\n';
    }
    cout << str;
    return 0;
}