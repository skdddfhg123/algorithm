#include <bits/stdc++.h>

using namespace std;

char board[6562][6562];

void solv(int x, int y, int n) {
	if (1 == n) {
		board[x][y] = '*';
		return ;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue ;
				solv(x + n/3 * i, y + n/3 * j, n / 3);
				
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i]+n, ' ');
	solv(0, 0, n);

	for (int i = 0; i < n; i++)
    	cout << board[i] << '\n';
}
