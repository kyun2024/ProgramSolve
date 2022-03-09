#include <iostream>
#include <string>

using namespace std;

int main(){
    int joi_cnt{}, ioi_cnt{};
    string str;
    cin >> str;
    for(int i=0;i<str.length()-2;i++){
        if(str.substr(i,3) == "JOI")joi_cnt++;
        if(str.substr(i,3) == "IOI")ioi_cnt++;
    }
    cout << joi_cnt << endl << ioi_cnt << endl;
    return 0;
}
