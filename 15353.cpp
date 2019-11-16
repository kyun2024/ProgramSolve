//Same with 10757

#include <iostream>
#include <string>

using std::string;
string acc(string a,string b){
    string s = "";
    int n = 0;
    auto ia = a.rbegin();
    auto ib = b.rbegin();
    for(;ia!=a.rend() && ib!=b.rend();ia++,ib++){
        n = n + *ia + *ib -2*'0';
        s = char(n%10+'0') + s;
        n = n/10;
    }
    for(;ia!=a.rend();ia++){
        n = n + *ia -'0';
        s = char(n%10+'0') + s;
        n = n/10;
    }
    for(;ib!=b.rend();ib++){
        n = n + *ib -'0';
        s = char(n%10+'0') + s;
        n = n/10;
    }
    if(n!=0){
        s = char(n%10+'0')+s;
    }
    return s;
}

int main(){
    using namespace std;
    string a,b;
    cin >> a >> b;
    cout << acc(a,b) << endl;
}