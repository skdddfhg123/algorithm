#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int cmp = 0;
        int p1 = 0;
        int p2 = height.size() - 1;
        bool move_f = 0;
        while (p1 < p2) {
            int m = min(height[p1], height[p2]);
            if (m == height[p1])
                move_f = 1;
            else
                move_f = 0;
            ans = max(ans, m * (p2 - p1));
            cout << m * (p2 - p1) << '\n';
            if (move_f)
                p1++;
            else
                p2--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {2,3,4,5,18,17,6};
    cout << sol.maxArea(height);
}

