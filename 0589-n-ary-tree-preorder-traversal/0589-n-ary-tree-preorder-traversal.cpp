class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(st.size()) {
            Node* node = st.top();
            st.pop();
            if(!node) continue;
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                st.push(node->children[i]);
            }
        }
        return res;
    }
};