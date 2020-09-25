#include <iostream>
#include <string>

char *al = "-\\(@?>&%";

using namespace std;

int indexOf(const char *s, char c)
{
    int i;
    for (i = 0; s[i] != 0; i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

int main()
{
    int res,i;
    string str;
    string::reverse_iterator rit;
    while (true)
    {
        res = 0;
        cin >> str;
        if(str[0]=='#')break;
        for (rit = str.rbegin(), i=1; rit != str.rend(); rit++,i*=8)
        {
            res += indexOf(al,*rit)*i;
        }
        cout << res << endl;
    }
}