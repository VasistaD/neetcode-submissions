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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        ListNode* newHead = new ListNode(0,lists[0]);
        for(int i=1;i<lists.size();i++)
        {
            ListNode* temp = newHead;
            ListNode* head1 = newHead->next;
            ListNode* head2 = lists[i];

            while(head1 && head2)
            {
                if(head1->val <= head2->val)
                {
                    temp->next = head1;
                    head1 = head1->next;
                }
                else
                {
                    temp->next = head2;
                    head2 = head2->next;
                }
                temp = temp->next;
            }
            if(head1)
                temp->next = head1;
            if(head2)
                temp->next = head2;
        }
        return newHead->next;

    }
};
