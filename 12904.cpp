#include <iostream>
#include <string>

using namespace std;

int main(){
    string str,target;
    cin >> target;
    cin >> str;
    while(str.length()>target.length()){
        if(str.back() == 'A'){
            str = string(str.begin(),str.end()-1);
        }
        else str = string(str.rbegin()+1,str.rend());
    }
    cout << (str==target) << endl;
    return 0;
}