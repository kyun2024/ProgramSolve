#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    vector<int> dp;
    cin >> str;
    dp.resize(str.size());
    if(str[0]!='0'){
        dp[0]=1;
    }
    else{
        cout << 0 << endl;
        return 0;
    }
    if(str[1]!='0'){
        dp[1]=dp[0]+(10*(str[0]-'0')+(str[1]-'0')<=26);
    }
    else if(str[0]=='1' || str[0] == '2'){
        dp[1] = 1;
    }
    else{
        cout << 0 << endl;
        return 0;
    }
    for(int i=2;i<str.size();i++){
        if(str[i]=='0'){
            if(str[i-1]=='1' || str[i-1]=='2'){
                dp[i] = dp[i-2]%1000000;
            }
            else{
                cout << 0 << endl;
                return 0;
            }
        }
        else{
            dp[i]=dp[i-1];
            if(str[i-1]!='0'){
                dp[i] += (10*(str[i-1]-'0')+(str[i]-'0')<=26)*dp[i-2];
            }
            dp[i] %= 1000000;
        }
    }
    cout << dp[str.size()-1] << endl;
    return 0;
}