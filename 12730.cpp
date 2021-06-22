#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string sen[100];
string q[1000];

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
            //cin.ignore(INT32_MAX,'\n');
        }
        cin >> qn;
        cin.ignore(INT32_MAX,'\n');
        for(int i=0;i<qn;i++){
            getline(cin,q[i]);
            //cin.ignore(INT32_MAX,'\n');
        }
        bitset<100> bm;
        int se,res=0;
        for(int i=0;i<qn;i++){
            for(se=0;se<sn;se++){
                if(sen[se]==q[i])break;
            }
            bm.set(se);
            if(bm.count() == sn){
                bm.reset();
                res++;
            }
            bm.set(se);
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}