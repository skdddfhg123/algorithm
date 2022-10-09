#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int N, M, V;
int mat[MAX][MAX];
bool vis[MAX];

void dfs(int start, int max) {
	stack<int> s;

	s.push(start);
	while(!s.empty()) {
		int cur = s.top();
		s.pop();
		if (!vis[cur]) {
			vis[cur] = true;
			cout << cur << ' ';
			for (int i = max; i >= 1; i--) {
				if (mat[cur][i] == 1 && !vis[i])
					s.push(i);
			}
		}
	}
}

void bfs(int start, int max) {
	queue<int> q;

	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (!vis[cur]) {
			vis[cur] = true;
			cout << cur << ' ';
			for (int i = 1; i <= max; i++) {
				if (mat[cur][i] == 1 && !vis[i])
					q.push(i);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	dfs(V, N);
	cout << "\n";
	memset(vis, 0, sizeof(vis));
	bfs(V, N);
}
