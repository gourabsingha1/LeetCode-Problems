class Solution {
public:
    vector<int> res;
    int c = 0;
    vector<int> postorder(Node* root) {
        if(root == NULL){
            return res;
        }
        for (int i = 0 ; i < root->children.size(); i++)
        {
            c++;
            postorder(root->children[i]);
            res.push_back(root->children[i]->val);
        }
        if(c == res.size() && root) res.push_back(root->val);
        return res;
    }
};