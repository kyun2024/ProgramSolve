#include <iostream>
#include <string>

using namespace std;

int transition[9][2] = {
    {5, 1},
    {2, -1},
    {3, -1},
    {3, 4},
    {5, 7},
    {-1, 6},
    {5, 1},
    {8, 7},
    {3, 6},
};

int main(){
    int n;
    int cs,i;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        cs = i = 0;
        while(i<str.length()){
            //cout << cs << " ";
            if(transition[cs][str[i]-'0'] >= 0){
                cs = transition[cs][str[i]-'0'];
                i++;
            }
            else {
                cs = -1;
                break;
            }
        }
        cout << ((cs == 4 || cs == 6 || cs == 7)?"YES":"NO") << endl;
    }
    return 0;
}