#include <iostream>

using namespace std;

int main(){
    long long n,s,t,k=0;
    int check=0;
    while(1){
        cin >> n;
        if(cin.eof())break;
        k = check = 0;
        s = n;
        while(check < (1<<10)-1){
            k++;
            t = s;
            while(t){
                check |= 1<<(t%10);
                t/=10;
            }
            s += n;
        }
        cout << k << endl;
    }
    return 0;
}