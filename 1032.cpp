#include <iostream>
#include <string>

using namespace std;

int main(){
    string a[50];
    int n;
    int i,j;
    char c;
    string result;
    cin >> n;
    cin.get();
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<a[0].length();i++){
        c = a[0][i];
        for(j=1;j<n;j++){
            if(c!=a[j][i])break;
        }
        if(j==n)result += c;
        else result += '?';
    }
    cout << result << endl;
    return 0;
}