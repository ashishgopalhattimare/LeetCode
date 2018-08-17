// https://leetcode.com/problems/top-k-frequent-words/description/

struct Node
{
    string word;
    int freq;
    
    bool operator<(const Node &temp) const
    {
	// if frequency is same, lexicologically smallest word first
        if(freq == temp.freq) {
            return word > temp.word;
        }
	// if frequency are not same, word with greater frequency first
        return freq < temp.freq;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> hash;
        Node temp;
        
        for(int i = 0; i < words.size(); i++) {
            if(hash.find(words[i]) == hash.end()) {
                hash[words[i]] = 1;
            }
            else {
                hash[words[i]]+= 1;
            }
        }
        
        priority_queue<Node>pq;
        
        for(auto itr = hash.begin(); itr != hash.end(); itr++) {
            pq.push(Node{itr->first, itr->second});
        }
        
        vector<string>v;
        while(k--) {
            temp = pq.top();
            pq.pop();
            
            v.push_back(temp.word);
        }
        
        return v;
    }
};
