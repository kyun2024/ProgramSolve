#include <iostream>
#include <cmath>
#include <queue>
#include <memory>

using namespace std;

int main(){
    unsigned int input_n{};
    int i{},j{},sum{};
    int start_index{},coef{},mul_val{};
    queue<int> Q;
    
    input_n = 0;
    while(true){
        cin >> input_n;
        if(cin.eof()){
            break;
        }
        if(input_n%2==0 || input_n%5 == 0){
            std::cout << -1 << endl;
            continue;
        }
        if(input_n == 1){
            std::cout << 1 << endl;
            continue;
        }
        start_index = static_cast<int>(ceil(log10(input_n)));
        coef = static_cast<int>(pow(10,start_index))%input_n;
        /*
        Q.swap(*unique_ptr<decltype(Q),void(*)(decltype(Q)*)>(new decltype(Q)(),[](auto obj){
            cout << "Destruct Called" << endl;
            delete obj;
        }));
        */
        Q.swap(*unique_ptr<decltype(Q)>(new decltype(Q)()));
        sum = 0;
        for(i=0;i<start_index;i++){
            sum = sum + static_cast<int>(pow(10,i));
            Q.push(pow(10,i));
        }
        for(i=start_index;sum%input_n!=0;i++){
            mul_val = (Q.front() * coef)%input_n;
            sum = (sum + mul_val)%input_n;
            Q.push(mul_val);
            Q.pop();
        }
        cout << i << endl;
    }
}