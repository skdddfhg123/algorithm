#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    
    while (1) {
        string s;
        getline(cin, s);
        if (s == ".")
            break ;
        stack<char> st;
        bool isValid = true;
        for (auto c : s) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    isValid = false;
                    break ;
                }
                st.pop();
            } else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    isValid = false;
                    break ;
                }
                st.pop();
            }
        }
        if (!st.empty()) isValid = false;
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}

// 다시 풀어야 할 문제 
// 막힌 부분 : 문자열 읽는 부분 getline 익히기