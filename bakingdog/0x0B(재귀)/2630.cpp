#include <bits/stdc++.h>

using namespace std;

bool board[129][129];
int ans[2];

bool same_check(int x, int y, int n) {
	if (n == 1)
		return 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[x][y] != board[x + i][y + j])
				return 0;
	return 1;
}

void solv(int x, int y, int n) {
	if (same_check(x, y, n))
		ans[board[x][y]]++;
	else {
		n /= 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				solv(x + i * n, y + j * n, n);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solv(0,0,n);
	cout << ans[0] << '\n' << ans[1];

}