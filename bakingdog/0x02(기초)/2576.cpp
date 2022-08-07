#include <bits/stdc++.h>
using namespace std;

int arr[7];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(arr, 100, sizeof(arr));
	int tmp, sum, mi;
	sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> tmp;
		if (tmp % 2 == 1) {
			sum += tmp;
			arr[i] = tmp;
		}
	}
	if (sum)
	{
		sort(arr, arr + 7);
		cout << sum << "\n" << arr[0];
	}
	else
		cout << "-1";
}