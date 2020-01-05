#include <iostream>
#include <vector>

using namespace std;

auto main()->int{
    int N;
    int c=0,i,j;
    vector<int> weight,height;
    cin >> N;
    weight.resize(N);
    height.resize(N);
    for(i=0;i<N;i++){
        cin >> weight[i] >> height[i];
    }
    for(i=0;i<N;i++){
        c=0;
        for(j=0;j<N;j++){
            if(weight[i]<weight[j] && height[i]<height[j])c++;
        }
        cout << c+1 << " ";
    }
    cout << endl;
    return 0;
}