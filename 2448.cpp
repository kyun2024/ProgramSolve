#include <iostream>
using namespace std;

char m2[2][3][7] = {{"      ", "      ", "      "}, {"*     ", "* *   ", "***** "}};
char m3[3072*3073*2];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, _n;
    cin >> _n;
    n = _n / 3;

    int i, j;
    for(i=0;i<_n;i++)
    {   
        for(j=0;j < _n - i - 1;j++)m3[(2*_n+1)*i+j]=' ';
        for(j=0;j < _n + i + 1;j++){
            const int y = i/3, x = j/6;
            m3[(2*_n+1)*i + j + _n-i-1] = m2[((x^y)&x) == 0][i%3][j%6];
        }
        m3[(2*_n+1)*i+2*_n]='\n';
    }
    cout << m3;
    return 0;
}
