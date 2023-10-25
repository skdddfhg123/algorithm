#include <bits/stdc++.h>

using namespace std;

string board[65];
string ans;

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
		cout << board[x][y];
	else {
		n /= 2;
		cout << '(';
		solv(x, y, n);
		solv(x, y + n, n);
		solv(x + n,  y, n);
		solv(x + n, y + n, n);
		cout << ')';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	solv(0,0,n);
}
