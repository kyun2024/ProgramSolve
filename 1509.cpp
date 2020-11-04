#include <iostream>
#include <string>

using namespace std;

bool isfelindrom[2500][2500];
int min_div[2500];

int main()
{
    int i, j;
    string str;
    cin >> str;
    for (i = 0; i < str.length(); i++)
    {
        isfelindrom[i][i] = true;
    }
    for (i = 0; i < str.length() - 1; i++)
    {
        isfelindrom[i][i + 1] = (str[i] == str[i + 1]);
    }
    for (i = 2; i < str.length(); i++)
    {
        for (j = 0; j < str.length() - i; j++)
        {
            isfelindrom[j][i + j] = (str[j] == str[i + j]) * isfelindrom[j + 1][i + j - 1];
        }
    }
    min_div[0] = 1;
    for (i = 1; i < str.length(); i++)
    {
        min_div[i] = i + 1;
        if (isfelindrom[0][i])
            min_div[i] = 1;
        else
        {
            for (j = 1; j <= i; j++)
            {
                if (isfelindrom[j][i])
                {
                    min_div[i] = min(min_div[i], min_div[j - 1] + 1);
                }
            }
        }
    }
    cout << min_div[str.length()-1] << endl;
    return 0;
}