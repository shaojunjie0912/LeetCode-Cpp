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
    // ------------------ 完全二叉树思路 --------------------
    // 递归完全二叉树的左右子树后一定是满二叉树
    // 满二叉树的结点数量为 2^层数-1
    int countNodes(TreeNode* root) {
        // 这是递归终止条件之一
        // 1. 如果直接输入空结点（当然这应该不可能）
        // 2. 递归左右子结点到最后就为空
        if (root == nullptr)
            return 0;

        // 在完全二叉树的前提下，如何判断是否是满二叉树？
        // 从根结点出发，左递归与右递归深度相等即为满二叉树
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int left_depth = 0;  // 初始化为 0 方便指数运算
        int right_depth = 0;
        while (left != nullptr) {
            left = left->left;
            ++left_depth;
        }
        while (right != nullptr) {
            right = right->right;
            ++right_depth;
        }

        // 这是递归终止条件之二 ???
        // 若是满二叉树（其实这里递归下去一定满足）
        // 则返回结点数量为 2^层数-1
        if (left_depth == right_depth)
            return (2 << left_depth) - 1;  // 左移位运算 2<<0 即2的1次方

        // 1 是加上根结点
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
#else
#if 1
    // ------------------ 普通二叉树思路 --------------------
    // 递归法
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l_nodes = countNodes(root->left);
        int r_nodes = countNodes(root->right);
        return 1 + l_nodes + r_nodes;
    }
#else
    // 迭代法（层序遍历）
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int num_nodes = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            num_nodes += size;  // 加上每一层结点数量
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
        }
        return num_nodes;
    }
#endif
#endif
};
// @leet end
