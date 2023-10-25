#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n, len;
    int let = 0;
    cin >> n;
    while (n--) {
        stack<char> s;
        string a;
        cin >> a;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 'A') {
                if (s.empty() || s.top() == 'B') {
                    s.push(a[i]);
                }
                else if (s.top() == 'A') {
                    s.pop();
                }
            } else {
                if (s.empty() || s.top() == 'A') {
                    s.push(a[i]);
                }
                else if (s.top() == 'B')
                    s.pop();
            }
        }
        if (s.size() == 0)
            let++;
    }
    cout << let;
}

// 15m