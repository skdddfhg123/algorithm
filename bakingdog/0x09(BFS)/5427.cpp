#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int num, n, m;

int f_board[1001][1001];
int r_board[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    while(num--) {
        memset(f_board, 0, sizeof(f_board));
        memset(r_board, 0, sizeof(r_board));
        queue<pair<int, int> > f_q;
        queue<pair<int, int> > r_q;
        cin >> n >> m;
        string board[m];
        for (int i = 0; i < m; i++) {
            cin >> board[i];
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    f_q.push({i, j});
                    f_board[i][j] = 1;
                }
                else if (board[i][j] == '@') {
                    r_q.push({i, j});
                    r_board[i][j] = 1;
                }
                else if (board[i][j] == '#') {
                    f_board[i][j] = -1;
                    r_board[i][j] = -1;
                }
            }
        }
        while(!f_q.empty()) {
            pair <int ,int> cur = f_q.front();
            f_q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue ;
                if (f_board[nx][ny] == 0) {
                    f_q.push({nx, ny});
                    f_board[nx][ny] = f_board[cur.X][cur.Y] + 1;
                }
            }
        }
        int ret = 1000000000;
        while(!r_q.empty()) {
            pair <int ,int> cur = r_q.front();
            if (cur.X == 0 || cur.Y == 0 || cur.X == m - 1 || cur.Y == n - 1) {
                int val = r_board[cur.X][cur.Y];
                ret = min(ret, val);
            }
            r_q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue ;
                if (r_board[nx][ny] == 0 && (r_board[cur.X][cur.Y] + 1 < f_board[nx][ny] || f_board[nx][ny] == 0)) {
                    r_q.push({nx, ny});
                    r_board[nx][ny] = r_board[cur.X][cur.Y] + 1;
                }
            }
        }
        if (ret == 1000000000)
            cout << "IMPOSSIBLE\n";
        else
            cout << ret << '\n';
    }
}