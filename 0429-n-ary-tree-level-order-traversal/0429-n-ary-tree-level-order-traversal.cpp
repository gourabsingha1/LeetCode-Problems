class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }

        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                
                for (auto &child : node->children)
                {
                    q.push(child);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};