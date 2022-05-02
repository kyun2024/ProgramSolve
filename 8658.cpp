#include <iostream>

using namespace std;

int main(){
    int n,i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        if(n%i)
        {
            cout << i << " ";
            break;
        }
    }
    for(i=n;i>=1;i--)
    {
        if(n%i)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
