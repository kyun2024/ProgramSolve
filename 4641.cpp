#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t = 0,i,j,cnt;
    string str;
    vector<int> v;
    while(true){
        t=0;
        cnt = 0;
        getline(cin,str);
        v.clear();
        for(const auto x: str){
            if(x == '-')return 0;
            if('0'<= x && x<= '9'){
                t = 10*t + (x-'0');
            }
            else
            {
                v.push_back(t);
                t=0;
            }            
        }

        for(i=0;i<v.size();i++){
            for(j=0;j<v.size();j++){
                if(v[i] == v[j]*2){
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }
}