#include <iostream>
#include <string>

using namespace std;

char s[6][6];
int m[6][6];
int mm[6][6];

int mul(int a,int b){
    return a*b;
}
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}

int(*sel_f(char c))(int,int){
    if(c=='*')return mul;
    else if(c=='-')return sub;
    else return add;
}

int main(){
    int n;
    string str;
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin >> str;
            s[i][j]=str[0];
        }
    }
    for(i=0;i<=n;i++){
        mm[i][0]=mm[0][i]=10000;
        m[i][0]=m[0][i]=-10000;
    }
    mm[1][1]=m[1][1]=s[1][1]-'0';
    for(i=2;i<=2*n-1;i++){
        for(j=1;j<=i;j++){
            if(i-j+1>n||j>n)continue;
            if(i%2==0){
                m[j][i-j+1]=max(m[j][i-j],m[j-1][i-j+1]);
                mm[j][i-j+1]=min(mm[j][i-j],mm[j-1][i-j+1]);
            }
            else{
                m[j][i-j+1]=max(sel_f(s[j][i-j])(m[j][i-j],s[j][i-j+1]-'0'),sel_f(s[j-1][i-j+1])(m[j-1][i-j+1],s[j][i-j+1]-'0'));
                mm[j][i-j+1]=min(sel_f(s[j][i-j])(mm[j][i-j],s[j][i-j+1]-'0'),sel_f(s[j-1][i-j+1])(mm[j-1][i-j+1],s[j][i-j+1]-'0'));
            }
        }
    }
    cout << m[n][n] << " " << mm[n][n] << endl;
    return 0;
}