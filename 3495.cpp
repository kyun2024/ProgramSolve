#include <iostream>
#define is ==

using namespace std;

string s[100];

int main(){
    int n,m;
    int i,j;
    cin >> n >> m;
    cin.get();
    for(i=0;i<n;i++){
        getline(cin,s[i]);
    }
    int area2x = 0;
    int shape_in = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(s[i][j] is '/' or s[i][j] is '\\'){
                shape_in = !shape_in;
                area2x++;
            }
            else if(shape_in)area2x+=2;
        }
    }
    cout << (area2x>>1) << (area2x%2?".5":"") << endl;
    return 0;
}