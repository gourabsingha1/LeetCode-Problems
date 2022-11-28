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
                
                for (int j = 0; j < node->children.size(); j++)
                {
                    q.push(node->children[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};