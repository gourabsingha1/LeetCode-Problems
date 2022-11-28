class Solution {
public:
    int maxDepth(Node* root) {
        int res = 0;
        if(!root){
            return res;
        }

        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                
                for (int j = 0; j < node->children.size(); j++)
                {
                    q.push(node->children[j]);
                }
            }
            res++;
        }
        return res;
    }
};
