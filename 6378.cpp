#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,r,i;
    string input_data;
    do{
        cin >> input_data;
        r = 0;
        for(i=0;i<input_data.size();i++){
            r += input_data[i] - '0';
        }
        n = r;
        if(n!=0){
            while(n>=10){
                r = 0;
                while(n>0){
                    r += n%10;
                    n/=10;
                }
                n = r;
            }
        }
        if(n!=0){
            cout << n << endl;
        }
    }while(n!=0);
    return 0;
}