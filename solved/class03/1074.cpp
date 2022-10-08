#include <bits/stdc++.h>
using namespace std;
int res;
int N, r, c;

void dfs(int n, int r, int c, int b) {
	if (n == N) {
		cout << res << "\n";
	}
	else {
		if (r >= b && c >= b) {
			res += (b * b) * 3;
			dfs(n + 1, r - b, c - b, b / 2);
		}
		else if (r >= b && c < b) {
			res += (b * b) * 2;
			dfs(n + 1, r - b, c, b / 2);
		}
		else if (c >= b && r < b) {
			res += (b * b) * 1;
			dfs(n + 1, r, c - b, b / 2);
		}
		else if (c < b && r < b)
			dfs(n + 1, r, c, b / 2);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> r >> c;
	int b = 2;
	for (int i = 1; i < N; i++)
		b *= 2;
	dfs(0, r, c, b / 2);
}