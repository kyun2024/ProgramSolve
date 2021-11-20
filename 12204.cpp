#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> memo[11];
int n;

void rec(string s, int lv, int open_b, int close_b){
    if(open_b == 0 && close_b == 0){
        memo[n].push_back(s);
        return;
    }
    if(open_b>0)rec(s+"(",lv+1,open_b-1,close_b);
    if(lv>0 && close_b>0)rec(s+")", lv-1, open_b, close_b-1);
}

int main(){
    for(n=1;n<=10;n++){
        rec("",0,n,n);
    }
    int T,i,k;
    cin >> T;
    for(i=1;i<=T;i++){
        cin >> n >> k;
        cout << "Case #" << i << ": ";
        if(k>memo[n].size()){
            cout << "Doesn't Exist!\n";
        }
        else{
            cout << memo[n][k-1] << "\n";
        }
    }
    return 0;
}