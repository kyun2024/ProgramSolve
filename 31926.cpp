#include <iostream>

using namespace std;

int main()
{
    int n, c;
    cin >> n;
    for(c=0;n>1;n>>=1, ++c);
    cout << c + 10 << endl;
    return 0;
}