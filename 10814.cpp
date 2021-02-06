#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

vector<tuple<int,string,int>> datas;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,i;
    cin >> n;
    int x;
    string str;
    for(i=1;i<=n;i++){
        cin >> x >> str;
        datas.push_back(make_tuple(x,str,i));
    }
    sort(datas.begin(),datas.end(),[](const tuple<int,string,int>& x,const tuple<int,string,int>& y){
        if(get<0>(x) == get<0>(y)){
            return (get<2>(x)) < (get<2>(y));
        }
        return (get<0>(x)) < (get<0>(y));
    });
    for(const auto& x:datas){
        cout << get<0>(x) << " " << get<1>(x) << '\n';
    }
    return 0;
}