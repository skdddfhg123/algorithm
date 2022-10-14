#include <bits/stdc++.h>

using namespace std;

bool vis[101];
bool check[101];
int N, cnt;
int from, to;
queue<int> q;
vector<int> v[101];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	cnt = 0;
	q.push(1);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (!vis[cur] && !v[cur].empty()) {
			vis[cur] = 1;
			
			for (int i = 0; i < v[cur].size(); i++) {
				q.push(v[cur][i]);
				if (!check[v[cur][i]]) {
					cnt++;
					check[v[cur][i]] = 1;
					// cout << v[cur][i] << '\n';
				}
			}
		}
	}
	cout << cnt - 1;
}