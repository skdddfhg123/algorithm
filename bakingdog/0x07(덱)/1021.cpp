#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, v, ans = 0;
    bool r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    while (m--) {
        cin >> v;
        int idx = find(dq.begin(), dq.end(), v) - dq.begin();
        while (dq.front() != v) {
            if (idx < dq.size() - idx) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans+=1;
        }
        dq.pop_front();
    }
    cout << ans;
}