#include <iostream>

using namespace std;

int get_sum_of_digit(int number,int base){
    int sum_val = 0;
    while(number>0){
        sum_val += number % base;
        number /= base;
    }
    return sum_val;
}

int main(){
    int i;
    for(i=1000;i<10000;i++){
        if(get_sum_of_digit(i,10)==get_sum_of_digit(i,12) && get_sum_of_digit(i,16) == get_sum_of_digit(i,10)){
            cout << i << endl;
        }
    }
    return 0;
}