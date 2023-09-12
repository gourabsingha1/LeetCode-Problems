class Trie {
public:
    struct Node
    {
        Node* links[26];
        bool flag = false;

        // checks if a node contains a character
        bool containsKey(char ch) {
            return links[ch - 'a'];
        }

        // puts a node
        void putKey(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        // next node
        Node* next(char ch) {
            return links[ch - 'a'];
        }

        // 1 = word exists, 0 = word doesn't exist
        void setEnd() {
            flag = 1;
        }

        // check if flag == 1
        bool isEnd() {
            return flag;
        }
    };
    
    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                node->putKey(ch, new Node());
            }
            // go to its reference node
            node = node->next(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            // go to its reference node
            node = node->next(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto& ch : prefix) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            // go to its reference node
            node = node->next(ch);
        }
        return 1;
    }
};