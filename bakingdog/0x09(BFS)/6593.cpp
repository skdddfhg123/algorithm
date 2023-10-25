#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;
char board[31][31][31];
int vis[31][31][31];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int L, R, C;
int z, x, y;
int res = 0;
queue<tuple<int, int, int> >q;

int bfs(void) {
	while(!q.empty()) {
		z = get<0>(q.front());
		x = get<1>(q.front());
		y = get<2>(q.front());
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = z + dz[dir];
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nz < 0 || nx < 0 || ny < 0 || nz >= L || nx >= R || ny >= C)
				continue ;
			if (board[nz][nx][ny] == 'E')
				return (vis[z][x][y]);
			if (board[nz][nx][ny] == '.' && !vis[nz][nx][ny]) {
				vis[nz][nx][ny] = vis[z][x][y] + 1;
				q.push({nz, nx, ny});
			}
		}
	}
	return (0);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> R >> C;
	while (L) {
		memset(board, 0, sizeof(board));
		memset(vis, 0, sizeof(vis));
		while (!q.empty())
			q.pop();
		for (int a = 0; a < L; a++)
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++) {
					cin >> board[a][i][j];
					if (board[a][i][j] == 'S'){
						vis[a][i][j] = 1;
						q.push({a, i, j});
					}
				}

		res = bfs();

		if (res == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << res << " minute(s).\n";
		cin >> L >> R >> C;
	}
	
}