#include <iostream>
#include <string>

using namespace std;

char nextChar(char c){
    switch(c){
        case 'B':return 'O';
        case 'O':return 'J';
        case 'J':return 'B';
    }
    return 0;
}

bool check[1000];
int min_e[1000];

int main(){
    int n;
    string str;

    cin >> n;
    cin >> str;
    check[0]=1;
    for(int i=0;i<n-1;i++){
        if(check[i]){
            char nc = nextChar(str[i]);
            for(int j=i+1;j<n;j++){
                if(str[j]==nc){
                    if(check[j]==0){
                        min_e[j]=(j-i)*(j-i)+min_e[i];
                    }
                    check[j]=1;
                    min_e[j]=min((j-i)*(j-i)+min_e[i],min_e[j]);
                }
            }
        }
    }
    if(!check[n-1])cout << -1 << endl;
    else cout << min_e[n-1] << endl;
    return 0;
}