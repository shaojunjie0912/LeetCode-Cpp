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
    // 高度：当前结点 到 最远叶结点 的距离（后序遍历）
public:
    // 定义一个根据高度判断平衡二叉树的递归函数
    // 后序递归计算高度
    int getHeight(TreeNode* root) {
        if (root == nullptr)  // 空结点高度为 0
            return 0;
        int left_height = getHeight(root->left);  // 左-----------
        if (left_height == -1)                    // 一定要判断，否则都是 -1 无法判错
            return -1;                            // 左子树不平衡则提前退出
        int right_height = getHeight(root->right);  // 右---------
        if (right_height == -1)  // 一定要判断，否则都是 -1 无法判错
            return -1;           // 右子树不平衡则提前退出

        // 标记是否是二叉平衡树(-1 or height)
        // 若不是则返回 -1，不需要返回高度
        // 若是，则返回以当前结点为根节点的二叉树高度
        // 高度是 1 + 左右子树高度最大的
        if (abs(left_height - right_height) > 1)  // 根----------
            return -1;
        else
            return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
// @leet end
