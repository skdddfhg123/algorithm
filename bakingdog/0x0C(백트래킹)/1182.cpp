#include <bits/stdc++.h>

using namespace std;

int arr[30];
int N, S;
// bool check[20000001];
int cnt = 0;

void solv(int c, int n) {
	if (c == N) {
		if (n ==S)
			cnt++;
		return ;
	}
	solv(c + 1, n);
	solv(c + 1, n + arr[c]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
	solv(0, 0);
	if (S == 0)
		cnt--;
	cout << cnt << endl;
}

