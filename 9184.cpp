#include <iostream>

int dp[21][21][21];

int q(int a,int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    if(a>20||b>20||c>20){
        return q(20,20,20);
    }
    if(dp[a][b][c]!=0)return dp[a][b][c];
    if(a<b&&b<c)return dp[a][b][c]=q(a,b,c-1)+q(a,b-1,c-1)-q(a,b-1,c);
    else{
        return dp[a][b][c]=q(a-1,b,c)+q(a-1,b-1,c)+q(a-1,b,c-1)-q(a-1,b-1,c-1);
    }
}

int main(){
    using namespace std;
    int a,b,c;
    do{
        cin >> a >> b >> c;
        if(a==b && b==c && c==-1)break;
        cout << "w(" << a << ", " << b << ", " << c <<  ") = " << q(a,b,c) << endl;
    }while(1);
    return 0;
}