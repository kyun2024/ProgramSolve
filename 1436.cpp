#include <iostream>

using namespace std;

int main(){
    int i1,i2,i3,i4,i5,i6,i7;
    int n,c=0,t;
    cin >> n;
    for(i1=0;i1<=9;i1++){
        for(i2=0;i2<=9;i2++){
            for(i3=0;i3<=9;i3++){
                for(i4=0;i4<=9;i4++){
                    for(i5=0;i5<=9;i5++){
                        for(i6=0;i6<=9;i6++){
                            for(i7=0;i7<=9;i7++){
                                if(i1==i2&&i2==i3&&i3==6||
                                   i2==i3&&i3==i4&&i4==6||
                                   i3==i4&&i4==i5&&i5==6||
                                   i4==i5&&i5==i6&&i6==6||
                                   i5==i6&&i6==i7&&i7==6){
                                       c++;
                                       t=(((((i1*10+i2)*10+i3)*10+i4)*10+i5)*10+i6)*10+i7;
                                       if(c==n){
                                           cout << t << endl;
                                           return 0;
                                       }
                                   }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}