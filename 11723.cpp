#include <iostream>
#include <string>

using namespace std;

constexpr int empty_set = 0;
constexpr int full_set = (1<<21)-2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    int set=0;
    int T,a;
    cin >> T;
    while(T--){
        cin >> s;
        if(s=="add"){
            cin >> a;
            set |= (1<<a);
        }
        if(s=="remove"){
            cin >> a;
            if(set&(1<<a)){
                set -= (1<<a);
            }
        }
        if(s=="check"){
            cin >> a;
            cout << ((set&(1<<a))?1:0) << '\n';
        }
        if(s=="toggle"){
            cin >> a;
            set ^= (1<<a);
        }
        if(s=="all"){
            set = full_set;
        }
        if(s=="empty"){
            set = empty_set;
        }
    }
}