#include <bits/stdc++.h>

using namespace std;

int dp[301] = {};

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, tmp;
	cin >> n;
	int ar[n];
	memset(ar, 0, sizeof(ar));
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	dp[0] = 0;
	dp[1] = ar[1];
	dp[2] = ar[1] + ar[2];
	for (int i = 3; i <= n; i++)
		dp[i] = max(ar[i - 1] + ar[i] + dp[i - 3], dp[i - 2] + ar[i]);
	cout << dp[n] << '\n';
	return (0);
}