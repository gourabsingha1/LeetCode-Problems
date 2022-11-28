class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!res.size() && root) res.push_back(root->val);
        if(!root){
            return res;
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            res.push_back(root->children[i]->val);
            preorder(root->children[i]);
        }
        return res;
    }
};