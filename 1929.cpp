#include <iostream>
#include <memory.h>

using namespace std;

int main(){
    int low,high,i,j;
    int* list;
    cin >> low >> high;
    list = new int[high+1];
    memset(list,0,sizeof(int)*(high+1));
    
    std::ios_base::sync_with_stdio(false);

    list[1]=1;
    for(i=2;i*i<=high;i++){
        if(list[i]==0){
            for(j=2*i;j<=high;j+=i){
                list[j]=1;
            }
        }
    }
    /*
    for(i=0;i<=high;i++){
        cout << list[i];
    }
    cout << endl;
    */
    for(i=low;i<=high;i++){
        if(list[i]==0){
            cout << i << '\n';
        }
    }
    delete[] list;
    return 0;
}