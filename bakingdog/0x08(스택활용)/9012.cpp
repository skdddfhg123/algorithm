#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n, len;
    cin >> n;
    while (n--) {
        stack<char> s;
        bool check = false;
        string a;
        cin >> a;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '(') {
                if (s.empty() || s.top() == '(')
                    s.push(a[i]);
            } else {
                if (s.empty() || s.top() == ')') {
                    check = true;
                    break ;
                }
                else if (s.top() == '(')
                    s.pop();
            }
        }
        if (!check && s.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

// 10m