#include <iostream>
#include <iomanip>

using namespace std;

class ubi{
private:
    static const unsigned long long dividor = 100000000ULL;
private:
    unsigned long long nums[255];
    unsigned long max_bit;
private:
    void __calculate__(){
        int i,p,r;
        for(i=0;i<=max_bit;i++){
            p = nums[i]/dividor;
            r = nums[i]%dividor;
            nums[i]=r;
            nums[i+1]+=p;
        }
        for(;nums[i]!=0;max_bit=i++){
            p = nums[i]/dividor;
            r = nums[i]%dividor;
            nums[i]=r;
            nums[i+1]+=p;
        }
    }
public:
    ubi(unsigned long long n=0){
        fill_n(nums,255,0);
        max_bit=0;
        nums[max_bit]=n;
    }
    friend ubi operator+(ubi a,ubi b){
        ubi r=0ULL;
        for(int i=0;i<=max(a.max_bit, b.max_bit);i++){
            r.nums[i] = a.nums[i] + b.nums[i];
        }
        r.__calculate__();
        return r;
    }
    friend ubi operator*(unsigned long long a,ubi b){
        ubi r=0ULL;
        for(int i=0;i<=b.max_bit;i++){
            r.nums[i] = a * b.nums[i];
        }
        r.__calculate__();
        return r;
    }
    friend ostream& operator<<(ostream& os, ubi x){
        int i;
        os << x.nums[x.max_bit];
        for(i=x.max_bit-1;i>=0;i--){
            os << setw(8) << setfill('0') << x.nums[i];
        }
        return os;
    }
};

ubi dp[255];

int main(){
    
    int n,i;
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(i=3;i<=250;i++){
        dp[i]=dp[i-1]+2*dp[i-2];
    }
    while(true){
        cin >> n;
        if(cin.eof())break;
        cout << dp[n] << endl;
    }
}