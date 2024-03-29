#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[1001][1001];
int N, M;
int ret = 0;

queue<pair<int, int> >q;

void bfs (void) {
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue ;
            if (board[nx][ny] != 0)
                continue ;
            board[nx][ny] = board[cur.X][cur.Y] + 1;
            ret = max(ret, board[nx][ny]);
            q.push({nx,ny});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push({i, j});
        }
	}
	bfs();
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            // cout << board[i][j] << " ";
            ret = max(ret, board[i][j]);
        }
        // cout << "\n";
	}
	cout << ret - 1;
}