#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unsigned long long a, b, diff;
	cin >> a >> b;
	if (a > b)
		swap(a,b);
	if (a == b || b - a == 1) {
		cout << "0\n";
		return (0);
	}
	diff = b - a - 1;
	cout << diff << "\n";
	for (long long i = a + 1; i < b; i++)
		cout << i << " ";
}