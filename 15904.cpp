#include <iostream>
#include <string>

using namespace std;

bool check(string str)
{
    int i = 0;
    for (; i < str.length(); i++)
        if (str[i] == 'U')
            break;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
        if (str[i] == 'C')
            break;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
        if (str[i] == 'P')
            break;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
        if (str[i] == 'C')
            break;
    if (i == str.length())
        return false;
    return true;
}

int main()
{
    string str;
    getline(cin,str);
    if (check(str))
    {
        cout << "I love UCPC\n";
    }
    else
    {
        cout << "I hate UCPC\n";
    }
    return 0;
}