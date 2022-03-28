#include <iostream>

using namespace std;

int a[4][3];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int w=1;
    for(i=2;i<=n;i++)
    {
        if(a[w][0]<a[i][0])w=i;
        else if(a[w][0]==a[i][0] && a[w][1]>a[i][1])w=i;
        else if(a[w][0]==a[i][0] && a[w][1]==a[i][1] && a[w][2]>a[i][2])w=i;
    }
    cout << w << endl;
    return 0;
}
