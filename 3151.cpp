#include <iostream>

using namespace std;

long long memo[20001];
constexpr int bias = 10000;
int inputs[10001];

long long nC2(long long n)
{
    return n * (n - 1) / 2;
}
long long nC3(long long n)
{
    return n * (n - 1) * (n - 2) / 6;
}

int main()
{
    int n;
    long long res = 0;
    int i, j, fn;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> inputs[i];
        memo[inputs[i] + bias]++;
    }
    if (memo[bias] > 2)
    {
        res += nC3(memo[bias]);
    }

    for (i = 1; i <= 10000; i++)
    {
        if (memo[i + bias] > 1 && i <= 5000)
        {
            res += nC2(memo[i + bias]) * memo[-2 * i + bias];
        }
        for (j = min(i - 1,10000-i); 2*j>-i; j--)
        {
            res += memo[i+bias]*memo[j+bias]*memo[-(i+j)+bias];
        }
        if(i%2==0){
            res += memo[i+bias]*nC2(memo[-(i/2)+bias]);
        }
    }
    cout << res << endl;
}