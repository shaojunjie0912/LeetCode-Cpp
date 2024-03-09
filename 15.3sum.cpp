#include <bits/stdc++.h>
using namespace std;

// @leet start
// 双指针法
// nums[0] nums[1] ... nums[size-1]
//  |       |            |
//  i      left        right
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // 对数组进行排序
        sort(nums.begin(), nums.end());

        // nums[i] + nums[left] + nums[right] = 0
        for (int i = 0; i < nums.size(); ++i) {
            // 如果第一个数就大于0，则三数之和不可能等于0
            if (nums[i] > 0)
                break;
            // 对第一个数 nums[i] 去重
            // 注意：比较 nums[i] 和 nums[i-1] 而不是 nums[i+1]
            // 否则 -1 -1 2 无法处理
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            // 注意：循环终止条件
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                    --right;
                else if (sum < 0)
                    ++left;
                else {
                    // 注意：找到一个三元组后再去重
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 对第二个元素 nums[left] 去重
                    while (left < right && nums[left + 1] == nums[left])
                        ++left;
                    // 对第三个元素 nums[right] 去重
                    while (left < right && nums[right - 1] == nums[right])
                        --right;
                    // 注意：找到三元组后再更新 left 和 right
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};
// @leet end
