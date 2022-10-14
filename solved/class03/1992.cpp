#include <bits/stdc++.h>
using namespace std;
int N;
string s;
bool board[64][64];
bool white, black;
int is_onecolor(int n, int x, int y) {
	if (n == 1) {
		cout << board[y][x];
		white = false;
		black = false;
		return (1);
	}
	white = true;
	black = true;
	for (int i = y; i < y + n; i++)
		for (int j = x; j < x + n; j++)
			if (board[i][j]) 
				white = false;
			else
				black = false;
	if (white || black)
		return (1);
	return (0);
}

void recur(int n, int x, int y) {
	if (is_onecolor(n, x, y)) {
		if (white)
			cout << 0;
		else if (black)
			cout << 1;
		return ;
	}
	else {
		n /= 2;
		cout << "(";
		recur(n, x, y);
		recur(n, x + n, y);
		recur(n, x, y + n);
		recur(n, x + n, y + n);
		cout << ")";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '1')
				board[i][j] = 1;
			else
				board[i][j] = 0;
		}
	}
	recur(N, 0, 0);
}
