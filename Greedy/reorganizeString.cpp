// https://leetcode.com/problems/reorganize-string/description/

struct Node
{
    char c;
    int f;
    Node(char C, int F) : c(C), f(F) {}
    bool operator <(const Node &temp) const
    {
        return f < temp.f;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        
        priority_queue<Node> pq;
        string result = "";
        
        int hasht[26];
        for(int i = 0; i < 26; i++) hasht[i] = 0;
        
        for(int i = 0; i < S.length(); i++) {
            hasht[S[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(hasht[i]) {
                pq.push(Node{'a'+i, hasht[i]});
            }
        }
        
        Node top{'#', -1};
        Node prev{'#', -1};
        
        while(!pq.empty()) {
            top = pq.top(); // get the most frequently used element currently
            pq.pop(); // pop it
            
            result = result + top.c; // append it to the result
            top.f--; // reduce its frequency
            
            if(prev.f > 0) { // if the prev pop element has freq left, push it back into the priority_queue
                pq.push(prev);
            }
            prev = top; // store this top element as prev 
        }
        
        if(result.length() == S.length()) {
            return result;
        }
        return "";
    }
};