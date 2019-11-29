//solved

#include <iostream>
#include <string>

using namespace std;

template <int T>
void action(){
    int i,t,m;
    string s;
    getline(cin,s);
    for(i=1,t=1,m=1;i<8;i++,m=max(t,m))t=t*(s[i]==s[i-1])+1;
    cout << m << endl;
    action<T-1>();
}

template<>
void action<0>(){

}

int main(){
    action<3>();
    return 0;
}