#include <iostream>
#include <string>
#include <array>

using namespace std;

int main(){
    int i,j;
    array<int,10> a;
    string str;
    a.fill(0);
    cin >> str;
    for(auto x : str){
        a[x-'0']++;
    }
    for(i=9;i>=0;i--){
        for(j=0;j<a[i];j++){
            cout << i;
        }
    }
    cout << endl;

    return 0;
}