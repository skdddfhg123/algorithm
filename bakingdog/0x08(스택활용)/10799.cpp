#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    string c;
    stack<char> s;
    int let = 0;
    cin >> c;
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == '(')
            s.push(c[i]);
        else if (c[i - 1] == ')') {
            s.pop();
            let ++;
        }
        else {
            s.pop();
            let += s.size();
        }
    }
    cout << let;
}

// 12m
    
