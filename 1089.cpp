#include <iostream>

using namespace std;

int pattern[10]={1168, 28086, 3096, 3120, 9270, 1584, 1552, 3510, 1040, 1072};

int vals[9];

int main(){
    int n,i,j,ten,cnt;
    double avg=0,tot_avg=0;
    char c;
    
    cin >> n;
    cin.get();
    for(i=0;i<5;i++){
        for(j=0;j<4*n;j++){
            c = cin.get();
            if(j%4==3)continue;
            vals[j/4]=2*vals[j/4]+(c=='#');
        }
    }
    for(i=n-1,ten=1;i>=0;i--,ten*=10){
        avg = 0;
        cnt = 0;
        for(j=0;j<=9;j++){
            if((pattern[j]&vals[i])==0){
                avg += j;
                cnt++;
            }
        }
        if(cnt == 0){
            cout << -1 << endl;
            return 0;
        }
        tot_avg += (avg*ten)/(double)(cnt);
    }
    cout << tot_avg << endl;
    return 0;
}