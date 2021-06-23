#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string sen[10];
string q[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int sn,qn;
    cin >> n;
    for(int t=1;t<=n;t++){
        cin >> sn;
        cin.ignore(INT32_MAX,'\n');
        for(int i=0;i<sn;i++){
            getline(cin,sen[i]);
        }
        cin >> qn;
        cin.ignore(INT32_MAX,'\n');
        for(int i=0;i<qn;i++){
            getline(cin,q[i]);
        }
        int bm=0,se,res=0;
        for(int i=0;i<qn;i++){
            for(se=0;se<sn;se++){
                if(sen[se]==q[i])break;
            }
            if((bm|(1<<se))==((1<<sn)-1)){
                bm = 0;
                res++;
            }
            bm |= (1<<se);
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}