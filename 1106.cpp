#include <iostream>
#include <algorithm>

using namespace std;

int memo[1101];
int price[21];
int gain[21];

int main(){
    int c,n;
    int i,j;
    cin >> c >> n;
    for(i=1;i<=n;i++)cin >> price[i] >> gain[i];
    for(i=1;i<=n;i++){
        if(memo[gain[i]]==0 || memo[gain[i]]>price[i])memo[gain[i]]=price[i];
        for(j=gain[i]+1;j<=1100;j++){
            if(memo[j-gain[i]]!=0 && (memo[j]==0 || memo[j]>memo[j-gain[i]]+price[i])){
                memo[j] = memo[j-gain[i]]+price[i];
            }
        }
    }
    int res = memo[c]?memo[c]:987654321; 
    for(i=c;i<=1100;i++)res = memo[i]!=0?min(memo[i],res):res;
    cout << res << endl;
    return 0;
}