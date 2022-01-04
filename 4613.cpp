#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i,s;
    string str;
    while (1)
    {
        getline(cin, str);
        if(str == "#")break;
        s = 0;
        for(i=1;i<=str.length();i++){
            s += (str[i-1]==' '?0:str[i-1]-'A'+1)*i;
        }
        cout << s << endl;
    }
    return 0;
}