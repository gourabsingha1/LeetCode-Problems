class Trie {
public:
    struct Node
    {
        Node* links[26];
        bool isEnd; // 1 if word exists, 0 if doesn't exist

        // checks if a node contains a character
        bool containsKey(char ch) {
            return links[ch - 'a'];
        }

        // puts a node
        void putKey(char ch, Node* newNode) {
            links[ch - 'a'] = newNode;
        }

        // next node
        Node* next(char ch) {
            return links[ch - 'a'];
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
        node->isEnd = 1;
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
        return node->isEnd;
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