#include <bits/stdc++.h>

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cmp = 0;
        for (int i = 0; i < t.length() && cmp < s.length(); i++) {
            if (s[cmp] == t[i]) {
                cmp++;
            }
        }
        if (cmp == s.length())
            return 1;
        return 0;
    }
};

int main() {
    Solution sol;
    cout << sol.isSubsequence("axc", "ahbgdc");
}