#include <iostream>
#include <string>

using namespace std;

int add(int a,int b){
    return a+b;
}

int sub(int a,int b){
    return a-b;
}

int mul(int a,int b){
    return a*b;
}

int divs(int a,int b){
    return a/b;
}

int main(){
    int n=0;
    int(*op)(int,int);
    op = add;
    string str;
    while(true){
        cin >> str;
        if(str[0]=='+'){
            op = add;
        }
        else if(str[0]=='-'){
            op = sub;
        }
        else if(str[0]=='*'){
            op = mul;
        }
        else if(str[0]=='/'){
            op = divs;
        }
        else if(str[0]=='='){
            break;
        }
        else{
            n = op(n,stoi(str));
        }
    }
    cout << n << endl;
    return 0;
}