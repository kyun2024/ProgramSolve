#include <iostream>

using namespace std;

int main(){
    constexpr int n = 10;
    int a[10],b[10];
    int ta=0,tb=0;
    int i;
    char lastwin='D';
    for(i=0;i<n;i++)cin >> a[i];
    for(i=0;i<n;i++)cin >> b[i];
    for(i=0;i<n;i++){
        if(a[i]>b[i]){
            ta+=3;
            lastwin='A';
        }
        else if(a[i]<b[i])
        {
            tb+=3;
            lastwin='B';
        }
        else{
            ta++;
            tb++;
        }
    }
    cout << ta << " " << tb << endl; 
    if(ta>tb)cout << "A" << endl;
    else if(ta<tb)cout << "B" << endl;
    else cout << lastwin << endl;
    return 0;
}