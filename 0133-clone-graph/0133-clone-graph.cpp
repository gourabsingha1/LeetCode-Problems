class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
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
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        return mp[node];
    }
};