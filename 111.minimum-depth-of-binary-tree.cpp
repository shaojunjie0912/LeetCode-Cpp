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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l_min_depth = minDepth(root->left);
        int r_min_depth = minDepth(root->right);

        // ------------ 关键 -------------
        // 如果左子树为空，只有右子树，那么最小深度是右子树的深度
        if (root->left == nullptr && root->right != nullptr)
            return 1 + r_min_depth;
        // 如果右子树为空，只有左子树，那么最小深度是左子树的深度
        else if (root->left != nullptr && root->right == nullptr)
            return 1 + l_min_depth;
        // 如果左右子树都不为空，则最小深度是左右子树最小深度
        else
            return 1 + min(l_min_depth, r_min_depth);
    }
#else
    // 迭代法（层序遍历）
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int min_depth = 0;
        queue<TreeNode*> nodes;  // 层序遍历用队列 FIFO
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();  // 该层结点数
            ++min_depth;                 // 最小深度++
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                // 左右子结点非空则入队，正常做法
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
                // ----- 关键 -----
                // 因为遍历每层结点，因此当
                // 当前访问的结点的左右子结点为空则为最小深度
                if (node->left == nullptr && node->right == nullptr)
                    return min_depth;
            }
        }
    }
#endif
};
// @leet end
