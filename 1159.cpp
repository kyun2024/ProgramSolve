#include <iostream>
#include <string>

using namespace std;

string a[150];

int main(){
    int n,c{},i,cc;
    cin >> n;
    cin.get();
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(char x='a';x<='z';x++){
        cc = 0;
        for(i=0;i<n;i++)
        {
            if(a[i][0]==x)cc++;
        }
        if(cc>=5){
            c++;
            cout << x;
        }
    }
    if(!c)cout << "PREDAJA\n";
    else cout << "\n";

}