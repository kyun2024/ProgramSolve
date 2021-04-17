#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    cin.get();
    cin >> str;
    int a,b;
    a=b=0;
    for(const auto& x:str){
        if(x=='A')a++;
        if(x=='B')b++;
    }
    if(a>b)cout << 'A' << endl;
    if(a<b)cout << 'B' << endl;
    if(a==b)cout << "Tie" << endl;
    return 0;
}