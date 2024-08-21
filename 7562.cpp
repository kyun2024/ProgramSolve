#include <iostream>
#include <deque>
#include <tuple>
#include <string.h>

using namespace std;

int check[320][320];
deque<tuple<int, int, int>> v;
int X[] = {-1, -2, -2, -1,  1,  2, 2, 1};
int Y[] = { 2,  1, -1, -2, -2, -1, 1, 2};

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        int x0, y0, xn, yn;
        cin >> N;
        cin >> x0 >> y0 >> xn >> yn;
        v.push_back({x0, y0, 0});
        check[y0+10][x0+10]=1;
        while(!v.empty())
        {
            auto [x, y, c] = v.front();
            // cout << x << " " << y << " " << c << endl;
            if(x == xn && y == yn)
            {
                cout << c << endl;
                break;
            }
            if(x<0 || x>=N || y<0 || y>=N)
            {
                v.pop_front();
                continue;
            }
            for(int i=0;i<8;++i)
            {
                if(!check[y+Y[i]+10][x+X[i]+10])
                {
                    check[y+Y[i]+10][x+X[i]+10]=1;
                    v.push_back({x+X[i], y+Y[i], c+1});
                }
            }
            v.pop_front();
        }
        for(x0=0;x0<320;++x0)for(y0=0;y0<320;++y0)check[y0][x0]=0;
        v.clear();
    }
    return 0;
}