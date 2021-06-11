#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int lc,uc,nc,sc;
    while(getline(cin,str)){
        lc = uc = nc = sc = 0;
        for(auto c : str){
            if('A'<=c && c<='Z')uc++;
            else if('a'<=c&&c<='z')lc++;
            else if('0'<=c&&c<='9')nc++;
            else if(c == ' ')sc++;
        }
        cout << lc << " " << uc << " " << nc << " " << sc << endl;
    }
    return 0;
}