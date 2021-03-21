#include <iostream>

using namespace std;

int sa[28];

int main(){
    int i;
    sa[0]=3;
    for(i=1;i<=27;i++){
        sa[i] = 2*sa[i-1]+i+3;
    }
    int n;
    cin >> n;
    for(i=27;i>=0;i--){
        if(n<=(sa[i]-i-3)/2){
            // front
            // i--
        }
        else if(n==(sa[i]-i-3)/2+1){
            cout << 'm' << endl;
            break;
        }
        else if(n<=((sa[i]-i-3)/2)+i+3){
            cout << 'o' << endl;
            break;
        }
        else{
            //back
            n = n-(((sa[i]-i-3)/2)+i+3);
        }
    }
    return 0;
}