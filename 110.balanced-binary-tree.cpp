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
    // 平衡二叉树
    // 一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1
    // 注意二叉树的 高度 不同于 深度！！！！
    // 深度：当前结点 到 根结点 的距离（前序遍历）
    // 高度：当前结点 到 叶结点 的距离（后序遍历）
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int left_depth = 0;
        int right_depth = 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while (left != nullptr) {
            left = left->left;
            ++left_depth;
        }
        while (right != nullptr) {
            right = right->right;
            ++right_depth;
        }
        if (std::abs(left_depth - right_depth) <= 1)
            return true;
        else
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @leet end
