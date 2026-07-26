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
        Node* cur = head;
        while(cur)
        {
            if(hashMap.find(cur) == hashMap.end())
                hashMap[cur] = new Node(cur->val);
            
            if(hashMap.find(cur->next) == hashMap.end())
                hashMap[cur->next] = new Node(cur->next->val);
            hashMap[cur]->next = hashMap[cur->next];
            
            if(hashMap.find(cur->random) == hashMap.end())
                hashMap[cur->random] = new Node(cur->random->val);
            hashMap[cur]->random = hashMap[cur->random];

            cur = cur->next;
        }
        return hashMap[head];
    }
};
