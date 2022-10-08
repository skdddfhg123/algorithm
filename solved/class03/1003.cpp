#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int cnt;
	cin >> cnt;
	int dp[43] = {0, 1, 1};
	for (int i = 2; i < 41; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	for (int i = 0; i < cnt; i++) {
		int n;
		cin >> n;
		if (n == 0)
			cout << "1 0\n";
		else
			cout << dp[n - 1] << " " << dp[n] << "\n";
	}
	return (0);
}