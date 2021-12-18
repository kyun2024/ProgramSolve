#include <iostream>
#include <algorithm>

using namespace std;

int h_values[100001];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> h_values[i];
    sort(h_values+1,h_values+1+n,greater<int>());
    for(i=n;i>=0;i--){
        if(h_values[i]>=i){
            cout << i << endl;
            break;
        }
    }
    return 0;
}