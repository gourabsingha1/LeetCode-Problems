class BrowserHistory {
public:
    struct ListNode {
        ListNode* next, *prev;
        string val;
        ListNode (string x) : val(x), next(nullptr), prev(nullptr) {}
    };

    ListNode* head;
    int n = 1;

    BrowserHistory(string homepage) {
        ListNode* newNode = new ListNode(homepage);
        newNode->prev = NULL;
        head = newNode;
    }
    
    void visit(string url) {
        ListNode* newNode = new ListNode(url);
        newNode->prev = head;
        head->next = newNode;
        head = head->next;
        n++;
    }
    
    string back(int steps) {
        ListNode* temp = head;
        while(steps-- && temp->prev) {
            temp = temp->prev;
        }
        head = temp;
        return head->val;
    }
    
    string forward(int steps) {
        ListNode* temp = head;
        while(steps-- && temp->next) {
            temp = temp->next;
        }
        head = temp;
        return head->val;
    }
};