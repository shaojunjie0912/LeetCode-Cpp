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
    // 注意二叉树的 高度 不同于 深度！！！！
    // 深度：当前结点 到 根结点 的距离（前序遍历）
    // 高度：当前结点 到 最远叶结点 的距离（后序遍历）

    // 本题之所以前后序都可以是因为二叉树的最大深度就是根节点的高度
    // 本题求深度用前序反而不易理解
public:
#if 1
    // ---------------------  递归法 --------------------
    // 后序递归：用求高度求深度
    int maxDepth(TreeNode* root) {
        if (root == nullptr)  // 递归退出条件
            return 0;
        // 左
        int l_depth = maxDepth(root->left);  // 单层递归逻辑
        // 右
        int r_depth = maxDepth(root->right);
        // 根 depth = 1 + max(l_depth, r_depth)
        return max(l_depth, r_depth) + 1;  // 返回最大的+1
    }
#elif 0
    // 极简递归后序写法
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
#elif 0
    // 前序递归：正统求深度，但是很复杂
    int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result;  // 中

        if (node->left == NULL && node->right == NULL)
            return;

        if (node->left) {  // 左
            depth++;       // 深度+1
            getdepth(node->left, depth);
            depth--;  // 回溯，深度-1
        }
        if (node->right) {  // 右
            depth++;        // 深度+1
            getdepth(node->right, depth);
            depth--;  // 回溯，深度-1
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL)
            return result;
        getdepth(root, 1);
        return result;
    }

#else
    // ---------------------  迭代法 --------------------
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
