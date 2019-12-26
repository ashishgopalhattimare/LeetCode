// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
// Medium

struct LinkedNode {
    int val, freq;
    LinkedNode *next;
    
    LinkedNode(int val, int freq) : val(val), freq(freq), next(NULL) {}
}*front, *rear, *curr;

void insertNode(int val, int freq) {
    LinkedNode *temp = new LinkedNode(val, freq);
    if(front == NULL) front = temp;
    else rear->next = temp;
    
    rear = temp;
}

void removeNode(LinkedNode *prev) {
    
    if(prev == NULL) { // remove the front node from the list
        curr = (front = front->next); // update front
    }
    else if(curr->next == NULL) { // remove the last node from the list
        curr = (prev->next = NULL);
    }
    else { // remove the mid node from the list
        prev->next = curr->next;
        curr = curr->next;
    }
    return;
}

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int value;
        front = rear = NULL;
        
        // Insert all the nodes in a linked list
        // and if any element not front
        // retun false
        
        int freq = 1, elem = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == elem) freq++;
            else {
                insertNode(elem, freq);
                elem = nums[i];
                freq = 1;
            }
        }
        insertNode(elem, freq);        

        LinkedNode *prev;
        while(front) {
            curr = front; prev = NULL;

            value = curr->val;

            // Run k times to make a set of 4 elements
            for(int i = 0; i < k; i++) {

                if(curr == NULL || value != curr->val)
                    return false;

                // printf("[%2d,%2d] ", curr->val, curr->freq);

                // take this and remove this from the list
                if(curr->freq == 1) removeNode(prev);
                else {
                    curr->freq = curr->freq - 1;
                    
                    prev = curr;
                    curr = curr->next;
                }
                value++;
            }
            // printf("\n");
        }

        return true;
    }
};