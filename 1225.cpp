#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1,s2;
    long long res=0;
    cin >> s1 >> s2;
    for(auto c1 : s1)for(auto c2:s2)res+=(c1-'0')*(c2-'0');
    cout << res << endl;
    return 0;
}