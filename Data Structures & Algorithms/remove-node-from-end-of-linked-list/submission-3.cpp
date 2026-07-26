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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        while(n--)
            cur = cur->next;

        ListNode* prev = new ListNode(0,head);
        ListNode* newHead = prev;
        ListNode* temp = head;

        while(cur)
        {
            prev = temp;
            temp = temp->next;
            cur = cur->next;
        }

        prev->next = temp->next;

        return newHead->next;
    }
};
