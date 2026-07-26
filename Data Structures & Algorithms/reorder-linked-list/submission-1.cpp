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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = head;
        ListNode* revTemp = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(revTemp)
        {
            ListNode* t = revTemp->next;
            revTemp->next = prev;
            prev = revTemp;
            revTemp = t;
        }
        ListNode* first = head;
        ListNode* second = prev;
        while(second)
        {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
        // return head;
    }
};
