#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n;

bool vis[102][102];

int val1, val2; 

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0 ,-1, 0};

queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string board[n];
    
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                val1++;
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    // cout << "!!\n";
                    pair <int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
                        if (!vis[nx][ny] && board[nx][ny] == board[i][j]) {
                            // cout << "X = " << nx << "  Y = " << ny << '\n';
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                val2++;
                q.push({i, j});
                vis[i][j] = 1;
                while(!q.empty()) {
                    pair <int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue ;
                        if (!vis[nx][ny]) {
                            if ((board[i][j] == 'R' || board[i][j] == 'G') &&\
                            (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                                q.push({nx,ny});
                                vis[nx][ny] = 1;
                            }
                            else if (board[i][j] == 'B' && board[nx][ny] == 'B') {
                                q.push({nx,ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << val1 << ' ' << val2;
}