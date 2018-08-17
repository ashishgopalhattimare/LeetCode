// https://leetcode.com/problems/linked-list-components/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        
        unordered_set<int>hash;
        
        for(int i = 0; i < G.size(); i++) {
            hash.insert(G[i]);
        }
        
        ListNode *ptr = head;
        int components = 0;
        int i, j;
        while(ptr) {
            
            // if the starting is the part of one component
            if(hash.find(ptr->val) != hash.end()) {
                components++;
                
                // check till where it is forming a part of component
                ptr = ptr->next;
                while(ptr && hash.find(ptr->val) != hash.end()) {
                    ptr = ptr->next;
                }
            }
            else {
                ptr = ptr->next;
            }
        }
        
        return components;
    }
};