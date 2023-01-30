// **** Design Linkedlist ****
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int n){
            val = n;
            next = NULL;
        }
    } *head, *last;
    int n = 0;
    
    int get(int index) {
        if(index >= n) return -1;
        ListNode* temp = head;
        while(index--) temp = temp->next;
        return temp->val;
    }

    // Add
    void addAtHead(int val) {
        n++;
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        if(n == 1) last = head;
    }
    void addAtTail(int val) {
        n++;
        ListNode* temp = new ListNode(val);
        if(n == 1){
            head = temp;
            last = head;
            return;
        }
        last->next = temp;
        last = temp;
    }
    void addAtIndex(int index, int val) {
        if(index > n) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        else if(index == n){
            addAtTail(val);
            return;
        }
        n++;
        ListNode* temp = head;
        ListNode* node = new ListNode(val);
        while(--index) temp = temp->next;
        node->next = temp->next;
        temp->next = node;
    }

    // Delete
    void deleteAtHead(ListNode *&head){
        if(!head) return;
        n--;
        ListNode* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    void deleteAtIndex(int index) {
        if(index >= n) return;
        if(index == 0){
            deleteAtHead(head);
            return;
        }
        n--;
        ListNode *temp = head, *toDelete;
        while(--index) temp = temp->next;
        if(temp->next && !temp->next->next) last = temp;
        toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Useful
    int size(){
        return n;
    }
    void display(ListNode *&head){
        ListNode *temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    bool search(ListNode *&head, int key){
        ListNode *temp = head;
        while(temp){
            if(temp->val == key) return 1;
            temp = temp->next;
        }
        return 0;
    }
    ListNode *reverse(ListNode *&head){
        ListNode *prevptr = NULL, *currptr = head;
        while(currptr){
            ListNode *nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
};