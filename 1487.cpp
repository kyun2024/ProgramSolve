#include <iostream>

using namespace std;

class pr{
public:
    int price,ship;
};

pr a[1001];
int main(){
    int n;
    int i,j,res{},price=0,benefit;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i].price >> a[i].ship;
    }
    for(i=1;i<=n;i++){
        benefit = 0;
        for(j=1;j<=n;j++){
            if(a[i].price<=a[j].price && a[i].price-a[j].ship>0){
                benefit += a[i].price-a[j].ship;
            }
        }
        if(res<benefit || res==benefit && a[i].price < price){
            res = benefit;
            price = a[i].price;
        }
    }
    cout << price << endl;
}