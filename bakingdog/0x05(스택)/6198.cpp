#include "bits/stdc++.h"

using namespace std;

int n;
long long h, ans;
stack<int> s;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
}