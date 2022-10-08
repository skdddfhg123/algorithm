#include <bits/stdc++.h>
using namespace std;
int num = 100;
int res;
bool check[10];
int n;

bool check_num(int i) {
	string a = to_string(i);
	if (i == 0) {
		if (check[0])
			return (false);
		else
			return (true);
	}
	for (int j = 0; j < a.length(); j++) {
			if (check[a[j] - '0']) {
				return (false);
			}
	}
	return (true);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, cnt, goal;
	cin >> goal >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		check[a] = true;
	}
	res = abs(goal - 100);
	for (int i = 0; i < 1000000; i++) {
		//못쓰는 숫자 들어있는지 확인하는 함수
		string a = to_string(i);
		if (check_num(i)) {
			cnt = abs(i - goal) + a.length();
			res = min(res, cnt);
		}
	}
	cout << res << "\n";
}