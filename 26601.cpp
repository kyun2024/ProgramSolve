#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool prime[5000001];
vector<long long> prime_numbers;

int main()
{
    int i,j,k;
    for(i=2;i*i<=1500000;++i)
    {
        if(!prime[i]){
            for(j=i*i;j<=1500000;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(i=2;i<=1500000;++i)if(!prime[i])prime_numbers.push_back(i);
    int l = prime_numbers.size();
    for(i=0;i<l;++i)
    {
        for(j=2;j<=16;j*=2)
        {
            long long temp = 1500000, x = 1;
            for(k=0;k<j && temp>=1;++k)
            {
                temp /= prime_numbers[i];
                x *= prime_numbers[i];
            }
            if(temp>=1)
            {
                prime_numbers.push_back(x);
            }
        }
    }
    sort(prime_numbers.begin(),prime_numbers.end());
    int n;
    cin >> n;
    long long res = 1;
    for(i=0;i<n;++i)
    {
        res = (res * prime_numbers[i])%2000003;
    }
    cout << res << endl;
    return 0;
}