#include <iostream>

using namespace std;

int m1[100][100],m2[100][100],m3[100][100];

int main(){
    int i,j,k;
    pair<int,int> s1,s2;
    cin >> s1.first >> s1.second;
    for(i=0;i<s1.first;i++){
        for(j=0;j<s1.second;j++){
            cin >> m1[i][j];
        }
    }
    cin >> s2.first >> s2.second;
    for(i=0;i<s2.first;i++){
        for(j=0;j<s2.second;j++){
            cin >> m2[i][j];
        }
    }
    for(i=0;i<s1.first;i++){
        for(j=0;j<s2.second;j++){
            for(k=0;k<s1.second;k++){
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    for(i=0;i<s1.first;i++){
        for(j=0;j<s2.second;j++){
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}