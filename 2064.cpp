#include <iostream>
#include <bitset>
#include <string>

using namespace std;

unsigned ip[1000];

int main(){
    int n;
    int i,j;
    unsigned x,t;
    string str;
    cin >> n;
    cin.get();
    for(i=0;i<n;i++){
        getline(cin,str);
        x=t=0;
        for(auto c : str){
            if(c=='.'){
                x = (x<<8)+t;
                t=0;
            }
            else{
                t = 10*t+(c-'0');
            }
        }
        x = (x<<8)+t;
        ip[i]=x;
    }
    for(j=0;j<32;j++){
        x = ip[0];
        t = (-1)<<j;
        x = x&t;
        for(i=1;i<n;i++){
            if(x != (ip[i]&t))break;
        }
        if(i==n){
            cout << (x>>24) << "." << ((x>>16)&255) << "." << ((x>>8)&255) << "." << (x&255) << endl;
            cout << (t>>24) << "." << ((t>>16)&255) << "." << ((t>>8)&255) << "." << (t&255) << endl;
            break;
        }
    }
    if(j==32){
        cout << "0.0.0.0" << endl;
        cout << "0.0.0.0" << endl;
    }
    return 0;
}