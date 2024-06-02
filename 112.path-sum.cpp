#include <bits/stdc++.h>

#include "include/treenode.h"
using namespace std;

// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // ----------- 递归详细版 ---------
#if 1
    // 递归+回溯
    // 这里若采用累加判断是否等于目标和则代码会比较麻烦
    // 因此采用递减, count 是计数器，初始化为目标值
    // 每经过一条边则减去对应结点值
    // 最终如果当前结点为叶结点且 count 为 0，则满足条件
    bool traversal(TreeNode* cur, int count) {
        // 终止条件：遇到叶结点则判断当前计数器值并返回
        if (cur->left == nullptr && cur->right == nullptr) {
            // NOTE: 为什么不要减去当前结点值再判断
            // 因为单层递归逻辑中已经先减后加了

            // count -= cur->val;

            if (count == 0)
                return true;
            else
                return false;
        }
        // NOTE: 由于终止条件是叶结点，因此不能让空结点进入递归
        // 这点在很多递归+回溯题目中都有展现

        // 单层递归逻辑
        if (cur->left) {              // 左
            count -= cur->left->val;  // count 减去当前结点值
            if (traversal(cur->left, count))
                return true;
            count += cur->left->val;  // 回溯，撤销处理结果
        }
        if (cur->right) {              // 右
            count -= cur->right->val;  // 递归，处理节点;
            if (traversal(cur->right, count))
                return true;
            count += cur->right->val;  // 回溯，撤销处理结果
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        // TODO: 这里传入的为什么是 sum 减去根结点值?
        return traversal(root, sum - root->val);
    }
#elif 0
    // ------------ 递归精简版 ------------
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if (!root->left && !root->right && sum == root->val) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
#endif
};
// @leet end
