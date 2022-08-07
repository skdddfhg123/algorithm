#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ret;
	int arr[3];
	ret = 0;
	cin >> arr[0] >> arr[1] >> arr[2];
	if ((arr[0] == arr[1]) && (arr[1] == arr[2]))
		ret = (arr[0] * 1000) + 10000;
	else if (arr[0] == arr[1] || arr[0] == arr[2])
		ret = (arr[0] * 100) + 1000;
	else if (arr[1] == arr[2])
		ret = (arr[1] * 100) + 1000;
	else {
		ret = max(arr[0], arr[1]);
		ret = max(ret, arr[2]) * 100;
	}
	cout << ret;
}