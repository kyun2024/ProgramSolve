#include <iostream>

using namespace std;

int main(){
    int n;
    int i,j;
    cin >> n;
    //front
    for(j=0;j<n;j++){
        cout << "*";
    }
    for(j=0;j<2*n-3;j++){
        cout << " ";
    }
    for(j=0;j<n;j++){
        cout << "*";
    }
    cout << endl;
    //middle
    for(i=1;i<n-1;i++){
        for(j=1;j<=i;j++)cout << " ";
        cout << "*";
        for(j=1;j<n-1;j++)cout << " ";
        cout << "*";
        //Spacing
        for(j=0;j<2*(n-i)-3;j++)cout << " ";
        cout << "*";
        for(j=1;j<n-1;j++)cout << " ";
        cout << "*";
        cout << endl;
    }
    for(j=1;j<n;j++)cout<< " ";
    cout << "*";
    for(j=1;j<n-1;j++)cout << " ";
    cout << "*";
    for(j=1;j<n-1;j++)cout << " ";
    cout << "*\n";
    for(i=n-2;i>=1;i--){
        for(j=1;j<=i;j++)cout << " ";
        cout << "*";
        for(j=1;j<n-1;j++)cout << " ";
        cout << "*";
        //Spacing
        for(j=0;j<2*(n-i)-3;j++)cout << " ";
        cout << "*";
        for(j=1;j<n-1;j++)cout << " ";
        cout << "*";
        cout << endl;
    }
    //back
    for(j=0;j<n;j++){
        cout << "*";
    }
    for(j=0;j<2*n-3;j++){
        cout << " ";
    }
    for(j=0;j<n;j++){
        cout << "*";
    }
    cout << endl;
}