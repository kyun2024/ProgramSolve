#include <iostream>
#include <vector>

using namespace std;

vector<int> s;
int target_number;

int max_s_num(int sum_n){
    int res = 0;
    if(sum_n>target_number){
        return 0;
    }
    for(const auto& x : s){
        res = max(res,max_s_num(10*sum_n+x));
    }
    if(res==0)res = sum_n;
    return res;
}

int main(){
    int n;
    cin >> target_number;
    cin >> n;
    s.resize(n);
    for(auto& x:s){
        cin >> x;
    }
    cout << max_s_num(0) << endl;
    return 0;
}