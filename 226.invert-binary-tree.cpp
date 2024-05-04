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
    // -------------------- 递归法 ----------------------
#if 1
    // return 只为能退出递归，实际并未使用返回值
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;  // 这里的返回只是为了退出递归
        swap(root->left, root->right);
        invertTree(root->left);   // 实际上并未用到返回值
        invertTree(root->right);  // 实际上并未用到返回值
        return root;              // 最后返回根结点
    }
    // ------------- 迭代法（层/前/后序） -------------
#elif 0
    // 层序遍历法（用队列）（广度优先遍历）
    // 层序遍历每一个结点并交换其子结点
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> nodes;  // 结点队列，FIFO
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
#elif 0
    // 前序遍历（用栈）（深度优先遍历）（普通迭代法）
    // 前序遍历顺序：根 -> 左 -> 右
    // 入栈顺序：根 -> 右 -> 左
    // 虽然这里结点操作为交换子结点，但其实对前序遍历无影响
    // 遍历只需要按照根 左 右顺序即可，不在乎左右是什么
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode*> nodes;  // 结点栈，LIFO
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            swap(node->left, node->right);  // 交换左右子结点
            if (node->right != nullptr)
                nodes.push(node->right);  // 右子结点入栈
            if (node->left != nullptr)
                nodes.push(node->left);  // 左子结点入栈
        }
        return root;
    }
#elif 0
    // 后序遍历（用栈）（深度优先遍历）（统一迭代法）
    // 后序遍历顺序： 左 -> 右-> 根
    // 入栈顺序：根 -> 左 -> 右
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            if (node != nullptr) {
                nodes.pop();
                if (node->left != nullptr)
                    nodes.push(node->left);  // 左
                if (node->right != nullptr)
                    nodes.push(node->right);  // 右
                nodes.push(node);             // 中
                nodes.push(nullptr);          // null标记处理
            } else {
                nodes.pop();
                TreeNode* top = nodes.top();
                nodes.pop();
                swap(top->left, top->right);
            }
        }
        return root;
    }

#endif
};
// @leet end
