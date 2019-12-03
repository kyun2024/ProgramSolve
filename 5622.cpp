#include <iostream>
#include <string>

using namespace std;

int main(){
    string input_data;
    int res{},i;
    cin >> input_data;
    for(i=0;i<input_data.size();i++){
        //cout << (input_data[i]-'A')/3;
        if(input_data[i]>='W'){
            res += 10;
        }
        else if(input_data[i]>='T'){
            res += 9;
        }
        else if(input_data[i]>='P'){
            res += 8;
        }
        else{
            res += (input_data[i]-'A')/3+3;
        }
    }
    cout << res << endl;
    return 0;
}