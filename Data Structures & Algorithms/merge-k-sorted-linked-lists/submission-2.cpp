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
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(0,nullptr);
        ListNode* temp = newHead;
        while(head1 && head2)
        {
            if(head1->val <= head2->val)
            {
                newHead->next = head1;
                head1 = head1->next;
            }
            else
            {
                newHead->next = head2;
                head2 = head2->next;
            }
            newHead = newHead->next;
        }
        if(head1)
            newHead->next = head1;
        if(head2)
            newHead->next = head2;
        return temp->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1)
            return nullptr;
        ListNode* dummy = new ListNode(0,lists[0]);
        while(lists.size() > 1)
        {
            vector<ListNode*> newList;
            for(int i=0;i<lists.size();i+=2)
            {
                ListNode* head1 = lists[i];
                ListNode* head2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                newList.push_back(mergeList(head1,head2));
            }
            lists = newList;
        }
        return lists[0];
    }
};
