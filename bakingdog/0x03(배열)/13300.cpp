#include <bits/stdc++.h>

using namespace std;

int arr[2][7];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b]++;
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            ans += arr[i][j] / k;
            if (arr[i][j] % k)
                ans++;
        }
    }
    cout << ans;
}