#include <iostream>
#include <string>

using namespace std;

void proc(string &str, int &a1)
{
    if (str[1] == ' ')
    {
        a1 += (str[0] - '0') * 3600;
        if (str[5] == ' '){
            a1 += (str[4] - '0') * 60;
            if (str.length() == 9)
            {
                a1 += str[8] - '0';
            }
            else
            {
                a1 += 10 * (str[8] - '0') + (str[9] - '0');
            }
        }
        else{
            a1 += (10 * (str[4] - '0') + (str[5] - '0')) * 60;
            if (str.length() == 10)
            {
                a1 += str[9] - '0';
            }
            else
            {
                a1 += 10 * (str[9] - '0') + (str[10] - '0');
            }
        }
    }
    else
    {
        a1 += (10 * (str[0] - '0') + (str[1] - '0')) * 3600;
        if (str[6] == ' ')
        {
            a1 += (str[5] - '0') * 60;
            if (str.length() == 10)
            {
                a1 += str[9] - '0';
            }
            else
            {
                a1 += 10 * (str[9] - '0') + (str[10] - '0');
            }
        }
        else
        {
            a1 += (10 * (str[5] - '0') + (str[6] - '0')) * 60;
            if (str.length() == 11)
            {
                a1 += str[10] - '0';
            }
            else
            {
                a1 += 10 * (str[10] - '0') + (str[11] - '0');
            }
        }
    }
}

int main()
{
    int a1 = 0, a2 = 0;
    string str;
    getline(cin, str);
    proc(str,a1);
    getline(cin,str);
    proc(str,a2);
    cout << ((a2-a1+86400)%86400) << endl;
    return 0;
}