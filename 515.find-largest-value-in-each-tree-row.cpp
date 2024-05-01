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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> nodes;
        vector<int> res;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            int max = nodes.front()->val;  // 将最大值设置为每层首结点值
            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (node->val > max)
                    max = node->val;
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
// @leet end
