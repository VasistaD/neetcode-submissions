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
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(newHead)
        {
            ListNode * nxt = newHead->next;
            newHead->next = prev;
            prev = newHead;
            newHead = nxt;
        }
        ListNode* first = head;
        ListNode* last = prev;
        while(last)
        {
            ListNode* firstNxt = first->next;
            ListNode* lastNxt = last->next;
            first->next = last;
            last->next = firstNxt;
            first = firstNxt;
            last = lastNxt;
        }
    }
};
