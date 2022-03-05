class MinStack {
public:
    struct Node{
        int val, mn;
        Node* next;
        Node(int _val, int _mn){
            val = _val;
            mn = _mn;
            next = NULL;
        }
    };
    
    Node* head=NULL;
    void push(int val) {
        if(!head){
            head = new Node(val, val);
        } 
        else{
            Node* temp = new Node(val, min(val, head->mn));
            temp->next=head;
            head=temp;
        }
    }
    
    void pop() {
        if(!head) return ;
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    
    int top() {
        if(!head) return -1;
        return head->val;
    }
    
    int getMin() {
        if(!head) return -1;
        return head->mn;
     //   https://leetcode.com/problems/min-stack/discuss/730013/3-approaches-(Two-stack-Only-One-Stack-and-linked-list)
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */