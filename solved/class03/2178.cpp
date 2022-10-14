#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool board[101][101];
int vis[101][101];
int N, M;

queue<pair<int, int> >q;

void bfs (void) {
	q.push(pair(0, 0));
	vis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		int ct = vis[cur.X][cur.Y];
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			int nt = ct + 1;
			if (nx < 0 || ny < 0 || nx > N || ny > M)
				continue ;
			if (board[nx][ny] && (!vis[nx][ny] ||vis[nx][ny] > nt)) {
				q.push(pair(nx, ny));
				vis[nx][ny] = nt;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
			board[i][j] = tmp[j] - '0';
	}
	bfs();
	cout << vis[N -1][M -1];
}