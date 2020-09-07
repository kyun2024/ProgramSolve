#include <iostream>
#include <algorithm>

using namespace std;

struct cd{
    int x,y;
};

cd a[100000];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i].x >> a[i].y;
    sort(a,a+n,[](const cd &i,const cd &j){if(i.x==j.x){return i.y<j.y;}return i.x<j.x;});
    for(i=0;i<n;i++)cout << a[i].x << " " << a[i].y << '\n';
    return 0;
}