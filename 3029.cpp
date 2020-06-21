#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    int t1,t2,r;
    string str;
    cin >> str;
    t1 = 3600*stoi(str.substr(0,2))+60*stoi(str.substr(3,2))+stoi(str.substr(6,2));
    cin >> str;
    t2 = 3600*stoi(str.substr(0,2))+60*stoi(str.substr(3,2))+stoi(str.substr(6,2));
    r = ((t2-t1+86399)%86400)+1;
    cout << setw(2) << setfill('0') << r/3600 << ":" << setw(2) << setfill('0') << (r%3600)/60 << ":" << setw(2) << setfill('0') << r%60 << endl;
    return 0;
}