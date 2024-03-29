#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            cin >> v;
            q.push(v);
        }
        else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << "-1\n";
        }
        else if (s == "size")
            cout << q.size() << '\n';
        else if (s == "empty") {
            cout << q.empty() << '\n';
        }
        else if (s == "front") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';
        }
        else if (s == "back") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }
}