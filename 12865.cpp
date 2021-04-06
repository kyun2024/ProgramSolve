#include <iostream>
#include <algorithm>

using namespace std;

int m[101][100001];
pair<int,int> wv[101];

int main(){
    int n,k;
    int i,j;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> wv[i].first >> wv[i].second;
    }
    for(i=1;i<=n;i++){
        if(k<wv[i].first)
        {
            for(j=1;j<=k;j++){
                m[i][j]=m[i-1][j];
            }
            continue;
        }
        for(j=1;j<wv[i].first;j++){
            m[i][j]=m[i-1][j];
        }
        m[i][j]=max(m[i-1][j],wv[i].second);
        for(j=wv[i].first+1;j<=k;j++){
            m[i][j] = m[i-1][j];
            if(m[i-1][j-wv[i].first] != 0){
                m[i][j]=max(m[i][j],wv[i].second+m[i-1][j-wv[i].first]);
            }
        }
    }
    cout << *max_element(m[n]+1,m[n]+1+k+1) << endl;
    return 0;
}