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
    // 前序递归（因为要做回溯，路径是从父结点指向子结点）
    // NOTE: 递归函数参数和返回值
    // 根结点 + 记录每一条路径 path + 存放结果集 result
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        // NOTE: 递归终止条件和终止处理逻辑
        // 不同于以往判断 cur 非空，路径只需判断 cur 是否是叶子结点
        // 后面逻辑可以控制空结点不入循环
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            // 最后一个结点特殊处理
            for (int i = 0; i < path.size() - 1; ++i) {
                sPath += to_string(path[i]) + "->";
            }
            sPath += to_string(path.back());
            result.push_back(sPath);
            return;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {}
};
// @leet end
