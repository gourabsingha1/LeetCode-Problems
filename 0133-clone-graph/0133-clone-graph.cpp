class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
        if(!node) return NULL;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        vector<Node*> newNei;
        for(auto& nei : node->neighbors) {
            if(mp[nei]) {
                newNei.push_back(mp[nei]);
            }
            else {
                newNei.push_back(dfs(nei, mp));
            }
        }
        newNode->neighbors = newNei;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};