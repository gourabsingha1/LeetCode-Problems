class Solution {
public:
    void levelorderTraversal(Node *root){
        if(!root){
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int t = q.size();
            Node* prev;
            for (int i = 0; i < t; i++) {
                Node* node = q.front();
                q.pop();
                if(i){
                    prev->next = node;
                }
                prev = node;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
        }
    }
    Node* connect(Node* root) {
        levelorderTraversal(root);
        return root;
    }
};