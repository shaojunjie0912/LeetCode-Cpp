#include <bits/stdc++.h>
using namespace std;

// 双指针法 + swap 库函数（不能直接用reverse）
// @leet start
class Solution {
public:
    void reverseString(vector<char>& s) {
#if 0
        for (int left = 0, right = s.size() - 1; left < s.size() / 2; ++left, --right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
#endif

#if 1
        // 调用库函数
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j) {
            swap(s[i], s[j]);
        }
#endif
    }
};
// @leet end
