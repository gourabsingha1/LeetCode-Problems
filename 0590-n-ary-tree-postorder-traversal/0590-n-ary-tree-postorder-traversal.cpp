class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        stack<Node*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            for (int i = 0; i < root->children.size(); i++)
            {
                st1.push(root->children[i]);
            }
        }
        while(!st2.empty()){
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};