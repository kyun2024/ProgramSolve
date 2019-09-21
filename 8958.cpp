#include <iostream>
#include <string>

using namespace std;

int main(){
    int N{},i{},cnt{},score{};
    string str;
    cin >> N;
    cin.get();
    for(i=0;i<N;i++){
        getline(cin,str);
        cnt = 0;
        score = 0;
        for(auto x : str){
            if(x=='X'){
                cnt = 0;
            }
            else{   //x=='O'
                cnt += 1;
                score += cnt;
            }
        }
        cout << score << endl;
    }
    return 0;
}