#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> V,A;
    int temp;
    while (true){
        cin >> temp;
        if(cin.eof())break;
        V.push_back(temp);
    }
    A.resize(V.size()-1,0);
    for(int i=0;i<V.size()-1;i++){
        A[i]=V[i+1]-V[i]-1;
    }
    int res{};
    for(auto x : A){
        res += x*(x+1)/2 -(x-1);
    }
    for(int i=0;i<A.size()-1;i++){
        for(int j=1;j<A.size();j++){
            res += A[i]*A[j];
        }
    }
    cout << res << endl;
    return 0;
}