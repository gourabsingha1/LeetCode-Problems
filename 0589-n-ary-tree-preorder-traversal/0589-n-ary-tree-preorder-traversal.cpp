class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            res.push_back(root->val);
            for (int i = root->children.size()-1; i >= 0; i--)
            {
                st.push(root->children[i]);
            }
        }
        return res;
    }
};