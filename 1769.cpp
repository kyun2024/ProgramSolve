#include <iostream>
#include <string>

using namespace std;

int main(){
    int r=0,rt;
    int c=0;
    string str;
    cin >> str;
    if(str.length()==1){
        r = stoi(str);
    }
    else{
        for(const char& ch : str){
            r += ch-'0';
        }
        c+=1;
        while(r>9){
            rt = 0;
            while(r>0){
                rt += r%10;
                r /= 10;
            }
            r = rt;
            c+=1;
        }
    }
    cout << c << endl;
    if(r%3==0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}