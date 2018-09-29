// https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    
    struct Node
    {
        int val;
        Node *next;
        
        Node(int v) : val(v), next(NULL) {}
    };
    
    Node *front, *rear;
    
    MyLinkedList() {
        front = rear = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        int currIndex = 0;
        Node *ptr = front;
        
        while(ptr) {
            if(currIndex == index) {
                return ptr->val;
            }
            ptr = ptr->next;
            currIndex++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *temp = new Node(val);
        
        if(front == NULL) {
            rear = temp;
        }
        temp->next = front;
        front = temp;
        
        // print();
    }
    
    void print() {
        // Node *ptr = front;
        // while(ptr) {
        //     printf("%d->", ptr->val);
        //     ptr = ptr->next;
        // }
        // printf("\n");
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp = new Node(val);
        
        if(front == NULL) {
            front = temp;
        }
        else {
            rear->next = temp;
        }
        rear = temp;
        
        // print();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(index == 0) {
            addAtHead(val);
        }
        else {
            Node *curr = front;
            
            if(curr == NULL) return;
            
            Node *temp = new Node(val);
            int currIndex = 1;
            bool added = false;
            
            while(curr->next) {
                if(currIndex == index) {
                    temp->next = curr->next;
                    curr->next = temp;
                    added = true;
                    
                    break;
                }
                curr = curr->next;
                currIndex++;
            }
            
            if(added == false && currIndex == index) {
                addAtTail(val);
            }
        }
        
        // print();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        Node *rem, *prev;
        Node *curr;    
        if(index == 0) {
            if(front) {
                front = (rem = front)->next;
                delete rem;
            }
        }
        else {
            curr = (prev = front)->next;
            
            int currIndex = 1;
            while(curr) {
                
                if(currIndex == index) {
                    rem = curr;
                    prev->next = curr->next;
                    
                    if(!curr->next) rear = prev;
                    
                    delete rem;
                    break;
                }
                
                curr = (prev = curr)->next;
                currIndex++;
            }
        }
        
        // print();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */s