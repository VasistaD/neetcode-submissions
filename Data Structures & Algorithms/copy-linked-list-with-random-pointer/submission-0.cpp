/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashMap;
        if(!head)
            return nullptr;
        Node* temp = head;
        while(temp)
        {
            Node* newNode = new Node(temp->val);
            hashMap[temp] = newNode;
            temp = temp->next;
        }
        Node* newHead = hashMap[head];
        temp = head;
        while(temp)
        {
            newHead->next = hashMap[temp->next];
            newHead->random = hashMap[temp->random];
            temp = temp->next;
            newHead = newHead->next;
        }
        return hashMap[head];
    }
};
