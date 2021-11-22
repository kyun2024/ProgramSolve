#include <iostream>

using namespace std;

int min_memo[3], max_memo[3], in_memo[3];

int main(){
    int n;
    cin >> n;
    n--;
    cin >> in_memo[0] >> in_memo[1] >> in_memo[2];
    min_memo[0] = max_memo[0] = in_memo[0];
    min_memo[1] = max_memo[1] = in_memo[1];
    min_memo[2] = max_memo[2] = in_memo[2];
    while(n--){
        cin >> in_memo[0] >> in_memo[1] >> in_memo[2];
        min_memo[0] = min(min_memo[0],min_memo[1]);
        min_memo[2] = min(min_memo[1], min_memo[2]);
        min_memo[1] = min(min_memo[0],min_memo[2]);
        max_memo[0] = max(max_memo[0], max_memo[1]);
        max_memo[2] = max(max_memo[1], max_memo[2]);
        max_memo[1] = max(max_memo[0],max_memo[2]);
        min_memo[0] += in_memo[0];  min_memo[1] += in_memo[1];  min_memo[2] += in_memo[2];  
        max_memo[0] += in_memo[0];  max_memo[1] += in_memo[1];  max_memo[2] += in_memo[2];  
    }
    cout << max(max(max_memo[0],max_memo[1]),max_memo[2]) << " ";
    cout << min(min(min_memo[0],min_memo[1]),min_memo[2]) << "\n";
    return 0;
}