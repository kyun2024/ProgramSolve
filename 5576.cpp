#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int a,b,c,d,e,f;
    int g;
    cin >> a >> b >> c;
    if(a<b)swap(a,b);
    if(a<c)swap(a,c);
    if(b<c)swap(b,c);
    for(n=0;n<7;n++){
        cin >> g;
        if(c<g)swap(g,c);
        if(b<c)swap(b,c);
        if(a<b)swap(a,b);
    }
    cin >> d >> e >> f;
    if(d<e)swap(d,e);
    if(d<f)swap(d,f);
    if(e<f)swap(e,f);
    for(n=0;n<7;n++){
        cin >> g;
        if(f<g)swap(f,g);
        if(e<f)swap(e,f);
        if(d<e)swap(d,e);
    }
    cout << a+b+c << " " << d+e+f << endl;
    return 0;
}