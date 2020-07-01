#include <iostream>

auto main()->int{
    using namespace std;
    int i;
    int a,b;
    int sum=0;
    int res=0;
    for(i=0;i<10;i++){
        cin >> a >> b;
        sum += b-a;
        if(res<sum)res=sum;
    }
    cout << res << endl;
    return 0;
}