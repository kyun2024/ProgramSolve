#include <iostream>
#include <vector>

using namespace std;

int main(){
    int z,i,m,l,it=0,f,jt;
    do{
        vector<int> v;
        cin >> z >> i >> m >> l;
        if(!(z | i | m | l))break;
        v.resize(m,0);
        f = l;
        v[f]=1;
        for(jt = 1;;jt++){
            l = (z*l+i)%m;
            v[l]++;
            if(v[l]>1)break;
        }
        if(f!=l)jt--;
        cout << "Case " << ++it <<": " << jt << endl;
    }while(true);
    return 0;
}