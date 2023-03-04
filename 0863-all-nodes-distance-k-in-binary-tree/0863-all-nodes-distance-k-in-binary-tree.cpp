class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void createGraph(TreeNode* root){
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while(q.size()){
            auto [node, parent] = q.front();
            q.pop();
            if(parent != -1){
                adj[parent].push_back(node->val);
                adj[node->val].push_back(parent);
            }
            if(node->left) {
                q.push({node->left, node->val});
            }
            if(node->right) {
                q.push({node->right, node->val});
            }
        }   
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        createGraph(root);
        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(target->val);
        vis[target->val] = 1, k++;
        while(q.size() && k--) {
            int t = q.size();
            while(t--) {
                int u = q.front();
                q.pop();
                if(k == 0) {
                    res.push_back(u);
                }
                for(auto& v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return res;
    }
};