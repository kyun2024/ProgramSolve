#include <iostream>
#include <numeric>

using namespace std;

int a[1001];
int cost[1001];

int main(){
    int n;
    int i,k;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    for(i=1;i<=n;i++){
        cin >> k;
        a[i] = k-a[i];
    }
    cost[1]=abs(a[1]);
    for(i=2;i<=n;i++){
        if(a[i-1]*a[i]>0){  // Same Group
            if(abs(a[i-1])<abs(a[i]))cost[i]=abs(a[i]-a[i-1]);
        }
        else{
            cost[i] = abs(a[i]);
        }
    }
    for(i=1;i<=n;i++){
        cout << cost[i] << " ";
    }
    cout << endl;
    cout << accumulate(cost+1,cost+n+1,0) << endl;
    return 0;
}