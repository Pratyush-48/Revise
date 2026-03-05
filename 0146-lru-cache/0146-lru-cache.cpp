class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key,int value){
        this->val = value;
        this->key = key;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    int size;
    unordered_map<int,Node*>tracker;
    Node* head;
    Node* tail;
    void add_node(Node* temp){
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
    }
    void delete_node(Node* temp){
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
    }
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int val=-1;
        if(tracker.find(key)!=tracker.end()){
            Node* temp = tracker[key];
            val = temp->val;
            delete_node(temp);
            tracker.erase(key);
            add_node(temp);
            tracker[key]=temp;
        }
        return val;
    }
    
    void put(int key, int value) {
        if(tracker.find(key)!=tracker.end()){
            Node* temp = tracker[key];
            temp->val = value;
            delete_node(temp);
            tracker.erase(key);
            add_node(temp);
            tracker[key]=temp;
        }
        else{
            Node* temp = new Node(key,value);
            if(tracker.size()>=size){
                tracker.erase(tail->prev->key);
                delete_node(tail->prev);
                add_node(temp);
                tracker[key]=temp;
            }
            else{
                add_node(temp);
                tracker[key]=temp;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */