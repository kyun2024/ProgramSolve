#include <iostream>

using namespace std;

int main(){
    int y,m,d;
    int yy,mm,dd;
    cin >> y >> m >> d;
    cin >> yy >> mm >> dd;

    int a1,a2;
    a1 = yy-y;
    if(mm<m || mm==m && dd<d)a1--;
    cout << a1 << endl;
    a2 = yy-y;
    cout << a2+1 << endl;
    cout << a2 << endl;
    return 0;
}