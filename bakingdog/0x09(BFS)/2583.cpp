#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool board[101][101];
bool vis[101][101];

queue<pair<int ,int> > q;
vector<int> v;

int n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for ( ; x1 < x2; x1++) {
            for (int i = y1 ; i < y2; i++) {
                board[i][x1] = 1;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 && !vis[i][j]) {
                int s = 1;
                ret++;
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    pair<int ,int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue ;
                        if (!vis[nx][ny] && board[nx][ny] == 0) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                            s++;
                        }
                    }
                }
                v.push_back(s);
            }
        }
    }
    cout << ret << '\n';
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
}