#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n;
    cin >> n;
    cin.get();
    while(n--){
        getline(cin,str);
        for(int i=0;i<str.length();i++){
            if(str[i]==' '){
                for(int j=i-1;j>=0 && str[j]!=' ';j--)
                {
                    cout << str[j];
                }
                cout << " "; 
            }
        }
        for(int j=str.length()-1;j>=0&&str[j]!=' ';j--)
        {
            cout << str[j];
        }
        cout << endl;
    }
    return 0;
}