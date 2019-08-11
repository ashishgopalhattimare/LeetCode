// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Medium
// LinkedList : O(n^2)

struct DoublyList {
    int data;
    int lvalue;
    
    DoublyList *next, *prev;
    DoublyList(int d, int v) : data(d), lvalue(v) {
        next = prev = NULL;
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int totalSum = 0, minim, product;
        
        DoublyList *front = NULL, *rear;
        for(int x : arr) {
            
            DoublyList *newNode = new DoublyList(x, x);
            
            if(front == NULL) front = newNode;
            else {
                rear->next = newNode;
                newNode->prev = rear;
            }
            rear = newNode;
        }
        
        DoublyList *extract, *ptr;
        while(front && front->next) {
            
            // Find the minimum neighbor pair
            minim = INT_MAX;
            ptr = front;
            
            // Find the neighbour nodes with minimum product of lvalue's
            while(ptr && ptr->next) {
            	
                product = ptr->lvalue * (ptr->next)->lvalue;
            	if(minim > product) {
            		minim = product;
            		extract = ptr;
            	}
            	ptr = ptr->next;
            }
            
            DoublyList *newNode = new DoublyList(minim, max(extract->lvalue, extract->next->lvalue));
            totalSum += minim;
            
            newNode->next = extract->next->next;
            if(extract == front) {
                
                // If newNode->next exists
                if(newNode->next)
            	newNode->next->prev = newNode;
            	
                front = newNode;
            }
            else {
            	newNode->prev = extract->prev; // manage with the previous node (because next two nodes are being manipulated)
            	newNode->prev->next = newNode;
            	
                // If newNode->next exists
            	if(newNode->next)
            	newNode->next->prev = newNode;
            }
            
            // Delete the nodes from the memory
            delete extract->next;
            delete extract;
        }
        
        return totalSum;
    }
};
