#include "bits/stdc++.h"
using namespace std;

stack<pair<int, int> >S;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num, height, same;
    long long ans = 0;
    cin >> num;
    while(num--) {
        cin >> height;
        same = 1;
        // MAX 갱신
        while(!S.empty() && S.top().first < height) {
            ans += S.top().second;
            S.pop();
        }
        // MAX 보다 작거나 같은 값
        if (!S.empty()) {
            if (S.top().first == height) {
                ans += S.top().second;
                same = S.top().second + 1;
                if (S.size() > 1)
                    ans++;
                S.pop();
            }
            else
                ans++;
        }
        S.push(make_pair(height, same));
    }
    cout << ans;
}
