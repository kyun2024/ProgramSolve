#include <iostream>

using namespace std;

int left_node[200001], right_node[200001], nch[200001];

int find_k_num(int n, int k)
{
    if (left_node[n] == -1 && right_node[n] == -1)
    {
        return n;
    }
    else if (left_node[n] == -1)
    {
        return find_k_num(right_node[n], k);
    }
    else if (right_node[n] == -1)
    {
        return find_k_num(left_node[n], k);
    }
    else
    {
        if (k % 2 == 0)
        {
            return find_k_num(left_node[n], k / 2);
        }
        else
        {
            return find_k_num(right_node[n], k / 2);
        }
    }
    return -1;
}

int main()
{
    int n;
    long long k;
    int l, r;
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> l >> r;
        left_node[i] = l;
        right_node[i] = r;
    }
    cin >> k;
    int node_n;
    long long k_n;
    node_n = 1;
    k_n = k-1;
    while (left_node[node_n] != -1 || right_node[node_n] != -1)
    {
        if (left_node[node_n] == -1)
        {
            node_n = right_node[node_n];
        }
        else if (right_node[node_n] == -1)
        {
            node_n = left_node[node_n];
        }
        else
        {
            node_n = (k_n % 2 == 0) ? left_node[node_n] : right_node[node_n];
            k_n /= 2;
        }
    }
    cout << node_n << endl;
    return 0;
}