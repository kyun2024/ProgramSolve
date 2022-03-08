#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        if(str == "anj"){
            cout << "뭐야;" << endl;
            return 0;
        }
    }
    cout << "뭐야?" << endl;
    return 0;
}
