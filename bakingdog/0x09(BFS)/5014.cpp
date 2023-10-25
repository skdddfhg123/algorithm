#include <bits/stdc++.h>

using namespace std;

// F : 건물 높이
// S : 현재 위치
// G : 가야할 층
// U : 한번에 올라가는 거리
// D : 한번에 내려가는 거리

int f,g,s,u,d,n;

queue<pair<int, int> > q;

bool vis[1000001];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    q.push({s, 0});
    vis[s] = 1;
    while (!q.empty()) {
        pair<int ,int> cur = q.front();
        q.pop();
        if (cur.first == g) {
            cout << cur.second;
            return 0;
        }
        // u
        if (cur.first + u <= f && !vis[cur.first + u]) {
            q.push({cur.first + u, cur.second + 1});
            vis[cur.first + u] = 1;
        }
        // d
        if (cur.first - d >= 1 && !vis[cur.first - d]) {
            q.push({cur.first - d, cur.second + 1});
            vis[cur.first - d] = 1;
        }
    }
    cout << "use the stairs";
}