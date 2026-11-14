class LRUCache {

    struct Node{
        Node* next;
        Node* prev;
        int key;
        int value;
    };
    unordered_map<int,Node*> mappings;
    int cap;
    Node* head;
    Node* tail;


public:
    LRUCache(int capacity) {
        cap = capacity;
        tail = new Node();
        head = new Node();

        tail->next = head;
        head->next = nullptr;
        tail->prev = nullptr;
        head->prev = tail;
    }
    
    int get(int key) {
        if(mappings.contains(key)){
            int ret = mappings[key]->value;
            remove(mappings[key]);
            insert(mappings[key]);
            return ret;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* node = new Node();
        node->key = key;
        node->value = value;
        // if(tail->next == head){
        //     node->next = head;
        //     node->prev = tail;

        //     tail->next = node;
        //     head->prev = node;
        // }
        // else{
        //     head->prev->next = node;
        //     node->prev = head->prev;
        //     node->next = head;
        //     head->prev = node;
        // }

        insert(node);

        if(mappings.contains(key)){
            remove(mappings[key]);
        }

        else if(mappings.size()+1 > cap){
            int rem = tail->next->key;
            remove(tail->next);
            mappings.erase(rem);
        }
        
        mappings[key] = node;
        
    }


    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node){
        head->prev->next = node;
        node->prev = head->prev;
        node->next = head;
        head->prev = node;
    }
};
