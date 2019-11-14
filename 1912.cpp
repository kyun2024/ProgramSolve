#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int i;
    int lo, hi, res;
    int n;
    vector<int> v, sum_list;
    cin >> n;
    v.resize(n);
    sum_list.resize(n);
    int sum_val = 0;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        sum_val = sum_val + v[i];
        if (i == 0)
        {
            res = sum_val;
        }
        sum_list[i] = sum_val;
        res = max(sum_val, res);
    }
    for (i = 0; i < n; i++)
    {
        cout << sum_list[i] << " ";
    }
    cout << endl;
    if(n == 1){
        res = v[0];
    }
    else if(n == 2){
        res = max(max(v[0],v[1]),v[0]+v[1]);
    }
    else if (n > 2)
    {
        lo = min(sum_list[0],sum_list[1]);
        hi = max(sum_list[0],sum_list[1]);        
        res = max(res,sum_list[1]-sum_list[0]);
        /*
        cout << "lo : " << lo << endl;
        cout << "hi : " << hi << endl;
        cout << "res : " << res << endl;
        */
        for (i = 2; i < n; i++)
        {
            if (sum_list[i] < lo)
            {
                if(sum_list[i] - lo > sum_list[i]){
                    res = max(res, sum_list[i] - lo);
                }
                lo = sum_list[i];
            }
            else
            {
                hi = sum_list[i];
                res = max(res, hi - lo);
            }
            //cout << "res : " << res << endl;
        }
    }
    cout << res << endl;
    
    return 0;
}