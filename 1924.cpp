#include <iostream>

using namespace std;

int main(){
    //int months[]={    0,31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum_months[]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};
    int m,d;
    char c[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin >> m >> d;
    cout << c[(sum_months[m]+d-1)%7] << endl;
    return 0;
}