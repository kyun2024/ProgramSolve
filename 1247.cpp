#include <iostream>
#include <vector>

using namespace std;

int _gc = 3;

int main(){
    int n;
    vector<long long> v;
    int i,j;
    long long sum_v;

    v.reserve(100000);
    while(_gc--){
        cin >> n;
        v.resize(n);
        fill_n(v.begin(),n,0);
        for(i=0;i<n;i++)cin >> v[i];
        sum_v = i = j = 0;
        while(1){
            if(sum_v == 0){
                while(i<n && v[i]<=0)i++;
                while(j<n && v[j]>=0)j++;
                if(i==n && j==n){
                    cout << 0 << endl;
                    break;
                }
                else if(i==n){
                    cout << "-\n";
                    break;
                }
                else if(j==n){
                    cout << "+\n";
                    break;
                }
                else{
                    sum_v += v[i]+v[j];
                }
                i++;
                j++;
            }
            else if(sum_v < 0){
                while(i<n && v[i]<=0)i++;
                if(i==n){
                    cout << "-\n";
                    break;
                }
                else{
                    sum_v += v[i];
                }
                i++;
            }
            else{       // sum_v is positive
                while(j<n && v[j]>=0)j++;
                if(j==n){
                    cout << "+\n";
                    break;
                }
                else{
                    sum_v += v[j];
                }
                j++;
            }
        }
    }
}