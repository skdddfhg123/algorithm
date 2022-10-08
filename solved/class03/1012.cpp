#include <bits/stdc++.h>

#define X first
#define Y second
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool board[51][51];
bool vis[51][51];

int num, M, N, K;
int x, y, res;

queue<pair<int, int> > q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> num;
	while (num--) {
		memset(board, 0, sizeof(board));
		memset(vis, 0, sizeof(vis));
		res = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] && !vis[i][j]) {
					q.push({i, j});
					vis[i][j] = 1;
					res++;
				}
				while(!q.empty()) {
					pair<int, int>cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx > M || ny > N)
							continue ;
						if (board[nx][ny] && !vis[nx][ny]) {
							vis[nx][ny] = 1;
							q.push({nx, ny});
						}
					}
				}
			}
		}
		cout << res << "\n";
	}
	return (0);
}

