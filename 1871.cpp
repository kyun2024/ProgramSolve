#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
  string str;
  int n;
  cin >> n;
  while(n--){
    cin >> str;
    int a,b;
    a = (str[0]-'A')*26*26+(str[1]-'A')*26+(str[2]-'A');
    b = (str[4]-'0')*1000+(str[5]-'0')*100+(str[6]-'0')*10+(str[7]-'0');
    cout << ((abs(a-b) <= 100)?"nice":"not nice") << endl;
  }
  return 0;
}
