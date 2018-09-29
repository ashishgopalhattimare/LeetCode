// https://leetcode.com/problems/clone-graph/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    
    void traverse(UndirectedGraphNode *head, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hashMap)
    {
        if(head == NULL) return;
        
        hashMap[head] = new UndirectedGraphNode(head->label);
        
        for(int i = 0; i < head->neighbors.size(); i++) {
            if(hashMap.find(head->neighbors[i]) == hashMap.end()) {
                traverse(head->neighbors[i], hashMap);
            }
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>hashMap;
        
	// create a new node corresponding to every existing node in the tree
        traverse(node, hashMap);
        
        UndirectedGraphNode *mainNode, *tempNode;

	// connect corresponding nodes to each other as in the existing tree
        for(auto itr = hashMap.begin(); itr != hashMap.end(); itr++) {
            mainNode = itr->first;	// existing node
            tempNode = itr->second;	// replica node
            
            // Traverse the neigbouring nodes of each node
            for(int i = 0; i < mainNode->neighbors.size(); i++) {
		        
                // connect the corresponding nodes of each neighbouring node with the current node's replica
                (tempNode->neighbors).push_back(hashMap[mainNode->neighbors[i]]);
            }
        }
        
        // return the replica of the headNode
        return hashMap[node];
    }
};