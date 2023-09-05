class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head, *newTemp = new Node(0);
        Node* newHead = newTemp;
        while(temp) {
            // hash original node with copy node
            mp[temp] = new Node(temp->val);
            // build copy node
            newTemp->next = mp[temp];
            newTemp = newTemp->next, temp = temp->next;
        }
        temp = head, newTemp = newHead->next;
        while(temp) {
            // build random pointer of copy node
            newTemp->random = mp[temp->random];
            newTemp = newTemp->next, temp = temp->next;
        }
        return newHead->next;
    }
};