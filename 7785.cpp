#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    set<string> s;
    string str,name;
    int n;
    cin >> n;
    cin.get();
    while(n--){
        cin >> name;
        cin >> str;
        if(str == "enter"){
            s.insert(name);
        }
        if(str == "leave"){
            s.erase(name);
        }
    }
    vector<string> v = vector<string>(s.begin(),s.end());
    sort(v.begin(),v.end(),greater<string>());
    for_each(v.begin(),v.end(),[](const string& str){cout << str << '\n';});
    return 0;
}