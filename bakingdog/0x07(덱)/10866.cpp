#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            cin >> v;
            dq.push_front(v);
        }
        else if (s == "push_back") {
            cin >> v;
            dq.push_back(v);
        }
        else if (s == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
                cout << "-1\n";
        }
        else if (s == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
                cout << "-1\n";
        }
        else if (s == "size")
            cout << dq.size() << '\n';
        else if (s == "empty") {
            cout << dq.empty() << '\n';
        }
        else if (s == "front") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.front() << '\n';
        }
        else if (s == "back") {
            if (dq.empty())
                cout << -1 << '\n';
            else
                cout << dq.back() << '\n';
        }
    }
}