#include <iostream>
#include <string>

using namespace std;

int m[1001][1001];

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int i,j;
    m[0][0] = str1.substr(0, 3) == str2.substr(0, 3);
    for(j=3;j<str2.length();j+=3){
        if(str1.substr(0, 3)==str2.substr(j, 3))m[0][j/3]=m[0][j/3-1]+1;
        else m[0][j/3] = m[0][j/3-1]; 
    }
    for(i=3;i<str1.length();i+=3)
    {
        m[i/3][0] = m[i/3-1][0] + (str1.substr(i,3)==str2.substr(0,3));
        for(j=3;j<str2.length();j+=3)
        {
            if(str1.substr(i,3) == str2.substr(j,3))
                m[i/3][j/3] = m[i/3-1][j/3-1] + 1;
            else m[i/3][j/3] = max(m[i/3-1][j/3], m[i/3][j/3-1]);
        }
    }
    cout << m[str1.length()/3-1][str2.length()/3-1] << endl;
    return 0;
}