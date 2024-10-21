#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
#if 1
        if (nums.size() < 2) {
            return nums.size();
        }
        int slow = 0;
        for (int fast = 1; fast < nums.size(); ++fast) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }
        return ++slow;
#else

        int slow = 1;
        int fast = 1;
        int val = nums[0];
        for (; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
                val = nums[fast];
            }
        }
        return slow;
#endif
    }
};
// @leet end
