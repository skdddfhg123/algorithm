#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int> > q;

int board[101][101];
bool vis[101][101];
bool h[101];

vector<int> v;
int n, ret = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            h[tmp] = 1;
        }
    }

    for (int z = 0; z < 100; z++) {
        if (h[z]) {
            memset(vis, 0, sizeof(vis));
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] > z && !vis[i][j]) {
                        tmp++;
                        vis[i][j] = 1;
                        q.push({i, j});
                        while(!q.empty()) {
                            pair<int , int> cur = q.front();
                            q.pop();
                            for (int dir = 0; dir < 4; dir++) {
                                int nx = cur.X + dx[dir];
                                int ny = cur.Y + dy[dir];
                                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
                                if (!vis[nx][ny] && board[nx][ny] > z) {
                                    q.push({nx, ny});
                                    vis[nx][ny] = 1;
                                }
                            }
                        }
                    }
                }
            }
            ret = max(ret, tmp);
        }
    }
    cout << ret;
    return 0;
}