#include <iostream>

using namespace std;

long long arr[100001];

long long get_max(int s, int e)
{
    if(s == e)
    {
        // cout << "max of " << s << ", " << e << " is " << arr[s] * arr[s] << endl;
        return arr[s] * arr[s];
    }
    else
    {
        int m = (s+e)/2;
        long long l_max = get_max(s, m);
        long long r_max = get_max(m+1, e);
        int l_p = m, r_p = m + 1;
        long long min_elem = min(arr[l_p], arr[r_p]);
        long long cur_sum = (arr[l_p] + arr[r_p]);
        long long max_val = cur_sum  * min_elem;
        while(s < l_p && r_p < e)
        {
            if(arr[l_p-1] > arr[r_p + 1])
            {
                min_elem = min(arr[--l_p], min_elem);
                cur_sum += arr[l_p];
            }
            else
            {
                min_elem = min(arr[++r_p], min_elem);
                cur_sum += arr[r_p];
            }
            max_val = max(max_val, cur_sum * min_elem);
        }
        while(s < l_p)
        {
            min_elem = min(arr[--l_p], min_elem);
            cur_sum += arr[l_p];
            max_val = max(max_val, cur_sum * min_elem);
        }
        while(r_p < e)
        {
            min_elem = min(arr[++r_p], min_elem);
            cur_sum += arr[r_p];
            max_val = max(max_val, cur_sum * min_elem);
        }
        // max_val = max(max_val, max(l_max, r_max));
        // cout << "max of " << s << ", " << e << " is " << arr[s] * arr[s] << endl;
        return max(max_val, max(l_max, r_max));
    }
}

int main()
{
    int n, i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    cout << get_max(1, n) << endl;
    return 0;
}