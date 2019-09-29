#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

class abc{
public:
    int x,y,c;
};

int gcd(int a,int b){
    if(a<b){
        int t=a;
        a=b;
        b=t;
    }
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int a,b,x,y;                                //입력 값들 (a,b)->(x,y)
    queue<abc> q;                               //queue 생성
    vector<int> x0,xa,y0,yb;                    //(0,n),(a,n),(n,0),(n,b)
    int mv,mx,my,tc;                                     //move value, move after value
    cin >> a >> b >> x >> y;
    int gcd_val = gcd(a,b);
    if(0<x && x<a && 0<y && y<b){
        cout << "-1" << endl;
        return 0;
    }
    
    if(x%gcd_val != 0 || y%gcd_val != 0){
        cout << "-1" << endl;
        return 0;
    }
    
    if(x==0 & y==0){
        cout << "0" << endl;
        return 0;
    }
    
    a = a/gcd_val;
    b = b/gcd_val;
    x = x/gcd_val;
    y = y/gcd_val;
    
    x0.resize(b+1,0);
    xa.resize(b+1,0);
    y0.resize(a+1,0);
    yb.resize(a+1,0);

    x0[0]=y0[0]=-1;

    q.push(abc({0,0,0}));
    while(!q.empty()){
        abc front = q.front();
        //cout << front.x << " " << front.y << " " << front.c << endl;
        //1. Fill
        //Fill X
        if(front.y==0 && y0[a]==0){
            q.push({a,front.y,front.c+1});
            y0[a]=front.c+1;
            if(xa[0]==0){
                xa[0]=front.c+1;
            }
        }
        if(front.y==b && yb[a]==0){
            q.push({a,front.y,front.c+1});
            yb[a]=front.c+1;
            if(xa[b]==0){
                xa[b]=front.c+1;
            }
        }
        if(xa[front.y]==0){
            q.push({a,front.y,front.c+1});
            xa[front.y]=front.c+1;
        }
        //Fill Y
        if(front.x==0 && x0[b]==0){         
            q.push({front.x,b,front.c+1});
            x0[b]=front.c+1;
            if(yb[0]==0){
                yb[0]=front.c+1;
            }
        }
        if(front.x==a && xa[b]==0){
            q.push({front.x,b,front.c+1});
            xa[b]=front.c+1;
            if(yb[a]==0){
                yb[a]=front.c+1;
            }
        }
        if(yb[front.x]==0){
            q.push({front.x,b,front.c+1});
            yb[front.x]=front.c+1;
        }
        //2.Move
        //Move X to Y
        mv = min(b-front.y,front.x);mx = front.x-mv;my = front.y+mv;
        if(mx == 0 && x0[my]==0){
            q.push({mx,my,front.c+1});
            x0[my]=front.c+1;
        }
        if(mx == a && xa[my]==0){
            q.push({mx,my,front.c+1});
            xa[my]=front.c+1;
        }
        if(my == 0 && y0[mx]==0){
            q.push({mx,my,front.c+1});
            y0[mx]=front.c+1;
        }
        if(my == b && yb[mx]==0){
            q.push({mx,my,front.c+1});
            yb[mx]=front.c+1;
        }
        //Move Y to X
        mv = min(a-front.x,front.y);mx = front.x+mv;my = front.y-mv;
        if(mx == 0 && x0[my]==0){
            q.push({mx,my,front.c+1});
            x0[my]=front.c+1;
        }
        if(mx == a && xa[my]==0){
            q.push({mx,my,front.c+1});
            xa[my]=front.c+1;
        }
        if(my == 0 && y0[mx]==0){
            q.push({mx,my,front.c+1});
            y0[mx]=front.c+1;
        }
        if(my == b && yb[mx]==0){
            q.push({mx,my,front.c+1});
            yb[mx]=front.c+1;
        }
        //3. Spill
        //Spill X
        if(x0[front.y]==0){
            q.push({0,front.y,front.c+1});
            x0[front.y]=front.c+1;
        }
        //Spill Y
        if(y0[front.x]==0){
            q.push({front.x,0,front.c+1});
            y0[front.x]=front.c+1;
        }
        q.pop();
    }
    /*
    cout << "x0 : ";
    for(auto val : x0){
        cout << setw(3) << left << val;
    }
    cout << endl;
    cout << "xa : ";
    for(auto val : xa){
        cout << setw(3) << left << val;
    }
    cout << endl;
    cout << "y0 : ";
    for(auto val : y0){
        cout << setw(3) << left << val;
    }
    cout << endl;
    cout << "yb : ";
    for(auto val : yb){
        cout << setw(3) << left << val;
    }
    cout << endl;
    */
    if(x==a){
        cout << (xa[y]?xa[y]:-1) << endl;
    }
    else if(x==0){
        cout << (x0[y]?x0[y]:-1) << endl;
    }
    else if(y==b){
        cout << (yb[x]?yb[x]:-1) << endl;
    }
    else if(y==0){
        cout << (y0[x]?y0[x]:-1) << endl;
    }
    
    return 0;
}