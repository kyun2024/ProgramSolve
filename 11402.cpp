#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

vector<unsigned long long> p1,p2;

bool check[2001][2001];
int memo[2001][2001];
unsigned long long m;

int nCr(int n,int k){
    if(n<0 || n<k || k<0) return 0;
    if(check[n][k])return memo[n][k];
    check[n][k]=true;
    
    return memo[n][k]=(nCr(n-1,k-1)+nCr(n-1,k))%m;
}

int main(){
    check[0][0]=1;
    memo[0][0]=1;

    unsigned long long n,k;
    cin >> n >> k >> m;
    auto t = n;
    decltype(n) rem{};
    while(t>0){
        rem = t%m;
        p1.push_back(rem);
        t/=m;
    }
    t = k;
    while(t>0){
        rem = t%m;
        p2.push_back(rem);
        t/=m;
    }
    while(p1.size()<p2.size()){
        p1.push_back(0);
    }
    while(p1.size()>p2.size()){
        p2.push_back(0);
    }
    //for(auto x : p1)cout << x; cout << endl;
    //for(auto x : p2)cout << x; cout << endl;
    int N = p1.size();
    int res = 1;
    for(int i=0;i<N;i++){
        res = (res * nCr(p1[i],p2[i]))%m;
    }
    cout << res << endl;
    return 0;
}