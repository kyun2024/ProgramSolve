#include <iostream>

using namespace std;

int main(){
    int a{},b{};
    int n;
    int t[20];
    int i;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> t[i];
    }
    for(i=0;i<n;i++){
        a += (t[i]+30)/30*10;
        b += (t[i]+60)/60*15;
    }
    if(a<b){
        cout << "Y " << a << endl;
    }
    else if(a>b){
        cout << "M " << b << endl;
    }
    else{
        cout << "Y M " << a << endl;
    }
    return 0;
}