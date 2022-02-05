#include <iostream>

using namespace std;

long long bitcount_range(long long x)
{
    long long d, l;
    if (x <= 1)return x;
    for (d = 1, l = 0; 2 * d <= x; d <<= 1, l++);
    return (x - d) + bitcount_range(x - d) + 1 + l * (d >> 1);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << bitcount_range(b)-bitcount_range(a-1) << endl;
}