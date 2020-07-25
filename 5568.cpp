#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    set<int> numbers;
    int n,m;
    int i,j,k,l,num2,num3,num4;
    vector<int> v;
    cin >> n >> m;
    v.resize(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            num2 = 100*v[i]*(v[j]>=10)+10*v[i]*(v[j]<10)+v[j];
            if(m==2){
                numbers.insert(num2);
                continue;
            }
            for(k=0;k<n;k++){
                if(i==k||j==k)continue;
                num3 = 100*num2*(v[k]>=10)+10*num2*(v[k]<10)+v[k];
                if(m==3){
                    numbers.insert(num3);
                    continue;
                }
                for(l=0;l<n;l++){
                    if(i==l||j==l||k==l)continue;
                    num4 = 100*num3*(v[l]>=10)+10*num3*(v[l]<10)+v[l];
                    numbers.insert(num4);
                }
            }
        }
    }
    cout << numbers.size() << endl;
}