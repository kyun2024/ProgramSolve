#include <iostream>

using namespace std;

bool mem[100001];

int main()
{
    int n, k;
    cin >> n >> k;
    int i, r, r2, c{};
    r = k % 10;
    r2 = (2 * k) %  10;
    for (i = 1; i <= n; i++)
    {
        if ((i % 10) != r && (i % 10) != r2){
            c++;
            mem[i]=1;
        }
    }
    cout << c << endl;
    for(i = 1; i<=n; i++){
        if(mem[i])cout << i << " ";
    }
    cout << endl;
    return 0;
}