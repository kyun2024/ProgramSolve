#include <iostream>
#include <bitset>
#include <string>

using namespace std;

char m[]={'\'',',','-','.','?'};

void proc(string str)
{
    int n = 0, i;
    string bit;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            n++;
        }
        else
        {
            if (n > 0)
            {
                bit += (n % 2 == 0) + '0';
            }
            n = 0;
        }
    }
    if (n > 0)
    {
        bit += (n % 2 == 0) + '0';
    }
    while(bit.length()%5!=0){
        bit += '0';
    }
    for(i=0;i<bit.length();i+=5){
        int t=bitset<5>(bit.substr(i,5)).to_ulong();
        if(t==0)cout << " ";
        if(0<t && t<27){
            cout << (char)('A'+t-1);
        }
        if(t>26){
            cout << m[t-27];
        }
    }
    cout << endl;
}

int main()
{
    string str, ts;
    while (true)
    {
        getline(cin,str);
        if (str == "*")
        {
            proc(ts);
            ts = "";
        }
        else if (str == "#")
            break;
        else
        {
            ts += str;
        }
    }
}