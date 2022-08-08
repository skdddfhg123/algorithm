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