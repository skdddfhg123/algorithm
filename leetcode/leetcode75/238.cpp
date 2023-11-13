#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int leftProduct = 1;
        int rightProduct = 1;

       // 왼쪽 곱 계산
        for (int i = 0; i < n; i++) {
            result[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        // 오른쪽 곱 계산
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = {1, 2, 3, 4};
    vector<int> v = sol.productExceptSelf(a);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ',';
    }
    return 0;
}
