#include <bits/stdc++.h>
using namespace std;

// @leet start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (char ch : ransomNote) {
            hash[ch - 'a']++;
        }
        for (char ch : magazine) {
            hash[ch - 'a']--;
        }
        for (int i : hash) {
            if (i > 0)
                return false;
        }
        return true;
    }
};
// @leet end
