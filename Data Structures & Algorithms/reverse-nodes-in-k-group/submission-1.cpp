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
    ListNode* getKthNode(ListNode* head, int k) {
        while(k > 0 && head)
        {
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev = dummy;
        while(true)
        {
            ListNode* kth = getKthNode(groupPrev, k);
            if(!kth)
                break;
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while(curr && curr != groupNext)
            {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
};
