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
    // 为什么想到用层序遍历？
    //
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)  // 判空
            return {};
        vector<int> res;  // 存储右视图结点
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
                if (i == size - 1)  // 每一层最后一个结点
                    res.push_back(node->val);
            }
        }
        return res;
    }
};
// @leet end
