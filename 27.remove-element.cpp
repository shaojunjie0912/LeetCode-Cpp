#include <bits/stdc++.h>
using namespace std;

// 双指针法

// 快指针：寻找新数组的元素
// 慢指针：指向更新新数组下标的位置

// @leet start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        for (; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        // NOTE: 这里是 slow 而不是 slow+1
        return slow;
    }
};
// @leet end
