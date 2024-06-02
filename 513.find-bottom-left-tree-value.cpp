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
    // ---------- 傻瓜层序遍历 ----------
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int result;
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                if (i == 0)  // 该行第一个结点就是最左侧结点
                    result = node->val;
                nodes.pop();
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
        }
        return result;
    }
#else
    // ----------- 前/中/后序递归+回溯 ------------
    // 此处采用前序递归但是没有写中的逻辑
    // 只写了左右，因为这里中不需要写逻辑？
    int maxDepth = INT_MIN;
    int result;
    // 最后一层：深度最大
    void traversal(TreeNode* root, int depth) {
        // -------- 递归终止条件 ---------
        // 判断是否是叶结点
        if (root->left == NULL && root->right == NULL) {
            // 这里很奇妙，depth突然出现，所以要以形参传入
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        // ------------ 单层递归逻辑 ----------
        // 这里对左结点判空
        if (root->left != nullptr) {
            depth++;
            traversal(root->left, depth);
            depth--;  // 回溯
        }
        // 这里对右结点判空
        if (root->right != nullptr) {
            depth++;
            traversal(root->right, depth);
            depth--;  // 回溯
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
#endif
};
// @leet end
