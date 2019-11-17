#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, j, k, idx;
    int r, c, n;
    cin >> r >> c >> n;
    int diag = min(r, c) / 2;
    auto v = vector<vector<int>>(r, vector<int>(c, 0));
    auto rolls = vector<int>(min(r, c) / 2);
    auto out = vector<vector<int>>(rolls.size());
    auto pos = vector<int>(rolls.size(), 0);
    for (i = 0; i < rolls.size(); i++)
    {
        rolls[i] = 2 * (r - 1 - 2 * i) + 2 * (c - 1 - 2 * i);
        out[i].resize(rolls[i]);
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    for (i = 0; i < rolls.size(); i++)
    {
        idx = 0;
        for (j = 0; j < c - 2 * i - 1; j++, idx++)
        {
            out[i][idx] = v[i][j + i];
        }
        for (j = 0; j < r - 2 * i - 1; j++, idx++)
        {
            out[i][idx] = v[j + i][c - i - 1];
        }
        for (j = 0; j < c - 2 * i - 1; j++, idx++)
        {
            out[i][idx] = v[r - i - 1][c - i - j - 1];
        }
        for (j = 0; j < r - 2 * i - 1; j++, idx++)
        {
            out[i][idx] = v[r - i - 1 - j][i];
        }
    }
    for (i = 0; i < rolls.size(); i++)
    {
        pos[i] = rolls[i] - n % rolls[i];
    }
    for (i = 0; i < rolls.size(); i++)
    {
        idx = 0;
        for (j = 0; j < c - 2 * i - 1; j++, idx++)
        {
            v[i][j + i] = out[i][(rolls[i] + idx - pos[i]) % rolls[i]];
        }
        for (j = 0; j < r - 2 * i - 1; j++, idx++)
        {
            v[j + i][c - i - 1] = out[i][(rolls[i] + idx - pos[i]) % rolls[i]];
        }
        for (j = 0; j < c - 2 * i - 1; j++, idx++)
        {
            v[r - i - 1][c - i - j - 1] = out[i][(rolls[i] + idx - pos[i]) % rolls[i]];
        }
        for (j = 0; j < r - 2 * i - 1; j++, idx++)
        {
            v[r - i - 1 - j][i] = out[i][(rolls[i] + idx - pos[i]) % rolls[i]];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    //v[min(min(i,j),min(r-i-1,c-i-1))]
    return 0;
}