#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    stack<pair<int, int> > S;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      int idx = i;
      while (!S.empty() && S.top().X >= h) {
        ans = max(ans, 1LL * (i - S.top().Y) * S.top().X);
        cout <<  "X = " << S.top().X << "  Y = " << i - S.top().Y << '\n';
        cout << "pop = " << ans << '\n';
        idx = S.top().Y;
        S.pop();
      }
      cout << "push h = " << h << "  i = " << i << '\n';
      S.push(make_pair(h, idx));
    }
    while (!S.empty()) {
      ans = max(ans, 1LL * (n - S.top().Y) * S.top().X);
        cout <<  "  X = " << S.top().X << "  Y = " << S.top().Y << '\n';
      cout << "pop = " << ans << '\n';
      S.pop();
    }
    cout << ans << '\n';
  }
}