class Solution {
public:
    void dfs(vector<int>& res, Node* root) {
        if(!root) {
            return;
        }
        
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
        {
            dfs(res, root->children[i]);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(res, root);
        return res;
    }
};