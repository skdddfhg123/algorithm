#include <bits/stdc++.h>
using namespace std;

queue<int> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans, tmp;
    cin >> n;
    for (int i = 1; i <= n; i++)
        Q.push(i);
    while(1) {
        if (Q.size() == 1) {
            cout << Q.front();
            return 0;
        }
        Q.pop();
        if (Q.size() == 1) {
            cout << Q.front();
            return 0;
        }
        tmp = Q.front();
        Q.pop();
        Q.push(tmp);
    }
}