#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct qt{
    string s;
    int n;
};

int ix[]={1,2,3,4,5,6,7,8,9};
string op=" +-";

int main(){
    int T;
    int n,i,s=0,t,sign;
    cin >> T;
    while(T--){
        cin >> n;
        queue<qt> q;
        q.push({"",0});
        while(!q.empty()){
            //cout << "!" << q.front().s << " " << q.front().n << endl;
            if(q.front().n < n-1)for(auto c : op)q.push({string(q.front().s) += c, q.front().n + 1});
            else
            {
                s = 0;
                t = 1;
                sign = 1;
                for(i=0;i<n-1;i++){
                    switch(q.front().s[i]){
                    case '+':
                        s += sign*t;
                        sign = 1;
                        t = ix[i+1];
                        break;
                    case '-':
                        s += sign*t;
                        sign = -1;
                        t = ix[i+1];
                        break;
                    case ' ':
                        t = 10*t + ix[i+1];
                        break;
                    }
                }
                s += sign*t;
                if(s==0){
                    for(i=0;i<n-1;i++){
                        cout << ix[i] << q.front().s[i];
                    }
                    cout << n << endl;
                }
            }
            q.pop();
        }
        cout << endl;
    }
    return 0;
}