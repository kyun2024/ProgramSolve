#include <iostream>
#include <string>

using namespace std;

char nas[4][5]={"ACAG",
                "CGTA",
                "ATCG",
                "GAGT"};

int trans(char c){
    switch (c)
    {
    case 'A':
        return 0;
    case 'G':
        return 1;
    case 'C':
        return 2;
    case 'T':
        return 3;
    }
}

int main(){
    char cur='\0';
    string str;
    int n,i;
    cin >> n;
    cin.get();
    getline(cin,str);
    cur = str[n-1];
    for(i=n-2;i>=0;i--){
        cur = nas[trans(str[i])][trans(cur)];
    }
    cout << cur << endl;
    return 0;
}