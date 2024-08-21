#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    int i,j,k;
    int res=1, temp;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<i;++j)
        {
            if(str[j] != str[j+n-i])break;
        }
        if(j==i)
        {
            string s = str + str.substr(i);
            temp = 0;
            for(j=0;j+n-1<s.length();++j)
            {
                for(k=0;k<n;++k)
                {
                    if(s[k] != s[k+j])break;
                }
                if(k==n)++temp;
            }
            res = max(res, temp);
        }
    }
    cout << res << endl;

    return 0;
}