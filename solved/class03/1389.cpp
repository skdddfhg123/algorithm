#include <bits/stdc++.h>

using namespace std;

int mat[101][101];
int N, M, first, second;
int z = 1000000000;
vector<int> a[101];
queue<int> q;
bool vis[101];

int find(int n, int max) {
	int ret = 0;
	memset(vis, 0, sizeof(vis));
	q.push(n);
	vis[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < a[cur].size(); i++) {
			int index = a[cur][i];
			if (!vis[index]) {
				vis[index] = 1;
				q.push(index);
				mat[index][n] = mat[cur][n] + 1;
				mat[n][index] = mat[n][cur] + 1;
			}
		}
	}
	for (int i = 1; i <= max; i++) {
		ret += mat[n][i];
	}
	return (ret);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		a[first].push_back(second);
		a[second].push_back(first);
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int ret = find(i, N);
		if (ret < z) {
			z = ret;
			res = i;
		}
	}
	cout << res;
	return (0);
}