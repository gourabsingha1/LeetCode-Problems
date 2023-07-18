// (0) <-> list <-> (0)

class LRUCache {
public:
    struct ListNode {
        ListNode* next, *prev;
        int val;
        ListNode(int v) {
            val = v, next = NULL, prev = NULL;
        }
    };

    int capacity;
    unordered_map<int, ListNode*> mp;
    unordered_map<ListNode*, int> reverseMp;
    ListNode* head, *tail;
    
    LRUCache(int capacity) {
        head = new ListNode(0), tail = new ListNode(0);
        head->next = tail, tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            updateNodeLRU(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        ListNode* newNode = new ListNode(value);
        reverseMp[newNode] = key;
        if(mp.find(key) != mp.end()) {
            mp[key]->val = value;
            updateNodeLRU(mp[key]);
        }
        else {
            if(mp.size() == capacity) {
                ListNode* LRU = tail->prev;
                mp.erase(reverseMp[LRU]); // here
                deleteNode(LRU);
            }
            mp[key] = newNode;
            setNodeLRU(newNode);
        }
    }

    // sets node to the head->next (MRU)
    void setNodeLRU(ListNode* node) {
        ListNode* headNext = head->next;
        head->next = node, node->prev = head;
        node->next = headNext, headNext->prev = node;
    }

    void deleteNode(ListNode* node) {
        node->prev->next = node->next, node->next->prev = node->prev;
    }

    void updateNodeLRU(ListNode* node) {
        deleteNode(node);
        setNodeLRU(node);
    }
    
    void print() {
        ListNode* temp = head;
        while(temp) {
            cout<<temp->val<<' ';
            temp = temp->next;
        }
        cout<<endl;
    }
};