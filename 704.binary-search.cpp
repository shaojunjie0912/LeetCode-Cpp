#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    // WARN: 发生过 size_t 运行报错，建议 int
#if 1
    // [left, right) 左闭右开区间
    int search(vector<int> &nums, int target) {
        int left = 0;
        // NOTE: 右边是开区间
        int right = nums.size();
        // NOTE: 闭区间 left==right 无意义
        while (left < right) {
            int middle{left + (right - left) / 2};
            if (nums[middle] > target) {
                right = middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
#else
    // [left, right] 闭区间
    int search(vector<int> &nums, int target) {
        int left = 0;
        // NOTE: 右边是闭区间
        int right = nums.size() - 1;
        // NOTE: 闭区间 left==right 有意义
        while (left <= right) {
            // 防止left+right直接溢出
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
#endif
};
// @leet end
