#include <bits/stdc++.h>

class Solution {
public:
    char checkLarge(char a) {
        if (a >= 'A' && a <= 'Z')
            return a + 32;
        else
            return a;
    }

    bool checkAlphabet(char a) {
        if ((a >= 'a' && a <= 'z') || \
        a >= '0' && a <= '9') {
            return 1;
        }
        return 0;
    }

    bool isPalindrome(string s) {
        string cmp = "";
        for (int i = 0; i < s.length(); i++) {
            char a = checkLarge(s[i]);
            if (checkAlphabet(a)) {
                cmp.append(1, a);
            }
        }
        int en = cmp.size() - 1;
        if (cmp == "")
            return 1;
        for (int st = 0; st <= en; st++, en-- ) {
            if (cmp[st] != cmp[en])
                return 0;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("0P");
}