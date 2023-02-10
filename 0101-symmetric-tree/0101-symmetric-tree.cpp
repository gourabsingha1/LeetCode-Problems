class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int t = q.size();
            vector<int> temp;
            while(t--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                else{
                    temp.push_back(101);
                }
                if(node->right){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
                else{
                    temp.push_back(101);
                }
            }
            int n = temp.size();
            for (int i = 0; i < n / 2; i++)
            {
                if(temp[i] != temp[n - 1 - i]){
                    return 0;
                }
            }
        }
        return 1;
    }
};