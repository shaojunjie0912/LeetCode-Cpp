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
    // ------------- 递归法 -------------
    // 比较左右子树内外侧元素是否相等
    bool compare(TreeNode* left, TreeNode* right) {
        // 终止条件
        // 子结点存在为空的情况
        if (left == nullptr && right != nullptr)  // 左空右不空
            return false;
        else if (left != nullptr && right == nullptr)  // 左不空右空
            return false;
        else if (left == nullptr && right == nullptr)  // 左右均空
            return true;
        // 子结点不为空的情况
        // 如果左右结点值不相等则返回 false
        // 这里不能把判断条件写满，不然递归到第一层即退出
        // 无法递归到底层
        else if (left->val != right->val)
            return false;
        // 以上情况都排除后，剩下就是左右结点不为空且数值相同的情况
        // 则可以做下一层判断
        // 若相等则一直往下递归，最后会遇到两侧均为空结点，此时返回true
        bool outside = compare(left->left, right->right);  // 比较二叉树外侧
        bool inside = compare(left->right, right->left);   // 比较二叉树内侧
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return compare(root->left, root->right);
    }
#else
    // ------------- 迭代法 -------------
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        queue<TreeNode*> nodes;
        nodes.push(root->left);
        nodes.push(root->right);
        while (!nodes.empty()) {
            TreeNode* left_node = nodes.front();   // 取左结点
            nodes.pop();                           // 弹出
            TreeNode* right_node = nodes.front();  // 取右节点
            nodes.pop();                           // 弹出
            // 左右结点均为空，执行下一次循环
            if (left_node == nullptr && right_node == nullptr)
                continue;  // !!!! 注意不是返回 true !!!!
            // 左右仅一为空或左右值不相等，返回 false
            if (left_node == nullptr || right_node == nullptr || left_node->val != right_node->val)
                return false;
            // 下一层外侧结点入队
            nodes.push(left_node->left);
            nodes.push(right_node->right);
            // 下一层内侧结点入队
            nodes.push(left_node->right);
            nodes.push(right_node->left);
        }
        // 经过循环后，所有结点均对称，则返回 true
        return true;
    }
#endif
};
// @leet end
