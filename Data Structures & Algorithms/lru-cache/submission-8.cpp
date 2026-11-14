class LRUCache {

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
};

int cap;
Node* head;
Node* tail;
unordered_map<int, Node*> mappings;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();
        head->prev = tail;
        tail->next = head;

        head->next = nullptr; tail->prev = nullptr;
    }
    
    int get(int key) {
        if(mappings.contains(key)){

            remove(mappings[key]);
            insert(mappings[key]);

            return mappings[key]->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        Node* node = new Node();
        node->key = key; node->value = value;

        insert(node);

        if(mappings.contains(key)){
            remove(mappings[key]);
        }
        else{
            if(mappings.size()+1 > cap){
                mappings.erase(tail->next->key);
                remove(tail->next);
            }
        }

        mappings[key] = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }
};
