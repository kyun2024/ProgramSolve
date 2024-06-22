#include <iostream>

using namespace std;

int m[102][102];
bool reserved[102][102];
bool visited[102][102];

int main(){
    int R, C;
    int i, j;
    int cheeze_c{},b_cheeze_c{};
    int air_c{}, b_air_c{};
    int t=0;
    cin >> R >> C;
    for(i=1;i<=R;i++)for(j=1;j<=C;j++)cin >> m[i][j];
    for(i=0;i<=R+1;i++)visited[i][0] = reserved[i][0] = visited[i][C+1] = reserved[i][C+1] = 1;
    for(j=0;j<=C+1;j++)visited[0][j] = reserved[0][j] = visited[R+1][j] = reserved[R+1][j] = 1;
    while(1)
    {
        for(i=1;i<=R;i++)for(j=1;j<=C;j++)if(m[i][j] == 0 && (visited[i-1][j] || visited[i+1][j] || visited[i][j-1] || visited[i][j+1])){reserved[i][j]=1;air_c++;}
        if(air_c == b_air_c)
        {
            for(i=1;i<=R;i++)for(j=1;j<=C;j++)if(m[i][j] == 1 && (visited[i-1][j] || visited[i+1][j] || visited[i][j-1] || visited[i][j+1])){reserved[i][j]=1;cheeze_c++;}
            if(cheeze_c == 0)break;
            for(i=1;i<=R;i++)for(j=1;j<=C;j++)if(m[i][j] == 1 && reserved[i][j]){
                m[i][j]=0;
                visited[i][j]=1;
            }
            ++t;
            b_cheeze_c = cheeze_c;
            cheeze_c = 0;
        }
        else
        {
            for(i=1;i<=R;i++)for(j=1;j<=C;j++)visited[i][j] = reserved[i][j];
        }
        b_air_c = air_c;
        air_c = 0;
    }
    cout << t << endl << b_cheeze_c << endl;
    return 0;
}