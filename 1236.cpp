#include <iostream>
#include <string>

using namespace std;

int a[50][50];

int main(){
    int r,c;
    int i,j;
    string str;
    bool b;
    int rn{},cn{};
    cin >> r >> c;
    cin.get();
    for(i=0;i<r;i++){
        getline(cin,str);
        for(j=0;j<c;j++){
            a[i][j] = (str[j]=='X');
        }
    }
    // row check
    for(i=0;i<r;i++){
        b = false;
        for(j=0;j<c;j++){
            b |= a[i][j];
        }
        rn += !b;
    }
    // col check
    for(j=0;j<c;j++){
        b = false;
        for(i=0;i<r;i++){
            b |= a[i][j];
        }
        cn += !b;
    }
    cout << max(rn,cn) << endl;
}