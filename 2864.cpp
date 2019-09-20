#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a{},b{};
    int max_a{},min_a{},max_b{},min_b{};
    int r{};
    cin >> a >> b;
    for(r=1;r<=1e6;r*=10){
        int key_a{},key_b{};
        key_a = a/r%10;
        key_b = b/r%10;
        if(key_a==5||key_a==6){
            max_a += 6*r;
            min_a += 5*r;
        }
        else{
            max_a += key_a*r;
            min_a += key_a*r;
        }
        if(key_b==5||key_b==6){
            max_b += 6*r;
            min_b += 5*r;
        }
        else{
            max_b += key_b*r;
            min_b += key_b*r;
        }
    }
    cout << min_a + min_b << " " << max_a + max_b << endl;
    return 0;
}