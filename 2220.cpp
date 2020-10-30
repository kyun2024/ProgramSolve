#include <iostream>

using namespace std;

int heap[100001];

int main(){
    ios_base::sync_with_stdio(false);
    
    int n;
    int i,t;
    cin >> n;
    heap[1]=1;
    for(i=2;i<=n;i++){
        t=i-1;
        while(t!=1){
            swap(heap[t],heap[t/2]);
            t/=2;
        }
        heap[t]=i;
        heap[i]=1;
    }
    for(i=1;i<=n;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}