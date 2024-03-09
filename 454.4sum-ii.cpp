#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        // key: a+b的和
        // value: 和出现的次数
        unordered_map<int, int> umap;
        // 遍历数组1和2，将两个数组元素之和 + 和出现的次数放到map中
        for (int a : nums1) {
            for (int b : nums2) {
                umap[a + b]++;
            }
        }

        // 统计 a+b+c+d=0 出现的次数
        int count = 0;
        // 遍历数组3和4，如果 0-(c+d) 在 map 中出现过
        // 则统计 map 中 key 对应的 value(出现次数)
        for (int c : nums3) {
            for (int d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }

        return count;
    }
};
// @leet end
