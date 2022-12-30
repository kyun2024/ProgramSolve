#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main(){
    int n;
    int i,j;
    vector<int> primes;
    for(i=2;i<=4000000;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0)break;
        }
        if(j*j>i)primes.push_back(i);
    }
    //cout << primes.front() << " " << primes.back() << endl;
    cin >> n;
    int fp{}, bp{}, s{primes[0]}, c{};
    const int back_index = primes.size();
    while(1){
        if(n == s){
            c++;
            if(bp-1<back_index){
                s -= primes[fp]; fp++;
                bp++; s += primes[bp];
            }
            else break;
        }
        else if(n < s){
            if(fp < bp){
                s -= primes[fp];
                fp++;
            }
            else break;
        }
        else{ // n > s
            if(bp-1 < back_index)
            {
                bp++;
                s += primes[bp];
            }
            else break;
        }
    }
    cout << c << endl;
    return 0;
}