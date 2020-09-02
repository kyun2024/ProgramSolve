#include <iostream>
#include <string>

using namespace std;

string result[30000];
int query[100000];
int eval_pos[30];
int ep[30][30000];
int epl[30];

int main()
{
    int r, c, q;
    int i, x, y, p, index;
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    cin.get();
    for (i = r - 1; i >= 0; i--)
    {
        cin >> result[i];
    }
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> query[i];
    }
    fill_n(epl,c,r-1);
    for (i = 0; i < q; i++)
    {
        p = query[i] - 1;
        if (epl[p] == r-1)
        {
            x = p;
            y = r - 1;
        }
        else{
            for(y=epl[p];y<r-1;y++){
                if(result[y][ep[p][y]]=='.')break;
            }
            x = ep[p][y];
        }
        for (; y > 0; y--)
        {
            // cout << y << " " << x << " " << result[y-1][x] << endl;
            if (result[y - 1][x] == 'X')
            {
                break;
            }
            else if (result[y - 1][x] == 'O')
            {
                if (x > 0 && result[y][x - 1] == '.' && result[y - 1][x - 1] == '.')
                {
                    ep[p][y]=x;
                    x -= 1;
                }
                else if (x < c - 1 && result[y][x + 1] == '.' && result[y - 1][x + 1] == '.')
                {
                    ep[p][y]=x;
                    x += 1;
                }
                else
                {
                    break;
                }
            }
            else ep[p][y]=x;
        }
        result[y][x] = 'O';
        epl[p] = y+1;
        // if(eval_pos[p] != -1){
        //     cout << eval_pos[p]/c << " " << eval_pos[p]%c << '\n';
        // }
        // else cout << -1 << endl;
    }
    for (i = r - 1; i >= 0; i--)
    {
        cout << result[i] << '\n';
    }
    return 0;
}