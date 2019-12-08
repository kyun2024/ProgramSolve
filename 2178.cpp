#include <iostream>
#include <vector>
#include <string>
#include <queue>

class path{
public:
    int x,y,c;
public:
    path(int x=0,int y=0,int c=0) : x(x), y(y), c(c){}
};

using namespace std;

int main(){
    string str;
    int i,j;
    int r,c;
    vector<vector<int>> input;
    queue<path> qpath;

    cin >> r >> c;
    cin.get();

    input.resize(r,vector<int>(c));

    for(i=0;i<r;i++){
        getline(cin,str);
        for(j=0;j<c;j++){
            input[i][j] = str[j]-'0';
        }
    }
    qpath.push(path(0,0,0));
    while(!qpath.empty()){
        path cur = qpath.front();
        //cout << cur.x << " " << cur.y << " " << cur.c << endl;
        if(cur.x == c-1 && cur.y == r-1)break;
        //Up
        if(cur.y > 0 && input[cur.y-1][cur.x]){
            input[cur.y-1][cur.x]=0;
            qpath.push(path(cur.x,cur.y-1,cur.c+1));
        }
        //Down
        if(cur.y < r-1 && input[cur.y+1][cur.x]){
            input[cur.y+1][cur.x]=0;
            qpath.push(path(cur.x,cur.y+1,cur.c+1));
        }
        //Left
        if(cur.x > 0 && input[cur.y][cur.x-1]){
            input[cur.y][cur.x-1]=0;
            qpath.push(path(cur.x-1,cur.y,cur.c+1));
        }
        //Right
        if(cur.x < c-1 && input[cur.y][cur.x+1]){
            input[cur.y][cur.x+1]=0;
            qpath.push(path(cur.x+1,cur.y,cur.c+1));
        }
        qpath.pop();
    }
    cout << qpath.front().c+1 << endl;

    return 0;
}