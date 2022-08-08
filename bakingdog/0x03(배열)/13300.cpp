#include <bits/stdc++.h>

using namespace std;

int arr[201];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp + 100]++;
    }
    int x;
    cin >> x;
    cout << arr[x + 100];
}