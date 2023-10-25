#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0 ,0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int n, m , h;

int board[101][101][101];

struct str {
    int x;
    int y;
    int z;
};

queue<str> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < n; z++) {
                cin >> board[i][j][z];
                if (board[i][j][z] == 1) {
                    q.push({i, j, z});
                }
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= m || nz >= n) continue ;
            if (board[nx][ny][nz] != 0) continue ;
            q.push({nx, ny, nz});
            board[nx][ny][nz] = board[x][y][z] + 1;
        }
    }
    int ret = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < n; z++) {
                if (board[i][j][z] == 0) {
                    cout << "-1";
                    return 0;
                }
                ret = max(ret, board[i][j][z]);
            }
        }
    }
    cout << ret - 1;
}