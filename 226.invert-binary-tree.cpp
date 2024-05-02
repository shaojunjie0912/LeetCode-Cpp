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
#if 0
    // 递归法
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;  // 这里的返回只是为了退出递归
        swap(root->left, root->right);
        invertTree(root->left);   // 实际上并未用到返回值
        invertTree(root->right);  // 实际上并未用到返回值
        return root;              // 最后返回根结点
    }
#elif 0
    // 层序遍历法（广度优先遍历）
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);  // 交换子结点
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
        }
        return root;
    }
#elif 1
    TreeNode* invertTree(TreeNode* root) {}

#endif
};
// @leet end
