#include <bits/stdc++.h>
using namespace std;

// 两层 for 循环(与三数之和为0中的 i left right 不同)
// 与三数之和为0中的剪枝操作(if nums[i]>target=0 break)不同
// 这里 target 可能是负数，因此需要修改剪枝逻辑

// @leet start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 两层 for 循环
        for (int k = 0; k < nums.size(); ++k) {
            // 第一层剪枝
            if (nums[k] >= 0 && nums[k] > target)
                break;
            // 对 nums[k] 去重
            if (k > 0 && nums[k] == nums[k - 1])
                continue;
            for (int i = k + 1; i < nums.size(); ++i) {
                // 第二层剪枝
                if (nums[k] + nums[i] > 0 && nums[k] + nums[i] > target)
                    break;
                // 对 nums[i] 去重
                // 注意这里是i>k+1而不是i>0
                // 因为i必须在k后
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;  // 第一次没绕过来，sum大了的确应该左移right
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;  // sum小了的确应该右移left，不管你target正负
                    else {
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        // 对 nums[left] 和 nums[right] 去重
                        while (left < right && nums[left] == nums[left + 1])
                            ++left;
                        while (left < right && nums[right] == nums[right - 1])
                            --right;
                        ++left;
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
// @leet end
