#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Mat = vector<vector<ll>>;

Mat operator*(const Mat A, const Mat B)
{
    Mat m = {{0, 0}, {0, 0}};
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                m[i][j] = (m[i][j]+A[i][k]*B[k][j]+1000000007)%1000000007;
    return m;
}

Mat power(Mat A, ll n)
{
    if(n==1)return A;
    Mat m = power(A, n/2);
    if (n%2) return m*m*A;
    else return m*m;
}

int main()
{
    ll n;
    cin >> n;
    if(n%2){
        cout << 0 << endl;
        return 0;
    }
    Mat m = power({{4, -1}, {1, 0}}, n/2);
    cout << (power({{4, -1}, {1, 0}}, n/2)*Mat{{3, 0},{1, 0}})[1][0] << endl;

    return 0;
}