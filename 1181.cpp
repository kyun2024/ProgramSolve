#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<string> v;
    cin >> n;
    cin.get();
    v.resize(n);
    for(auto& elem : v){
        cin >> elem;
    }
    sort(v.begin(),v.end(),[](const string& i,const string& j){
        if(i.length()==j.length()){
            return i<j;
        }
        return i.length()<j.length();
    });
    v.erase(unique(v.begin(),v.end()),v.end());
    for(const auto& elem : v){
        cout << elem << '\n';
    }
    return 0;
}