#include <bits/stdc++.h>

using namespace std;

bool vis[1000000001];

queue<pair<int, int> > q;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sec = 1000000001;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int>cur = q.front();
		q.pop();
        cout << cur.first << '\n';
		if (cur.first == n)
			sec = min(sec, cur.second);
        if ((cur.first * 2) <= 1000000001 && !vis[cur.first * 2]) {
			vis[cur.first * 2] = true;
			q.push(pair(cur.first * 2, cur.second));
		}
		if ((cur.first + 1) <= 1000000001 && !vis[cur.first + 1]) {
			vis[cur.first + 1] = true;
			q.push(pair(cur.first + 1, cur.second + 1));
		}
    }

}
