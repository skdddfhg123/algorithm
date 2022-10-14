#include <bits/stdc++.h>

using namespace std;

bool board[129][129];
int N, tmp, w_cnt, b_cnt;

bool check_all(int x, int y, int t) {
	bool tmp = board[x][y];
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++)
			if (tmp != board[i + x][j + y])
				return (false);
	}
	return (true);
}

void find(int x, int y, int n) {
	if (check_all(x, y, n)) {
		// cout << "x= " << x << " y=" << y << '\n';
		if (board[x][y])
			b_cnt++;
		else
			w_cnt++;
	}
	else {
		n /= 2;
		find(x, y, n);
		find(x + n, y, n);
		find(x, y + n, n);
		find(x + n, y + n, n);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	find(0, 0, N);
	cout << w_cnt << '\n' << b_cnt;
}