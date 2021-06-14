#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

pair<int,int> brace[10];
string str;
int st[200];
bool check[10];
int brc;
bool first_print = true;
vector<string> v;

void dfs(int i){
    if(i==brc){
        if(first_print){
            first_print = 0;
            return;
        }
        int j,k;
        string nstr;
        for(k=0;k<str.length();k++){
            if(str[k]=='('){
                for(j=0;j<brc;j++){
                    if(check[j] && brace[j].first==k){
                        nstr += str[k];
                    }
                }
            }
            else if(str[k]==')'){
                for(j=0;j<brc;j++){
                    if(check[j] && brace[j].second==k){
                        nstr += str[k];
                    }
                }
            }
            else nstr += str[k];
        }
        v.push_back(nstr);
        return;
    }
    check[i]=1;dfs(i+1);
    check[i]=0;dfs(i+1);
}

int main(){
    cin >> str;
    int height=0,i;
    for(i=0;i<str.length();i++){
        if(str[i]=='('){height++[st]=i;}
        if(str[i]==')')brc++[brace]=pair<int,int>((--height)[st],i);
    }
    sort(brace,brace+brc,[](const pair<int,int>& x,const pair<int,int>& y){
        return x.first<y.first;
    });
    dfs(0);
    sort(v.begin(), v.end());
    auto vu_end = unique(v.begin(),v.end());
    for(auto it = v.begin();it!=vu_end;it++){
        cout << *it << endl;
    }
    return 0;
}