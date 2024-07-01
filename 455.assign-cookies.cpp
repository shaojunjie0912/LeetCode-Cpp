#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
    // 贪心算法
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child_num = 0;
        int cookie_id = s.size() - 1;
        // 从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 这里从大到小，循环判断语句是>=
        for (int child_id = g.size() - 1; child_id >= 0; --child_id) {
            // 神金，饼干🍪可能是空的
            if (cookie_id >= 0 && s[cookie_id] >= g[child_id]) {
                ++child_num;
                --cookie_id;
            }
        }
        return child_num;
    }
};
// @leet end
