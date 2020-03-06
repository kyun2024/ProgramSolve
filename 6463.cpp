#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n,res=1;
    while(true){
        cin >> n;
        res=1;
        if(cin.eof())break;
        cout << setw(5) << right << n;
        do{
            res *= n;
            while(res%10==0)res/=10;
            res%=100000;
        }while(--n>0);
        cout << " -> " << res%10 << endl;
    }
    return 0;
}