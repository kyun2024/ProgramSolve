#include <iostream>
#include <string>

using namespace std;

int a[10001][502];

int r,c;

int dfs(int cr,int cc){
    if(cr<=0 || cr>r || cc<=0 || cc>c)return 0;
    if(a[cr][cc])return 0;
    a[cr][cc]=2;
    /*
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]==1)cout << 'x';
            else if(a[i][j]==2)cout << '*';
            else cout << '.';
        }
        cout << "\n";
    }
    cout << "\n";
    */
    if(cc==1){
        // cout << "return at cc==0" << endl;
        return 1;
    }
    if(cr>1 && !(a[cr][cc-1]==2 && a[cr-1][cc]==2) && dfs(cr-1,cc-1)==1){
        // cout << "return at cr-1" << endl;
        return 1;
    }
    if(dfs(cr,cc-1)==1){
        // cout << "return at cr" << endl;
        return 1;
    };
    if(cr<=r && !(a[cr][cc-1]==2 && a[cr+1][cc]==2) && dfs(cr+1,cc-1)==1){
        // cout << "return at cr+1" << endl;
        return 1;
    }
    a[cr][cc]=1;
    return 0;
}

int main(){
    int i,j;
    string str;
    cin >> r >> c;
    for(i=1;i<=r;i++){
        cin >> str;
        for(j=1;j<=c;j++){
            if(str[j-1]=='x')a[i][j]=1;
        }
    }
    for(i=1;i<=r;i++){
        dfs(i,c);
        // cout << "dfs " << i << " end" << endl;
    }
    int s=0;
    for(i=1;i<=r;i++){
        s += a[i][c]==2;
    }
    cout << s << endl;
    /*
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(a[i][j]==1)cout << 'x';
            else if(a[i][j]==2)cout << '*';
            else cout << '.';
        }
        cout << '\n';
    }
    */
}