#include <iostream>
using namespace std;

int main(){
    int h{},m{},t{};
    cin >> h >> m;
    t = h*60+m;
    t = (t - 45 + 60*24)%(24*60);
    h = t/60;
    m = t%60;
    cout << h << " " << m << endl;
    return 0;
}