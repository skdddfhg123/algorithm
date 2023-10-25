#include <bits/stdc++.h>

using namespace std;

bool check[2000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    fill(arr, arr + n, 0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        check[tmp] = 1;
    }
    int cmp;
    int ans = 0;
    cin >> cmp;
    for (int i = 0; i < n; i++) {
        if (cmp - arr[i] > 0 && check[cmp - arr[i]])
            ans++;
    }
    cout << ans / 2;
}

#include <bits/stdc++.h>

using namespace std;


// int arr[100001];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n, tmp, cmp, ans = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> tmp;
//         arr[i] = tmp;
//     }
//     cin >> cmp;
//     sort(arr, arr+n);
//     int p1 = 0 , p2 = n - 1;
//     while(p1 != p2) {
//         if (arr[p1] + arr[p2] > cmp)
//             p2 -= 1;
//         else if (arr[p1] + arr[p2] < cmp)
//             p1 += 1;
//         else if (arr[p1] + arr[p2] == cmp) {
//             ans += 1;
//             p1 += 1;
//         }
//     }
//     cout << ans;
// }
