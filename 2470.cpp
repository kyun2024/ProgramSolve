#include <iostream>
#include <algorithm>

using namespace std;

long long a[100000];

int main()
{
    long long N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    sort(a, a+N);
    long long min_sum = abs(a[0] + a[1]);
    long long res_sel0 = a[0], res_sel1 = a[1];
    for (int i = 0; i < N; ++i)
    {
        int idx = (lower_bound(a, a + N, -a[i]) - a);
        //cout << a[i] << " " << i << " " << a[idx] << " " << idx << endl;
        if (idx != i && idx < N)
        {
            if (min_sum > abs(a[i] + a[idx]))
            {
                min_sum = abs(a[i] + a[idx]);
                res_sel0 = a[i];
                res_sel1 = a[idx];
            }
        }
        if (idx - 1 != i && idx > 0)
        {
            if (min_sum > abs(a[i] + a[idx-1]))
            {
                min_sum = abs(a[i] + a[idx-1]);
                res_sel0 = a[i];
                res_sel1 = a[idx-1];
            }
        }
        if (idx + 1 != i && idx + 1 < N)
        {
            if (min_sum > abs(a[i] + a[idx + 1]))
            {
                min_sum = abs(a[i] + a[idx + 1]);
                res_sel0 = a[i];
                res_sel1 = a[idx + 1];
            }
        }
    }
    if (res_sel0 > res_sel1)
        swap(res_sel0, res_sel1);
    cout << res_sel0 << " " << res_sel1 << endl;
    return 0;
}