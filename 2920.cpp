#include <iostream>

using namespace std;
int main(){
    int A[8];
    int* a;
    for(a=A;a!=A+8;a++){
        cin >> *a;
    }
    if(( A[0] == 1 ) && ( A[1] ==2 ) && ( A[2] == 3 ) && ( A[3] == 4 ) && ( A[4] == 5 ) && ( A[5] == 6 ) && ( A[6] == 7 ) && ( A[7] == 8 )){
        cout << "ascending" << endl;
    }
    else if(( A[0] == 8 ) && ( A[1] == 7 ) && ( A[2] == 6 ) && ( A[3] == 5 ) && ( A[4] == 4 ) && ( A[5] == 3 ) && ( A[6] == 2 ) && ( A[7] == 1 )){
        cout << "descending" << endl;
    } 
    else cout << "mixed" << endl;
    return 0;
}