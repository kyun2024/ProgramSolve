#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> a,s;
    int n;
    int len{};
    int i;
    cin >> n;
    a.resize(n,0);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    s.reserve(n);
    for(i=0;i<n;i++){
        vector<int>::iterator it = lower_bound(s.begin(),s.end(),a[i]);
        if(it!=s.end())*it=a[i];
        else s.push_back(a[i]);
    }
    cout << s.size() << endl;
    return 0;
}