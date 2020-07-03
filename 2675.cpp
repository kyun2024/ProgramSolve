#include <iostream>
#include <string>

using namespace std;

auto main()->int{
    int n{};
    int a,i;
    string s;
    cin >> n;
    while(n-->0){
        cin >> a >> s;
        for(const auto& elem : s){
            for(i=0;i<a;i++){
                cout << elem;
            }
        }
        cout << endl;
    }
    return 0;
}