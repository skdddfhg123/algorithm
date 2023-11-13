#include <bits/stdc++.h>

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string tmp = "";
        string ret = "";
        for (int i = 0; s[i] == ' ' && i < s.length(); i++) ;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (tmp != "") {
                    cout << tmp << i << '\n';
                    st.push(tmp);
                    tmp = "";
                }
                continue;
            }
            else 
                tmp += s[i];
        }
        if (tmp != "")
            st.push(tmp);
        while(!st.empty()) {
            ret += st.top();
            st.pop();
            if (!st.empty())
                ret += ' ';
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string s = "the sky is blue";
    cout << solution.reverseWords("  hello world  ");
}