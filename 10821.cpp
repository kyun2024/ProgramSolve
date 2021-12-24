#include <iostream>
#include <string>

using namespace std;

int main(){
    int n=0;
    string str;
    cin >> str;
    for(auto c : str)n += c==',';
    cout << n+1 << endl;
    return 0;
}