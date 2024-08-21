#include <iostream>
#include <string>

using namespace std;

int m[64][64];

string solution(int x0, int y0, int x1, int y1)
{
    // cout << "s : " << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
    int i,j;
    int s = 0;
    for(i=y0;i<y1;++i)
    {
        for(j=x0;j<x1;++j)
        {
            s += m[i][j];
        }
    }
    if(s == 0)
    {
        return "0";
    }
    if(s == (y1-y0)*(x1-x0))
    {
        return "1";
    }
    return "(" + solution(x0, y0, (x0+x1)/2, (y0+y1)/2) + 
                 solution((x1+x0)/2, y0, x1, (y1+y0)/2) + 
                 solution(x0, (y1+y0)/2, (x1+x0)/2, y1) +
                 solution((x1+x0)/2, (y1+y0)/2, x1, y1) + ")";
}

int main()
{
    int n, i, j;
    string x;
    cin >> n;
    for(i=0;i<n;++i)
    {
        cin >> x;
        for(j=0;j<n;++j)m[i][j]=x[j]-'0';
    }
    cout << solution(0, 0, n, n) << endl;
    return 0;
}