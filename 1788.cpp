#include <iostream>
#include <cmath>

using namespace std;

template <size_t n,size_t shift>
class ShiftingArray{
private:
    int m[n];
public:
    int& operator[](int i){
        return m[i+shift];
    }
};

ShiftingArray<2000001,1000000> m;

int main(){
    int i;
    m[0]=0;
    m[1]=1;
    for(i=2;i<=1000000;i++){
        m[i]=(m[i-1]+m[i-2])%1000000000;
    }
    for(i=-1;i>=-1000000;i--){
        m[i]=(m[i+2]-m[i+1])%1000000000;
    }
    cin >> i;
    if(m[i]==0){
        cout << 0 << endl;
    }
    else cout << abs(m[i])/m[i] << endl;
    cout << abs(m[i]) << endl; 
    return 0;
}