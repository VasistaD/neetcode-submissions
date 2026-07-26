class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k, value = v;
        prev = nullptr, next = nullptr;
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
        Node* p = right->prev;
        p->next = node;
        node->next = right;
        node->prev = p;
        right->prev = node;
    }

    void remove(Node* node) {
        Node* n = node->next;
        Node* p = node->prev;
        p->next = n;
        n->prev = p;
    }

    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
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
            delete(lru);
        }
    }
};
