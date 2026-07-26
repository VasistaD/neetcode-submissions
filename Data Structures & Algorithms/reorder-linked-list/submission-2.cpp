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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* revtemp = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(revtemp)
        {
            ListNode* temp = revtemp->next;
            revtemp->next = prev;
            prev = revtemp;
            revtemp = temp;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second)
        {
            ListNode* f1 = first->next;
            ListNode* s1 = second->next;
            first->next = second;
            second->next = f1;
            first = f1;
            second = s1;
        }
        // return head;
    }
};
