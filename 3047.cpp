#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int m[3];

int main(){
    int i;
    for(i=0;i<3;i++)cin>>m[i];
    sort(m,m+3);
    string str;
    cin.get();
    cin >> str;
    for(auto c : str){
        cout << m[c-'A'] << " ";
    }
    cout << endl;
    return 0;
}