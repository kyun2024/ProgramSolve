#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

int adj[1001][1001];
int p[1001];

int main() {
	int i, j;
	int a, b;
	queue<int> q;
	cin >> N >> M;
	for (i = 1; i <= N; i++)p[i] = i;
	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		adj[a][b] = adj[b][a] = true;
	}
	for (i = 1; i <= N; i++)p[i] = i;
	for (i = 1; i <= N; i++) {
		if (p[i] < i) {
			continue;
		}
		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			for (j = 1; j <= N; j++) {
				if (adj[x][j] && p[j] != i) {
					p[j] = i;
					q.push(j);
				}
			}
			q.pop();
		}
	}
	int c = 1;
	sort(p + 1, p + N + 1);
	for (i = 2; i <= N; i++) {
		if (p[i] != p[i - 1])c++;
	}
	cout << c << endl;
	return 0;
}