#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int i,j;
    string str1,str2;
    vector<vector<int>> v;
    cin >> str1 >> str2;
    v.resize(str1.length()+1,vector<int>(str2.length()+1,0));

    for(i=1;i<=str1.length();i++){
        for(j=1;j<=str2.length();j++){
            if(str1[i-1]==str2[j-1]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
    cout << v[str1.length()][str2.length()] << endl;
    return 0;
}