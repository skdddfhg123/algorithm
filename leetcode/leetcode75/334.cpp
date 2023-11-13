#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        stack<int> s;

        for (int cur = n - 1; cur >= 0; cur--) {
            while (!s.empty() && s.top() <= nums[cur]) {
                s.pop();
            }
            if (!s.empty()) {
                arr[cur] = s.top();
            }
            s.push(nums[cur]);
        }

        int cmp = arr[0];
        int flag = 0;
        for (auto num : arr) {
            cout << num << ',';
            if (cmp < num) {
                flag++;
                if (flag == 2)
                    return true;
            } else if (cmp > num) {
                flag = 0;
            }
            cmp = num;
        }
        return false;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,1,5,0,4,6};
    cout << sol.increasingTriplet(nums);
}