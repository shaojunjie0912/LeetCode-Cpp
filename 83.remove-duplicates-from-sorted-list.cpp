#include <bits/stdc++.h>

#include "include/linked_list.h"
using namespace std;

// @leet start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 不加则无法断开后面重复的元素 [1,1,2,3,3,3]
        slow->next = nullptr;
        return head;
    }
};
// @leet end
