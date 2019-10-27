#include <iostream>
#include <memory>

using namespace std;


int main(){
    int n;
    float *A;
    cin >> n;
    A = new float[n];
    for(int i=0;i<n;i++){
        cin >> i[A];
    }
    int m_val = A[0];
    for(int i=1;i<n;i++){
        if(m_val<A[i])m_val = A[i];
    }
    for(int i=0;i<n;i++){
        i[A] = i[A]/m_val*100;
    }
    float s_val = 0;
    for(int i=0;i<n;i++){
        s_val += A[i];
    }
    s_val = s_val/n;
    cout << s_val << endl;
    delete[] A;
    return 0;
}