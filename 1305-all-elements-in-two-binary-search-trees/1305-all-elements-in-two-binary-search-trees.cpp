class Solution {
public:
    void Inorder(TreeNode *root, vector<int> &list){
        if(root == NULL){
            return;
        }
        Inorder(root->left, list);
        list.push_back(root->val);
        Inorder(root->right, list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res, list1, list2;
        Inorder(root1, list1), Inorder(root2, list2);
        int i = 0, j = 0;
        while(i < list1.size() && j < list2.size()){
            if(list1[i] < list2[j]){
                res.push_back(list1[i++]);
            }
            else{
                res.push_back(list2[j++]);
            }
        }
        while(i != list1.size()){
            res.push_back(list1[i++]);
        }
        while(j != list2.size()){
            res.push_back(list2[j++]);
        }
        return res;
    }
};