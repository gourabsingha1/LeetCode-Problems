class Solution {
public:
    vector<int> res;
    void Postorder(Node *root){
        if(root == NULL){
            return;
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            Postorder(root->children[i]);
            res.push_back(root->children[i]->val);
        }
    }
    vector<int> postorder(Node* root) {
        Postorder(root);
        if(root) res.push_back(root->val);
        return res;
    }
};