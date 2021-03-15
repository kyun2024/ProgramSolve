#include <iostream>
#include <string>

using namespace std;

int ti[27][2];
string prefix, infix, postfix;

void dfs(int n){
    prefix += n+'A'-1;
    if(ti[n][0]!=0){
        dfs(ti[n][0]);
    }
    infix += n+'A'-1;
    if(ti[n][1]!=0){
        dfs(ti[n][1]);
    }
    postfix += n+'A'-1;
}

int main(){
    int n,i;
    string str;
    cin >> n;
    cin.get();
    for(i=1;i<=n;i++){
        getline(cin,str);
        ti[str[0]-'A'+1][0]=(str[2]=='.')?0:str[2]-'A'+1;
        ti[str[0]-'A'+1][1]=(str[4]=='.')?0:str[4]-'A'+1;
    }
    dfs(1);
    cout << prefix << endl << infix << endl << postfix << endl;
    return 0;
}