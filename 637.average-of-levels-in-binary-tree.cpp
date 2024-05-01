#include <bits/stdc++.h>

#include "treenode.h"
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr)  // ！！！一定要先判空！！！
            return {};
        vector<double> res;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();  // 队列 size 即该层结点数，由于会动态变化因此必须固定
            double sum = 0.0;                    // 该层结点值之和
            for (size_t i = 0; i < size; ++i) {  // for 循环控制该层结点的子节点入队
                TreeNode* node = nodes.front();
                nodes.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    nodes.push(node->left);  // 只添加结点到队列，元素访问由上一步执行
                }
                if (node->right != nullptr) {
                    nodes.push(node->right);  // 只添加结点到队列，元素访问由上一步执行
                }
            }
            res.push_back(sum / size);
        }
        return res;
    }
};
// @leet end
