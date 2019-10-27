#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int N,t,max_val,min_val;
    cin >> N >> t;
    max_val = t;
    min_val = t;
    for(int i=1;i<N;i++){
        cin >> t;
        if(t>max_val)max_val=t;
        if(t<min_val)min_val=t;
    }
    cout << min_val << " " << max_val << endl;
    return 0;
}
