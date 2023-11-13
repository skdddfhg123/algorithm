#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int p1 = 0;
        int p2 = numbers.size() - 1;
        while (p1 < p2) {
            if (numbers[p1] + numbers[p2] == target) {
                answer.push_back(p1 + 1);
                answer.push_back(p2 + 1);
                return answer;
            }
            if (numbers[p1] + numbers[p2] < target ) {
                // cout << "p1++ / " << numbers[p1] + numbers[p2] << '\n';
                p1++;
            }
            else if (numbers[p1] + numbers[p2] > target) {
                // cout << "p2-- / " << numbers[p1] + numbers[p2] << '\n';
                p2--;
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {2,7,11,15};
    vector<int> a = sol.twoSum(numbers, 9);
    for (auto num: a) {
        cout << num << ',';
    }
}