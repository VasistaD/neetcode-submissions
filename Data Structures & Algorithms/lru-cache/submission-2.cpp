class Node {
public:
    int val,key;
    Node* prev;
    Node* next;

    Node(int k,int v) {
        val = v, key = k;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    int cap;
    Node* left;
    Node* right;

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }

    void insert(Node* node) {
        Node* pre = right->prev;
        pre->next = node;
        node->next = right;
        right->prev = node;
        node->prev = pre;
    }

    void remove(Node* node) {
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev=  pre;
    }

    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
        }
        Node* node = new Node(key,value);
        insert(node);
        cache[key] = node;
        if(cache.size() > cap)
        {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
