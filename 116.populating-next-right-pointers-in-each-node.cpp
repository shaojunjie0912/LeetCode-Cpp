#include <bits/stdc++.h>

#include "include/perfect_node.h"
using namespace std;

// @leet start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // 下一个右侧结点指针
    // 需要用层序遍历思想
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        queue<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            size_t size = nodes.size();
            for (size_t i = 0; i < size; ++i) {
                Node* node = nodes.front();
                nodes.pop();
                if (i == size - 1)  // 特殊处理本层最后一个结点
                    node->next = nullptr;
                else
                    node->next = nodes.front();
                if (node->left != nullptr)
                    nodes.push(node->left);
                if (node->right != nullptr)
                    nodes.push(node->right);
            }
        }
        return root;
    }
};
// @leet end
