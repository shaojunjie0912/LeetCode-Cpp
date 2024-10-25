#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int begin = 0;
        int end = nums.size() - 1;
        int idx = res.size() - 1;
        while (begin <= end) {
            auto pow_begin = nums[begin] * nums[begin];
            auto pow_end = nums[end] * nums[end];
            if (pow_begin > pow_end) {
                res[idx--] = pow_begin;
                ++begin;
            } else {
                res[idx--] = pow_end;
                --end;
            }
        }
        return res;
    }
};
// @leet end
