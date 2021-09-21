#include <iostream>
#include <string>

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    int s = 0;
    for (int c : str)
    {
        if ('A' <= c && c <= 'Z')
        {
            s += c - 'A' + 27;
        }
        if ('a' <= c && c <= 'z')
        {
            s += c - 'a' + 1;
        }
    }
    if (isprime(s))
    {
        cout << "It is a prime word.\n";
    }
    else
    {
        cout << "It is not a prime word.\n";
    }
    return 0;
}