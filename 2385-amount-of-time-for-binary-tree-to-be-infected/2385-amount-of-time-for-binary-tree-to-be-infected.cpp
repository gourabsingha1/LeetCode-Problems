// convert tree to graph then simple bfs

class Solution {
public:
    // **** Tree to Graph ****
    unordered_map<int, vector<int>> adj;

    void treeToGraph(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            auto node = q.front();
            q.pop();
            if(node->left) {
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right) {
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }   
    }
    
    int amountOfTime(TreeNode* root, int start) {
        treeToGraph(root);
        unordered_map<int, bool> vis;
        int level = -1;
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(q.size()) {
            int size = q.size();
            while(size--) {
                int u = q.front();
                q.pop();
                for(auto& v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            level++;
        }
        return level;
    }
};