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
    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(0,nullptr);
        ListNode* temp = newHead;
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
        
        return newHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        while(lists.size() > 1)
        {
            vector<ListNode*> curList;
            for(int i=0;i<lists.size();i+=2)
            {
                ListNode* head1 = lists[i];
                ListNode* head2 = (i+1) < lists.size() ? lists[i+1] : nullptr;
                ListNode* head = mergeLists(head1,head2);
                curList.push_back(head);
            }
            lists = curList;
        }
        if(lists.size() == 0)
            return nullptr;
        return lists[0];
    }
};
