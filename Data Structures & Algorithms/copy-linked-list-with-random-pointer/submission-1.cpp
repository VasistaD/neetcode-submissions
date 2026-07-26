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
        hashMap[nullptr] = nullptr;
        Node* temp = head;
        while(temp)
        {
            if(hashMap.find(temp) == hashMap.end())
                hashMap[temp] = new Node(0);
            hashMap[temp]->val = temp->val;

            if(hashMap.find(temp->next) == hashMap.end())
                hashMap[temp->next] = new Node(0);
            hashMap[temp]->next = hashMap[temp->next];
            
            if(hashMap.find(temp->random) == hashMap.end())
                hashMap[temp->random] = new Node(0);
            hashMap[temp]->random = hashMap[temp->random];

            temp = temp->next;
        }
        return hashMap[head];
    }
};
