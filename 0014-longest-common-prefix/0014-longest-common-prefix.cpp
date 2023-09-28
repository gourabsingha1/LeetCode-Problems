// **** Trie - O(N), O(N) ****
class Solution {
public:
    struct Node
    {
        Node* links[26];
        bool isEnd; // 1 if word exists, 0 if doesn't exist
        int cntEndWith = 0; // count no. of words equal to word
        int cntPrefix = 0; // count no. of prefixes equal to word

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

    Solution() {
        root = new Node();
    }
    
    void insert(string& word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                node->putKey(ch, new Node());
            }
            // go to its reference node
            node = node->next(ch);
            node->cntPrefix++;
        }
        node->isEnd = 1;
        node->cntEndWith++;
    }
    
    bool search(string& word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->isEnd;
    }
    
    bool startsWith(string& prefix) {
        Node* node = root;
        for(auto& ch : prefix) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return 1;
    }

    int countWordsEqualTo(string& word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string& word) {
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->cntPrefix;
    }

    void erase(string& word) { // assuming word exists
        Node* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return;
            }
            node = node->next(ch);
            node->cntPrefix--;
        }
        node->cntEndWith--;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            insert(strs[i]);
        }
        Node* node = root;
        for(auto& ch : strs[0]) {
            if(node->containsKey(ch)) {
                node = node->next(ch);
            }

            if(node->cntPrefix == n) {
                res += ch;
            }
            else {
                break;
            }
        }
        return res;
    }
};