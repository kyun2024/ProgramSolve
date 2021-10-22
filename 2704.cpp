#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str;
    int h,m,s;
    int i;

    cin >> n;
    cin.get();
    while(n--){
        cin >> str;
        h = 10*(str[0]-'0') + (str[1]-'0');
        m = 10*(str[3]-'0') + (str[4]-'0');
        s = 10*(str[6]-'0') + (str[7]-'0');
        for(i=5;i>=0;i--){
            cout << ((h>>i)&1);
            cout << ((m>>i)&1);
            cout << ((s>>i)&1);
        }
        cout << " ";
        for(i=5;i>=0;i--){
            cout << ((h>>i)&1);
        }
        for(i=5;i>=0;i--){
            cout << ((m>>i)&1);
        }
        for(i=5;i>=0;i--){
            cout << ((s>>i)&1);
        }
        cout << endl;
    }
    return 0;
}