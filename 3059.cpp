#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n;
    cin >> n;

    int i,j,res;
    while(n--){
        cin >> str;
        res = 0;
        for(i='A';i<='Z';i++){
            for(j=0;j<str.length();j++){
                if(str[j] == i)break;
            }
            if(j == str.length())res += i;
        }
        cout << res << endl;
    }
    return 0;
}
