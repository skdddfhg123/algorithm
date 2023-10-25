#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[10];
bool check[10];


void solv(int k) {
    if (m == k) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            arr[k] = i;
            check[i] = 1;
            solv(k + 1);
            check[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    solv(0);
}