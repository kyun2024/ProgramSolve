#include <iostream>
#include <queue>

using namespace std;

class compare{
public:
    bool operator()(const int& a,const int& b){
        if(abs(a)==abs(b)){
            return a>b;
        }
        return abs(a)>abs(b);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    
    priority_queue<int,vector<int>,compare> pq;
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}