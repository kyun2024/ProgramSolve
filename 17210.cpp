#include <iostream>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    if(n>=6){
        cout << "Love is open door\n";
    }
    else
    for (int i = 2; i <= n; i++)
    {
        t = !t;
        cout << t << endl;
    }
    return 0;
}