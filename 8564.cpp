#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> adj_list[1001];
int sub_sum[1001];

int n;

void dfs(int node) {
	visited[node] = true;
	for (auto near : adj_list[node]) {
		if (!visited[near]) {
			dfs(near);
			sub_sum[node] += sub_sum[near];
		}
	}
	sub_sum[node] += 1;
	return;
}

int main() {
	int i, a, b;
	cin >> n;
	for (i = 1; i < n; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	dfs(1);
	int res = 0;
	for (i = 1; i <= n; i++) {
		res = max(res, (sub_sum[i] * (n - sub_sum[i])));
	}
	cout << res << endl;
	return 0;
}
