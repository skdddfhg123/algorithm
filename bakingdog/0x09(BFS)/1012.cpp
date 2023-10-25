#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int board[51][51];
bool vis[51][51];

queue<pair<int, int> > q;

int num, n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    while (num--) {
        memset(board,0, sizeof(board));
        memset(vis,0, sizeof(vis));
        int ret = 0;
        cin >> n >> m >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[x][y] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    ret++;
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for(int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx > n || ny < 0 || ny > m) continue ;
                            if (board[nx][ny] && !vis[nx][ny]) {
                                q.push({nx, ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout << ret << '\n';
    }
}