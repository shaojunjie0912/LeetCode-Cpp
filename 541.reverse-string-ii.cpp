#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    string reverseStr(string s, int k) {
#if 0
        // 垃圾第一版
        for (auto iter = s.begin(); iter != s.end(); iter += 2 * k) {
            auto dist = distance(iter, s.end());
            if (dist < k) {
                reverse(iter, s.end());
                break;
            }
            if (dist > k && dist < 2 * k) {
                reverse(iter, iter + k);
                break;
            }
            reverse(iter, iter + k);
        }
        return s;
#elif 1
        // 自己优化了一下
        auto iter = s.begin();
        while (iter <= s.end() - 2 * k) {
            reverse(iter, iter + k);
            iter += 2 * k;
        }
        auto dist = distance(iter, s.end());
        if (dist < k)
            reverse(iter, s.end());
        else
            reverse(iter, iter + k);
        return s;
#endif
    }
};
// @leet end
