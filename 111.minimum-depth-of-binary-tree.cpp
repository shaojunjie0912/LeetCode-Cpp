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
#if 1
    // 递归法
    int minDepth(TreeNode* root) {}
#else
    // 迭代法（层序遍历）
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int min_depth = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            ++min_depth;  // 记录最小深度
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
                // 左右子结点为空则为最小深度
                if (node->left == nullptr && node->right == nullptr)
                    return min_depth;
            }
        }
    }
#endif
};
// @leet end
