#include <bits/stdc++.h>

using namespace std;

int N, K;

bool vis[100001];
queue<pair <int ,int> > q;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	int sec = 100000;
	q.push(pair(N, 0));
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		if (cur.first == K)
			sec = min(sec, cur.second);
		if ((cur.first * 2) <= 100000 && !vis[cur.first * 2]) {
			vis[cur.first * 2] = true;
			q.push(pair(cur.first * 2, cur.second + 1));
		}
		if ((cur.first - 1) >= 0 && !vis[cur.first - 1]) {
			vis[cur.first - 1] = true;
			q.push(pair(cur.first - 1, cur.second + 1));
		}
		if ((cur.first + 1) <= 100000 && !vis[cur.first + 1]) {
			vis[cur.first + 1] = true;
			q.push(pair(cur.first + 1, cur.second + 1));
		}
	}
	cout << sec;
}