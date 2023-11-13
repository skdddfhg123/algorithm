#include <bits/stdc++.h>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = max(word1.length(), word2.length());
        string ret = "";
        for (int i = 0; i < len; i++) {
            if (i < word1.length())
                ret += word1[i];
            if (i < word2.length())
                ret += word2[i];
        }
        return ret;
    }
};