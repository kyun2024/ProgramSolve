#include <iostream>
#include <string>

using namespace std;

int N;

int n_of_teacher;
pair<int, int> teachers[40];
char m[6][6];

int main()
{
    string s;
    int i,j;
    cin >> N;
    for(i=0;i<N;++i)for(j=0;j<N;++j)
    {
        cin >> s;
        if(s=="S"){
            m[i][j] = 'S';
        }
        else if(s=="T")
        {
            m[i][j] = 'T';
            teachers[n_of_teacher++] = {i, j};
        }
        else // X
        {
            m[i][j] = 'X';
        }
    }
    int i0, i1, i2;
    bool avoid=false;
    for(i0=0;i0<N*N;++i0)
    {
        for(i1=i0+1;i1<N*N;++i1)
        {
            for(i2=i1+1;i2<N*N;++i2)
            {
                if(m[i0/N][i0%N] == 'X' && m[i1/N][i1%N] == 'X' &&m[i2/N][i2%N] == 'X')
                {
                    m[i0/N][i0%N] = 'B';
                    m[i1/N][i1%N] = 'B';
                    m[i2/N][i2%N] = 'B';
                    avoid = true;
                    for(i=0;i<n_of_teacher;++i)
                    {
                        for(j=teachers[i].first-1;j>=0;--j){
                            if(m[j][teachers[i].second] == 'T' || m[j][teachers[i].second] == 'B')break;
                            else if(m[j][teachers[i].second] == 'S')
                            {
                                avoid = false;
                                break;
                            }
                        }
                        for(j=teachers[i].first+1;j<N;++j){
                            if(m[j][teachers[i].second] == 'T' || m[j][teachers[i].second] == 'B')break;
                            else if(m[j][teachers[i].second] == 'S')
                            {
                                avoid = false;
                                break;
                            }
                        }
                        for(j=teachers[i].second-1;j>=0;--j){
                            if(m[teachers[i].first][j] == 'T' || m[teachers[i].first][j] == 'B')break;
                            else if(m[teachers[i].first][j] == 'S')
                            {
                                avoid = false;
                                break;
                            }
                        }
                        for(j=teachers[i].second+1;j<N;++j){
                            if(m[teachers[i].first][j] == 'T' || m[teachers[i].first][j] == 'B')break;
                            else if(m[teachers[i].first][j] == 'S')
                            {
                                avoid = false;
                                break;
                            }
                        }
                    }
                    if(avoid)
                    {
                        cout << "YES" << '\n';
                        return 0;
                    }
                    m[i0/N][i0%N] = 'X';
                    m[i1/N][i1%N] = 'X';
                    m[i2/N][i2%N] = 'X';
                }
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}