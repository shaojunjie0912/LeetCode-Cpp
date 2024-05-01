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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
#if 0
    // 递归实现
    int maxDepth(TreeNode* root) {
    }
#else
    // 迭代实现
    // 使用二叉树的层序遍历
    int maxDepth(TreeNode* root) {
        if (root == nullptr)  // 经典判空
            return {};
        int depth = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            ++depth;  // while 循环每次判断为一层
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->left != nullptr) {
                    nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
            }
        }
        return depth;
    }
#endif
};
// @leet end
