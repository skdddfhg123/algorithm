#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fun1(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll val = fun1(a, b/2, c);
    if (b % 2 == 0) return val * val % c;
    return val * val % c * a % c;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << fun1(a, b, c);
}