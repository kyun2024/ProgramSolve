#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string l1 = "`1234567890-=";
    string l2 = "QWERTYUIOP[]\\";
    string l3 = "ASDFGHJKL;'";
    string l4 = "ZXCVBNM,./";
    string::iterator it;
    string str;
    while (true)
    {
        getline(cin, str);
        if(cin.eof())break;
        for (const auto &ch : str)
        {
            it = find(l1.begin(), l1.end(), ch);
            if (it != l1.end())
            {
                cout << *(it - 1);
            }
            it = find(l2.begin(), l2.end(), ch);
            if (it != l2.end())
            {
                cout << *(it - 1);
            }
            it = find(l3.begin(), l3.end(), ch);
            if (it != l3.end())
            {
                cout << *(it - 1);
            }
            it = find(l4.begin(), l4.end(), ch);
            if (it != l4.end())
            {
                cout << *(it - 1);
            }
            if (ch == ' ')
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}