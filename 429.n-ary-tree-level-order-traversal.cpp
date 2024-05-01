#include <bits/stdc++.h>

#include "node.h"
using namespace std;

// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // N 叉树，子结点有多个
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            vector<int> vec;
            for (size_t i = 0; i < size; ++i) {
                Node* node = nodes.front();
                nodes.pop();
                vec.push_back(node->val);
                for (size_t j = 0; j < node->children.size(); ++j) {
                    // 判断子结点是否非空
                    // 貌似加这句能减少时间内存消耗
                    // 一定要判断非空吗？之前二叉树确实判断左右结点非空
                    // 的确需要，这就相当于判断是否存在子结点，
                    // 只有当子结点确实存在时，才需要添加进值序列
                    if (node->children[j] != nullptr)
                        nodes.push(node->children[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
// @leet end
