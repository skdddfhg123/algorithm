#include <bits/stdc++.h>

using namespace std;

int ans[3];

int N;
int board[2188][2188];

bool same_find(int x, int y, int n) {
	int tmp = board[y][x];
	if (n == 1)
		return (true);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[y + j][x + i] != tmp)
				return (false);
	return (true);
}

void find(int x, int y, int n) {
	if (same_find(x, y, n)) {
		ans[board[y][x] + 1]++;
	}
	else {
		n /= 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				find(x + j * n, y + i * n, n);
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	for (int i =0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[j][i];
	find(0, 0, N);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}