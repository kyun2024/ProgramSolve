#include <iostream>
#include <string>

using namespace std;

string m[64];

string qt(int x,int y,int n){
    if(n==1){
        return string()+m[y][x];
    }
    string s1,s2,s3,s4;
    s1 = qt(x,y,n/2);
    s2 = qt(x+n/2,y,n/2);
    s3 = qt(x,y+n/2,n/2);
    s4 = qt(x+n/2,y+n/2,n/2);
    if(s1 == s2 && s3 == s4 && s2 == s3 && s1 == "0"){
        return "0";
    }
    if(s1 == s2 && s3 == s4 && s2 == s3 && s1 == "1"){
        return "1";
    }
    return "(" + s1 + s2 + s3 + s4 + ")";
}

int main(){
    int n,i;
    cin >> n;
    cin.get();
    for(i=0;i<n;i++){
        getline(cin,m[i]);
    }
    cout << qt(0,0,n) << endl;
    return 0;
}