#include <bits/stdc++.h>

#include "include/node.h"
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
#if 1
    // 递归法
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        int max_depth = 0;
        for (size_t i = 0; i < root->children.size(); ++i) {
            // 如果这里是maxDepth(root->children[i])+1 则0 和 1直接就是1大
            // 因此不合理，需要把 +1 放到最后
            max_depth = max(max_depth, maxDepth(root->children[i]));
        }
        // 想一想只有一个根结点的情况
        // 就只会执行这一句，很合理
        return max_depth + 1;
    }
#else
    // 迭代法（层序遍历）
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        queue<Node*> nodes;
        nodes.push(root);
        int max_depth = 0;
        while (!nodes.empty()) {
            ++max_depth;  // 深度+1
            size_t size = nodes.size();
            for (size_t i = 0; i < size; ++i) {
                Node* node = nodes.front();
                nodes.pop();
                for (size_t j = 0; j < node->children.size(); ++j) {
                    if (node->children[j] != nullptr)
                        nodes.push(node->children[j]);
                }
            }
        }
        return max_depth;
    }
#endif
};
// @leet end
