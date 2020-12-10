#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class BigInt{
public:
    int x[420];
    int h;
public:
    BigInt(int n=0){
        h=1;
        x[0]=n;
    }
    BigInt(const BigInt& b){
        h=b.h;
        for(int i=0;i<b.h;i++){
            x[i]=b.x[i];
        }
    }
    string to_string(){
        int i;
        ostringstream oss;
        oss << std::to_string(x[h-1]);
        for(i=h-2;i>=0;i--){
            oss << setfill('0') << setw(8) << x[i];
        }
        return oss.str();
    }
    BigInt operator+(BigInt& other){
        int up_n=0,i,k;
        BigInt r;
        for(i=0;i<min(h,other.h);i++){
            k = other.x[i]+x[i]+up_n;
            up_n = k/100000000;
            k%=100000000;
            r.x[i]=k;
        }
        for(i=min(h,other.h);i<h;i++){
            if(up_n==0)break;
            k = x[i]+up_n;
            up_n = k/100000000;
            k%=100000000;
            r.x[i]=k;
        }
        for(i=min(h,other.h);i<other.h;i++){
            if(up_n==0)break;
            k = other.x[i]+up_n;
            up_n = k/100000000;
            k%=100000000;
            r.x[i]=k;
        }
        if(up_n>0){
            r.x[max(h,other.h)]=up_n;
        }
        r.h = max(h,other.h)+(up_n>0);
        return r;
    }
    BigInt operator=(BigInt&& b){
        h=b.h;
        for(int i=0;i<b.h;i++){
            x[i]=b.x[i];
        }
        return *this;
    }
};

BigInt m[10001]={BigInt(0),BigInt(1)};

int main(){
    int i,n;
    cin >> n;
    for(i=2;i<=n;i++){
        m[i]=m[i-2]+m[i-1];
    }
    cout << m[n].to_string() << endl;
    return 0;
}