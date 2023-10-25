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

// #include <bits/stdc++.h>

// using namespace std;

// int check[13] = {};

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, k, ans = 0;
//     cin >> n >> k;
//     int s, g;
//     while (n--) {
//         cin >> s >> g;
//         if (s)
//             check[g + 6]++;
//         else
//             check[g]++;
//     }
//     for (int i = 1; i < 13; i++) {
//         if (check[i]) {
//             if (check[i] % k == 0)
//                 ans += (check[i] / k);
//             else if (check[i] > k)
//                 ans += (check[i] / k) + 1;
//             else
//                 ans++;
//         }
//     }
//     cout << ans;
// }
