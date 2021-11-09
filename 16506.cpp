#include <iostream>
#include <map>
#include <string>
#include <bitset>

using namespace std;

char* opc[]={"ADD","ADDC","SUB","SUBC","MOV","MOVC","AND","ANDC","OR","ORC","NOT","NOTC","MULT","MULTC","LSFTL","LSFTLC","LSFTR","LSFTRC","ASFTR","ASFTRC","RL","RLC","RR","RRC"};

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int i;
    map<string,int> s2op_m;
    for(i=0;i<24;i++){
        s2op_m[opc[i]]=i;
    }
    int n;
    cin >> n;
    int rd,ra,term;
    cin.get();
    string op_code;
    for(i=0;i<n;i++){
        cin >> op_code >> rd >> ra >> term;
        cin.get();
        if(s2op_m[op_code]%2==0){
            cout << bitset<5>(s2op_m[op_code]).to_string() << 0 << bitset<3>(rd).to_string() << bitset<3>(ra).to_string() << bitset<3>(term).to_string() << 0 << '\n';
        }
        else{
            cout << bitset<5>(s2op_m[op_code]).to_string() << 0 << bitset<3>(rd).to_string() << bitset<3>(ra).to_string() << bitset<4>(term).to_string() << '\n';
        }
    }
    return 0;
}