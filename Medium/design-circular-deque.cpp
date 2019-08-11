// https://leetcode.com/problems/design-circular-deque/
// Medium

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    
    list<int>ll;
    int maxSize;
    
    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(ll.size() == maxSize){
            return false;
        }
        ll.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(ll.size() == maxSize){
            return false;
        }
        ll.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(ll.size() == 0) return false;
        ll.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(ll.size() == 0) return false;
        ll.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(ll.size()) return ll.front();
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(ll.size()) return ll.back();
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return ll.size() == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return ll.size() == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
