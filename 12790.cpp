#include <iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    int hp,mp,atk,def,ihp,imp,iatk,idef;

    while(T--){
        cin >> hp >> mp >> atk >> def >> ihp >> imp >> iatk >> idef;
        cout << max(1,hp+ihp)+5*max(1,mp+imp)+2*max(0,atk+iatk)+2*(def+idef) << '\n';
    }
    return 0;
}