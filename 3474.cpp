#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int test_case{},n{};
    int i{};

    cin >> test_case;

    for(i=0;i<test_case;i++){
        cin >> n;
        cout << n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125+n/9765625+n/48828125+n/244140625 << endl;
    }
    return 0;
}