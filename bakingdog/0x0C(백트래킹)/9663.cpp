#include <bits/stdc++.h>

using namespace std;
bool board[16][16];
bool x_vis[16];
bool x_p_y_vis[31];
bool x_m_y_vis[31];
int N;
int cnt = 0;

void dfs(int y) {
	if (y == N) {
		cnt++;
		return ;
	}
	for (int x = 0; x < N; x++) {
		// y축 체크
		if (!x_vis[x] && !x_p_y_vis[x+y] && !x_m_y_vis[x-y + (N -1)]) {
			// cout << x-y << endl;
			x_vis[x] = true;
			x_p_y_vis[x+y] = true;
			x_m_y_vis[x-y +(N -1)] = true;
			dfs(y + 1);
			x_vis[x] = false;
			x_p_y_vis[x+y] = false;
			x_m_y_vis[x-y +(N -1)] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	dfs(0);
	cout << cnt << endl;
}
