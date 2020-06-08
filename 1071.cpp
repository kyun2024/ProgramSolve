#include <iostream>

using namespace std;

int nc[1002];

int main()
{
    int n;
    int i, j, m = 1001, M = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> j;
        nc[j]++;
        m = min(m, j);
        M = max(M, j);
    }
    //cout << m << " " << M << endl;
    for (i = m; i <= M; i++)
    {
        if (nc[i] != 0)
        {
            if (i == M)
            {
                while (nc[i] > 0)
                {
                    cout << i << " ";
                    nc[i]--;
                }
            }
            else if (i + 1 == M)
            {
                while (nc[i + 1] > 0)
                {
                    cout << i + 1 << " ";
                    nc[i + 1]--;
                }
                while (nc[i] > 0)
                {
                    cout << i << " ";
                    nc[i]--;
                }
            }
            else
            {
                if (nc[i + 1] == 0)
                {
                    while (nc[i] > 0)
                    {
                        cout << i << " ";
                        nc[i]--;
                    }
                }
                else{
                    for(j=i+2;j<=M;j++){
                        if(nc[j]!=0)break;
                    }
                    if(j>M){
                        cout << "ERROR!" << endl;
                        break;
                    }
                    while (nc[i] > 0)
                    {
                        cout << i << " ";
                        nc[i]--;
                    }
                    cout << j << " ";
                    nc[j]--;
                }
            }
        }
    }
    cout << endl;
    return 0;
}