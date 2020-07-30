#include <iostream>
#include <vector>

using namespace std;

int r,c;
vector<int> init_virus;

int max_safe_area(vector<vector<int>>& v,vector<int>& q){
    vector<int> n_q;
    int x,y,res=0;
    if(q.size()==0){
        for(y=0;y<r;y++){
            for(x=0;x<c;x++){
                //cout << v[y][x];
                if(v[y][x]==0){
                    res+=1;
                }
            }
            //cout << endl;
        }
        //cout << res << endl;
        return res;
    }
    for(auto pos : q){
        x = pos%c;
        y = pos/c;
        if(x+1<c && v[y][x+1]==0){
            v[y][x+1]=2;
            n_q.push_back(pos+1);
        }
        if(x-1>=0 && v[y][x-1]==0){
            v[y][x-1]=2;
            n_q.push_back(pos-1);
        }
        if(y+1<r && v[y+1][x]==0){
            v[y+1][x]=2;
            n_q.push_back(pos+c);
        }
        if(y-1>=0 && v[y-1][x]==0){
            v[y-1][x]=2;
            n_q.push_back(pos-c);
        }
    }
    res = max_safe_area(v,n_q);
    for(auto pos : n_q){
        v[pos/c][pos%c]=0;
    }
    return res;
}

int select_area(vector<vector<int>>& v,int n,int cnt){
    int i;
    int res=0;
    for(i=n+1;i<r*c;i++){
        if(v[i/c][i%c]==0){
            v[i/c][i%c]=1;
            if(cnt==2){
                res=max(res,max_safe_area(v,init_virus));
            }
            else res=max(res,select_area(v,i,cnt+1));
            v[i/c][i%c]=0;
        }
    }
    return res;
}

int solution(vector<vector<int>>& m){
    return select_area(m,-1,0);
}

int main(){
    int i,j;
    vector<vector<int>> v;
    cin >> r >> c;
    v.resize(r,vector<int>(c));
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> v[i][j];
            if(v[i][j]==2){
                init_virus.push_back(i*c+j);
            }
        }
    }
    cout << solution(v) << endl;
    return 0;
}