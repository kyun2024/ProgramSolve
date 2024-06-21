#include <deque>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int solution(vector<int> &heights)
{
    deque<int> left_top_idx;
    deque<int> right_top_idx;
    vector<long long> sum_array(heights.size());

    int i;
    long long res = 0;
    left_top_idx.push_back(0);
    for (i = 1; i < heights.size(); ++i)
    {
        if (heights[left_top_idx.back()] <= heights[i])
        {
            left_top_idx.push_back(i);
        }
    }
    if (left_top_idx.back() < heights.size() - 1)
        right_top_idx.push_back(heights.size() - 1);
    for (i = heights.size() - 2; i > left_top_idx.back(); --i)
    {
        if (heights[right_top_idx.back()] <= heights[i])
        {
            right_top_idx.push_back(i);
        }
    }
    while (!right_top_idx.empty())
    {
        left_top_idx.push_back(right_top_idx.back());
        right_top_idx.pop_back();
    }
    sum_array[0] = heights[0];
    for (i = 1; i < sum_array.size(); ++i)
    {
        sum_array[i] = sum_array[i - 1] + heights[i];
    }
    for (i = 1; i < left_top_idx.size(); ++i)
    {
        if (left_top_idx[i] != left_top_idx[i - 1] + 1)
        {
            long long h = min(heights[left_top_idx[i - 1]], heights[left_top_idx[i]]);
            long long v = left_top_idx[i]-1 - left_top_idx[i - 1];
            res += h * v - sum_array[left_top_idx[i]-1] + sum_array[left_top_idx[i - 1]];
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    cin.get();
    while (T--)
    {
        int a;
        vector<int> heights;
        string s;
        getline(cin, s);
        istringstream iss(s);
        while (iss >> a)
        {
            heights.push_back(a);
        }
        cout << solution(heights) << '\n';
    }
    return 0;
}