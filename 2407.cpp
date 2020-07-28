#include <iostream>
#include <iomanip>

using namespace std;

class numeric_int{
private:
    unsigned long long top,down;
public:
    numeric_int(unsigned long long top, unsigned long long down){
        this->top = top;
        this->down = down;
    }
    numeric_int(unsigned long long n=0){
        top=n/1'000'000'000'000'000'000ULL;
        down=n%1'000'000'000'000'000'000ULL;
    }
    numeric_int operator+(numeric_int other){
        unsigned long long t,d;
        d = down+other.down;
        t = top+other.top+d/1'000'000'000'000'000'000ULL;
        d%=1'000'000'000'000'000'000ULL;
        return numeric_int(t,d);
    }
    numeric_int operator+(unsigned long long other){
        unsigned long long t,d;
        d = down+other;
        t = top+d/1'000'000'000'000'000'000ULL;
        d%=1'000'000'000'000'000'000ULL;
        return numeric_int(t,d);
    }
public:
    friend ostream& operator<<(ostream& os, numeric_int x){
        if(x.top==0){
            os << x.down;
        }
        else{
            os << x.top << setw(18) << setfill('0') << x.down;
        }
        return os;
    }
};

numeric_int dp[101][101];

int main(){
    int n,m;
    int i,j;
    cin >> n >> m;
    dp[0][0]=1;
    for(i=1;i<=100;i++){
        dp[i][0]=1;
        for(j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    cout << dp[n][m] << endl;
}
