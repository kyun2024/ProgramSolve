#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(){
    string str1,str2;
    vector<int> v1,v2;
    cin >> str1;
    cin >> str2;
    for(int i=0;i<str1.length();i++){
        v2.push_back(c[str1[i]-'A']);
        v2.push_back(c[str2[i]-'A']);
    }
    while(true){
        v1 = vector<int>();
        for(int i=0;i<v2.size()-1;i++){
            v1.push_back((v2[i]+v2[i+1])%10);
        }
        v2 = v1;
        if(v2.size()==2)break;
    }
    cout << v2[0] << v2[1] << endl;
    return 0;
}