#include <bits/stdc++.h>

using namespace std;

int arr[10] = {};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ret = 1;
    cin >> n;
    while (n) {
        arr[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9)
            continue ;
        ret = max(ret, arr[i]);
    }
    ret = max(ret, (arr[6] + arr[9] + 1) / 2);
    cout << ret;
}